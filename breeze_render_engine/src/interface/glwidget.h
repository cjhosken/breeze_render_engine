#ifndef GLWIDGET_H
#define GLWIDGET_H

#include "../common.h"
#include "../opengl/vertex.h"
#include "../opengl/shader.h"
#include "../opengl/viewportcamera.h"
#include "../opengl/world.h"
#include "../opengl/primitives.h"
#include "../opengl/canvas.h"
#include "../opengl/rendercamera.h"
#include "../opengl/texture.h"
#include "../opengl/light.h"

class GLWidget : public QOpenGLWidget, protected QOpenGLExtraFunctions {
	Q_OBJECT

public:
    GLWidget(QWidget* parent = nullptr) : QOpenGLWidget(parent) {
        setMouseTracking(true);
    }

    GLWidget() : QOpenGLWidget() {
        setMouseTracking(true);
    }

	~GLWidget() {}

    QSize minimumSizeHint() const override {
        return QSize(50, 50);
    };

    QSize sizeHint() const override {
        return QSize(settings.value("app/width").toFloat(), settings.value("app/height").toFloat());
    };

    void setFOV(float f) {
        fov = f;
        reproject(settings.value("app/width").toFloat(), settings.value("app/height").toFloat());
    }

    void render();

    void setSceneDrawType(DrawType t) {
        sceneDrawType = t;
    }

    void deselect() {
        world.deselectAll();

        selectID = 0;
        selectType = NONE;
    }

protected:
    unsigned int VAO;

