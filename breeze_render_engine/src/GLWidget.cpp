#include "glwidget.h"

//#define STB_IMAGE_WRITE_STATIC
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include <stb/stb_image_write.h>

QVector3D ray_color(Ray r, World world, int depth) {
    if (depth < 1) {
        return QVector3D(0.0f, 0.0f, 0.0f);
    }
    
    HitData ht = world.hit(r);

    if (ht.t > 0.00001f) {
        QVector3D target = ht.normal + randomInUnitSphere();
        return 0.5f * ray_color(Ray(r.at(ht.t), target), world, depth - 1);
    }

    QVector3D unit_direction = r.direction().normalized();
    float t = 0.5f * (unit_direction.y() + 1.0f);
    return (1.0f - t) * QVector3D(1.0f, 1.0f, 1.0f) + t * QVector3D(0.5, 0.7, 1.0);
}


void GLWidget::render() {
    if (!rendering) {
        rendering = true;
        const int width = 160;
        const int height = 90;
        const int channels = 3;
        const int samples = 4;
        const int depth = 2;

        unsigned char data[width * height * channels];

        int index = 0;

        renderCamera.setupForRender();

        for (int y = height - 1; y >= 0; y--) {
            qDebug() << "Line: " << y;
            for (int x = 0; x < width; x++) {
                QVector3D pixel_color(0.0f, 0.0f, 0.0f);
                for (int s = 0; s < samples; s++) {
                    float i = (float(x) + random_float()) / float(width - 1);
                    float j = (float(y) + random_float()) / float(height - 1);

                    Ray r = renderCamera.get_ray(i, j);
                    pixel_color += ray_color(r, world, depth);
                }

                pixel_color /= samples;

                data[index++] = (unsigned char)(255.0 * pixel_color.x());
                data[index++] = (unsigned char)(255.0 * pixel_color.y());
                data[index++] = (unsigned char)(255.0 * pixel_color.z());
            }
        }

        stbi_write_png("render.png", width, height, channels, data, width * channels);

        rendering = false;
    }
}
