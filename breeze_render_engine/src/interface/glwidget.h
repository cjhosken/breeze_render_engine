#ifndef GLWIDGET_H
#define GLWIDGET_H

#include "../common.h"
#include "../opengl/shader.h"
#include "../opengl/viewportcamera.h"
#include "../opengl/world.h"
#include "../opengl/primitives.h"
#include "../opengl/canvas.h"
#include "../opengl/rendercamera.h"
#include "../opengl/texture.h"
#include "../interface/applicationsettings.h"

class GLWidget : public QOpenGLWidget, protected QOpenGLFunctions_4_5_Core {
	Q_OBJECT

public:
    GLWidget(QWidget* parent = nullptr) : QOpenGLWidget(parent) {
        setMouseTracking(true);
        settings = ApplicationSettings();
    }

    GLWidget(ApplicationSettings &set) : QOpenGLWidget() {
        setMouseTracking(true);
        settings = set;
    }

	~GLWidget() {}

    QSize minimumSizeHint() const override {
        return QSize(50, 50);
    };

    QSize sizeHint() const override {
        return QSize(settings.APP_WIDTH, settings.APP_HEIGHT);
    };

    void render();

    void setSceneDrawType(DrawType t) {
        sceneDrawType = t;
    }

    void addCube() {
        world.add(std::make_shared<Cube>("cube"));
    }

    void addPlane() {
        world.add(std::make_shared<Plane>("plane"));
    }

    void addSphere() {
        world.add(std::make_shared<Sphere>("sphere"));
    }

    void addOBJ(std::string path) {
        world.add(std::make_shared<OBJModel>(path, "obj"));
    }

    void addTriangle() {
        world.add(std::make_shared<Triangle>("triangle"));
    }

    void addCircle() {
        world.add(std::make_shared<Circle>("circle"));
    }

    void addCylinder() {
        world.add(std::make_shared<Cylinder>("cylinder"));
    }

    void addMonkey() {
        world.add(std::make_shared<OBJModel>("assets/models/suzanne.obj", "monkey"));
    }

    void addTeapot() {
        world.add(std::make_shared<OBJModel>("assets/models/teapot.obj", "teapot"));
    }

protected:

    void initializeGL() override {
        initializeOpenGLFunctions();

        glViewport(0, 0, settings.APP_WIDTH, settings.APP_HEIGHT);

        projection.setToIdentity();
        projection.perspective(35, float(settings.APP_WIDTH) / float(settings.APP_HEIGHT), 0.01f, 100.0f);
       
        Texture matcap("assets/images/matcap.jpg", false);
        Texture light("assets/images/light.jpg", false);
        textures.push_back(matcap);
        textures.push_back(light);

        Shader defaultShader("assets/shaders/default.vert", "assets/shaders/default.frag");
        Shader wireShader("assets/shaders/default.vert", "assets/shaders/flat.frag");
        Shader IDShader("assets/shaders/default.vert", "assets/shaders/flat.frag");
        Shader lightShader("assets/shaders/default.vert", "assets/shaders/light.frag");
        Shader canvasShader("assets/shaders/canvas.vert", "assets/shaders/canvas.frag");

        shaders.push_back(defaultShader);
        shaders.push_back(wireShader);
        shaders.push_back(IDShader);
        shaders.push_back(lightShader);
        shaders.push_back(canvasShader);

        cvs.init();

        renderCamera.init();
        renderCamera.location = QVector3D(0.0f, 0.0f, 3.0f);

        world.add(std::make_shared<Light>("Light"));

        /*
        world.add(std::make_shared<Plane>("ground"));
        world.get("ground")->scale = QVector3D(10, 10, 10);
        
        world.add(std::make_shared<Cube>("cube"));
        world.get("cube")->location = QVector3D(-3.0f, 1, 0.0f);

        world.add(std::make_shared<Sphere>("sphere"));
        world.get("sphere")->scale = QVector3D(2, 2, 2);
        world.get("sphere")->location = QVector3D(1.0f, 1.5f, 2.0f);

        world.add(std::make_shared<OBJModel>("assets/models/teapot.obj", "monke"));
        world.get("monke")->location = QVector3D(0.0f, 2.0f, -3.0f);
        */


        glEnable(GL_DEPTH_TEST);
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    };
   

    
    void paintGL() override {
        glClearColor(0, 0, 0, 1);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

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

        cvs.draw(shaders.at(4));

        glClear(GL_DEPTH_BUFFER_BIT);

        renderCamera.draw(shaders.at(1), WIRE, settings);


        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, textures[0].TXO);
        shaders[0].setInt("matcap", 0);

        for (int mdx = 0; mdx < world.scene.size(); mdx++) {
            world.get(mdx)->draw(shaders.at(0), DEFAULT, settings);

            if (world.scene[mdx]->type == SOLID) {
                world.get(mdx)->draw(shaders.at(0), DEFAULT, settings);

            }
            else if (world.scene[mdx]->type == WIREFRAME) {
                world.get(mdx)->draw(shaders.at(1), WIRE, settings);
            }

            if (world.get(mdx)->selected) {
                world.get(mdx)->draw(shaders.at(1), WIRE, settings);
            }
        }

        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, textures[1].TXO);
        shaders[3].setInt("light", 0);

        for (int ldx = 0; ldx < world.lights.size(); ldx++) {
            world.getLight(ldx)->draw(shaders.at(3), DEFAULT, settings);
        }

        glBindTexture(GL_TEXTURE_2D, 0);
    };

    void resizeGL(int width, int height) override {
        glViewport(0, 0, width, height);
        projection.setToIdentity();
        projection.perspective(35, float(width) / float(height), 0.01f, 100.0f);
    };

    void mousePressEvent(QMouseEvent* ev) override {
        if (ev->buttons() == Qt::LeftButton) {
            click = true;
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

        repaint();
    };

    void wheelEvent(QWheelEvent* ev) {
        viewCamera.processMouseScroll(ev->angleDelta().y());
        repaint();
    }

private:
    ApplicationSettings settings;

    QMatrix4x4 projection = QMatrix4x4();

    float lastX = settings.APP_WIDTH / 2.0f;
    float lastY = settings.APP_HEIGHT / 2.0f;

    float pixelScreenHeight = settings.APP_HEIGHT;

    bool firstMouse = true;
    bool click = false;
    bool rendering = false;

    std::vector<Shader> shaders;
    std::vector<Texture> textures;

    DrawType sceneDrawType;

public:
    ViewportCamera viewCamera = ViewportCamera();
    RenderCamera renderCamera = RenderCamera();
    World world = World();
    Canvas cvs = Canvas();
    bool selecting;

};

#endif // !GLWIDGET_H