    void setupVAOs() {
        glGenVertexArrays(1, &VAO);
        glBindVertexArray(VAO);

        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);
        glEnableVertexAttribArray(0);

        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, normal));
        glEnableVertexAttribArray(1);

        glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, uv));
        glEnableVertexAttribArray(2);
    }

    void initializeGL() override {
        makeCurrent();
        initializeOpenGLFunctions();
        setupVAOs();

        glViewport(0, 0, settings.value("app/width").toFloat(), settings.value("app/height").toFloat());

        reproject(settings.value("app/width").toFloat(), settings.value("app/height").toFloat());
       
        Texture matcap(":/assets/images/matcap.jpg");
        Texture light(":/assets/images/light.jpg");
        textures.push_back(matcap);
        textures.push_back(light);

        Shader defaultShader(":/assets/shaders/default.vert", ":/assets/shaders/default.frag");
        Shader wireShader(":/assets/shaders/default.vert", ":/assets/shaders/flat.frag");
        Shader IDShader(":/assets/shaders/default.vert", ":/assets/shaders/flat.frag");
        Shader lightShader(":/assets/shaders/default.vert", ":/assets/shaders/light.frag");
        Shader canvasShader(":/assets/shaders/canvas.vert", ":/assets/shaders/canvas.frag");

        shaders.push_back(defaultShader);
        shaders.push_back(wireShader);
        shaders.push_back(IDShader);
        shaders.push_back(lightShader);
        shaders.push_back(canvasShader);

        cvs.init();

        RenderCamera defaultCamera = RenderCamera("Camera");
        defaultCamera.location = QVector3D(0.0f, 0.0f, 3.0f);

        world.add(std::make_shared<RenderCamera>(defaultCamera));
        world.add(std::make_shared<Cube>("Cube"));
        
        glEnable(GL_DEPTH_TEST);
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

        RenderCamera* cam = world.getCamera(0);
        setSelected(cam);
    };
    
    void paintGL() override {
        glClearColor(0, 0, 0, 1);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glBindVertexArray(VAO);

        QMatrix4x4 view = viewCamera.getViewMatrix();

        // Default Shader
        shaders[0].use();
        shaders[0].setMat4("projection", projection);
        shaders[0].setMat4("view", view);

        // Wire Shader
        shaders[1].use();
        shaders[1].setMat4("projection", projection);
        shaders[1].setMat4("view", view);

        // ID Shader
        shaders[2].use();
        shaders[2].setMat4("projection", projection);
        shaders[2].setMat4("view", view);

        // Light Shader
        shaders[3].use();
        shaders[3].setMat4("projection", projection);
        shaders[3].setMat4("view", view);

        if (click && selecting) {
            for (int idx = 0; idx < world.size(); idx++) {
                if (idx < world.models.size()) {
                    world.getModel(idx)->draw(shaders.at(2), ID);
                }
                else if (idx < world.lights.size()) {
                    world.getLight(idx - world.models.size())->draw(shaders.at(2), ID);
                }
                else {
                    world.getCamera(idx - (world.models.size() + world.lights.size()))->draw(shaders.at(2), ID);
                }
            }

            glFlush();
            glFinish();

            glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
            unsigned char data[3];
            glReadPixels(lastX, settings.value("app/height").toFloat() - lastY, 1, 1, GL_RGB, GL_UNSIGNED_BYTE, data);

            int pickedID = data[0] + data[1] * 256 + data[2] * 256 * 256;

            if (pickedID != 0) {
                deselect();
                for (int idx = 0; idx < world.size(); idx++) {
                    if (idx < world.models.size()) {
                        if (world.getModel(idx)->id == pickedID) {
                            Model* model = world.getModel(idx);
                            setSelected(model);
                            break;
                        }
                    }
                    else if (idx < world.lights.size()) {
                        if (world.getLight(idx - world.models.size())->id == pickedID) {
                            Light* light = world.getLight(idx - world.models.size());
                            setSelected(light);
                            break;
                        }
                    }
                    else {
                        if (world.getCamera(idx - (world.models.size() + world.lights.size()))->id == pickedID) {
                            RenderCamera* camera = world.getCamera(idx - (world.models.size() + world.lights.size()));
                            setSelected(camera);
                            break;
                        }
                    }
                }
            }

            glClearColor(0, 0, 0, 1);
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);            
        }

        cvs.draw(shaders.at(4));

        glClear(GL_DEPTH_BUFFER_BIT);

        for (int idx = 0; idx < world.size(); idx++) {
            if (idx < world.models.size()) {
                if (world.models.size() > 0) {
                    glActiveTexture(GL_TEXTURE0);
                    glBindTexture(GL_TEXTURE_2D, textures[0].TXO);
                    shaders[0].setInt("matcap", 0);

                    Model* model = world.getModel(idx);

                    model->draw(shaders.at(0), sceneDrawType);

                    if (model->selected) {
                        model->draw(shaders.at(1), WIRE);
                    }
                }
            }
            else if (idx < world.lights.size()) {
                if (world.lights.size() > 0) {
                    shaders[3].use();
                    glActiveTexture(GL_TEXTURE0);
                    glBindTexture(GL_TEXTURE_2D, textures[1].TXO);
                    shaders[3].setInt("light", 0);

                    Light* light = world.getLight(idx - world.models.size());
                    light->draw(shaders.at(3), DEFAULT);
                }
            }
            else {
                if (world.cameras.size() > 0) {
                    RenderCamera* camera = world.getCamera(idx - (world.models.size() + world.lights.size()));
                    camera->draw(shaders.at(1), WIRE);
                }
            }
        }

        glBindTexture(GL_TEXTURE_2D, 0);
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

        if (click && selecting) {
            click = false;
        }
    };

    void resizeGL(int width, int height) override {
        glViewport(0, 0, width, height);
        reproject(float(width), float(height));
    };

    void mousePressEvent(QMouseEvent* ev) override {
        if (ev->buttons() == Qt::LeftButton) {
            click = true;
        }
        else {
            click = false;
        }
        repaint();
    };

    void mouseMoveEvent(QMouseEvent* ev) override {
        float xPos = static_cast<float>(ev->pos().x());
        float yPos = static_cast<float>(ev->pos().y());

        if (firstMouse)
        {
            lastX = xPos;
            lastY = yPos;
            firstMouse = false;
        }

        float xOffset = xPos - lastX;
        float yOffset = lastY - yPos;

        lastX = xPos;
        lastY = yPos;

        if (ev->buttons() == Qt::LeftButton) {
            click = false;
                viewCamera.processMouseMovement(xOffset, yOffset);
        }

        click = false;

        repaint();
    };

    void wheelEvent(QWheelEvent* ev) {
        viewCamera.processMouseScroll(ev->angleDelta().y());
        repaint();
    }

    void setSelected(Model* &m) {
        m->selected = true;
        selectID = m->id;
        selectType = MODEL;

        emit updateSelection();
    }

    void setSelected(Light* &l) {
        l->selected = true;
        selectID = l->id;
        selectType = LIGHT;
        
        emit updateSelection();
    }

    void setSelected(RenderCamera* &c) {
        c->selected = true;
        selectID = c->id;
        selectType = CAMERA;

        emit updateSelection();
    }

signals:
    void updateSelection();

private:
    void reproject(float w, float h) {
        projection.setToIdentity();
        projection.perspective(fov, w / h, clipNear, clipFar);
    }

    QSettings settings;
    QMatrix4x4 projection = QMatrix4x4();

    float lastX = settings.value("app/width").toFloat() / 2.0f;
    float lastY = settings.value("app/height").toFloat() / 2.0f;

    bool firstMouse = true;
    bool click = false;

    std::vector<Shader> shaders;
    std::vector<Texture> textures;

    DrawType sceneDrawType = DEFAULT;

    float fov = 35.0f;
    float clipNear = 0.01f;
    float clipFar = 100.0f;

public:
    ViewportCamera viewCamera = ViewportCamera();
    World world = World();
    Canvas cvs = Canvas();

    unsigned selectID;
    ObjectType selectType;

    bool selecting = true;
    bool rendering = false;
};

#endif // !GLWIDGET_H
