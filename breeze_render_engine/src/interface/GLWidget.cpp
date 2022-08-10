#include "glwidget.h"

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include <stb/stb_image_write.h>

#include <QProgressBar>
#include "widgets/qrenderpopup.h"

QVector3D reflect(const QVector3D v, const QVector3D n) {
    return v - 2 * QVector3D().dotProduct(v, n) * n;
}

QColor ray_color(Ray r, World world, QMatrix4x4 view, int depth) {

    if (depth <= 0) {
        return QColor(0.0f, 0.0f, 0.0f);
    }

    HitData ht = world.hit(r, view);

    if (ht.model != nullptr) {
            float ro = ht.model->material.roughness;

            QVector3D reflected = reflect(r.direction().normalized(), ht.normal);
            Ray scattered = Ray(r.at(ht.t), ht.normal + randomInUnitSphere());

            QColor out = QColor(
                ht.model->material.color.red() * ray_color(scattered, world, view, depth - 1).red(),
                ht.model->material.color.green() * ray_color(scattered, world, view, depth - 1).green(),
                ht.model->material.color.blue() * ray_color(scattered, world, view, depth - 1).blue()
            );

            return out;
    }

    QVector3D unit_direction = r.direction().normalized();
    float t = 0.5f * (unit_direction.y() + 1.0f);

    QColor b0(255.0f, 255.0f, 255.0f);

    QColor b1(127.5f, 178.5f, 255.0f);

    QColor out = QColor(
        (1 - t) * b0.red() + t * b1.red(),
        (1 - t) * b0.green() + t * b1.green(),
        (1 - t) * b0.blue() + t * b1.blue()
    );

    return out;
}

void GLWidget::render() {
    
    if (!rendering && world.cameras.size() > 0) {
        RenderCamera* camera = world.getCamera(0);

        const int width = camera->width;
        const int height = camera->height;
        const int channels = camera->channels;
        const int samples = camera->samples;
        const int depth = camera->bounces;

        unsigned char* data = new unsigned char[width * height * channels];

        World tmpWorld = world;
       
        rendering = true;
        camera->setupForRender();

        int max = width * height;

        QRenderPopup* progressPopup = new QRenderPopup(max);

        int index = 0;

        for (int y = height - 1; y >= 0; y--) {
            for (int x = 0; x < width; x++) {
                QCoreApplication::processEvents();
                int pct = x + ((height - 1) - y) * width;
                progressPopup->setValue(pct);

                QColor pixel_color(0.0f, 0.0f, 0.0f);

                for (int s = 0; s < samples; s++) {
                    float i = (float(x) + random_float()) / float(width - 1);
                    float j = (float(y) + random_float()) / float(height - 1);

                    Ray r = camera->get_ray(i, j);
                    pixel_color.setRedF(pixel_color.red() + ray_color(r, tmpWorld, camera->getViewMatrix(), depth).red());
                    pixel_color.setGreenF(pixel_color.green() + ray_color(r, tmpWorld, camera->getViewMatrix(), depth).green());
                    pixel_color.setBlueF(pixel_color.blue() + ray_color(r, tmpWorld, camera->getViewMatrix(), depth).blue());
                }

                pixel_color.setRedF(pixel_color.red() / samples);
                pixel_color.setGreenF(pixel_color.green() / samples);
                pixel_color.setBlueF(pixel_color.blue() / samples);


                data[index++] = (unsigned char)(pixel_color.red());
                data[index++] = (unsigned char)(pixel_color.green());
                data[index++] = (unsigned char)(pixel_color.blue());
            }
        }

        stbi_write_png("render.png", width, height, channels, data, width * channels);

        rendering = false;

        progressPopup->close();
    }
}
