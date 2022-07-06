#ifndef GLWIDGET_H
#define GLWIDGET_H

#include "../common.h"
#include "shader.h"
#include "viewportcamera.h"
#include "world.h"
#include "primitives.h"
#include "canvas.h"
#include "rendercamera.h"
#include "texture.h"

#include <QOpenGLFrameBufferObject>

class GLWidget : public QOpenGLWidget, protected QOpenGLFunctions_4_5_Core {
	Q_OBJECT

public:
    GLWidget(QWidget* parent = nullptr) : QOpenGLWidget(parent) {
        setMouseTracking(true);

    }
	~GLWidget() {}

    QSize minimumSizeHint() const override {
        return QSize(50, 50);
    };
    QSize sizeHint() const override {
        return QSize(APP_WIDTH, APP_HEIGHT);
    };

    void render();

protected:

    void initializeGL() override {
        initializeOpenGLFunctions();

        glViewport(0, 0, APP_WIDTH, APP_HEIGHT);

        projection.setToIdentity();
        projection.perspective(35, float(APP_WIDTH) / float(APP_HEIGHT), 0.01f, 100.0f);
       
        Texture matcap("assets/images/matcap.jpg");
        textures.push_back(matcap);

        Shader defaultShader("assets/shaders/default.vert", "assets/shaders/default.frag");
        Shader wireShader("assets/shaders/default.vert", "assets/shaders/flat.frag");
        Shader IDShader("assets/shaders/default.vert", "assets/shaders/flat.frag");
        Shader canvasShader("assets/shaders/canvas.vert", "assets/shaders/canvas.frag");

        shaders.push_back(defaultShader);
        shaders.push_back(wireShader);
        shaders.push_back(IDShader);
        shaders.push_back(canvasShader);

        cvs.init();

        renderCamera.init();
        renderCamera.location = QVector3D(0.0f, 0.0f, 3.0f);

        world.add(std::make_shared<Sphere>("coob"));


        glEnable(GL_DEPTH_TEST);
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

        cvs.draw(shaders.at(3));

        glClear(GL_DEPTH_BUFFER_BIT);

        renderCamera.draw(shaders.at(1), WIRE);


        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, textures[0].TXO);
        shaders[0].setInt("matcap", 0);

        for (int mdx = 0; mdx < world.scene.size(); mdx++) {
            world.get(mdx)->draw(shaders.at(0), DEFAULT);

            if (world.scene[mdx]->type == SOLID) {
                world.get(mdx)->draw(shaders.at(0), DEFAULT);

            }
            else if (world.scene[mdx]->type == WIREFRAME) {
                world.get(mdx)->draw(shaders.at(1), WIRE);
            }

            if (world.get(mdx)->selected) {
                world.get(mdx)->draw(shaders.at(1), WIRE);
            }
        }
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
    World world = World();
    Canvas cvs = Canvas();

    QMatrix4x4 projection = QMatrix4x4();

    ViewportCamera viewCamera = ViewportCamera();
    RenderCamera renderCamera = RenderCamera();

    float lastX = APP_WIDTH / 2.0f;
    float lastY = APP_HEIGHT / 2.0f;

    float pixelScreenHeight = APP_HEIGHT;

    bool firstMouse = true;
    bool click = false;
    bool rendering = false;

    std::vector<Shader> shaders;
    std::vector<Texture> textures;
};

#endif // !GLWIDGET_H
