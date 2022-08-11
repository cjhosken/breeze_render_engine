#ifndef WORLD_H
#define WORLD_H

#include "../common.h"
#include "model.h"
#include "ray.h"
#include "rendercamera.h"

struct HitData {
	float t;
	QVector3D normal;
	Model* model;
};

class World {
public:
    std::vector<std::shared_ptr<RenderCamera>> cameras;
    std::vector<std::shared_ptr<Model>> models;

    void add(std::shared_ptr<Model> m) {
        models.push_back(m);
    }

    void add(std::shared_ptr<RenderCamera> c) {
        cameras.push_back(c);
    }

    unsigned int idAt(unsigned int id) {
        for (unsigned int idx = 0; idx < models.size() + cameras.size(); idx++) {
            if (idx < models.size()) {
                if (models.at(idx).get()->id == id) {
                    return idx;
                }
            }
            else {
                if (cameras.at(idx - models.size()).get()->id == id) {
                    return idx;
                }
            }
        }
        return -1;
    }

    void removeWithID(unsigned int id) {
        for (unsigned int idx = 0; idx < models.size() + cameras.size(); idx++) {
            if (idx < models.size()) {
                if (models.at(idx).get()->id == id) {
                    models.erase(models.begin() + idx);
                }
            }
            else {
                if (cameras.at(idx - models.size()).get()->id == id) {
                    cameras.erase(cameras.begin() + (idx - models.size()));
                }
            }
        }
    }

    int size() {
        return models.size() + cameras.size();
    }

    void deselectAll() {
        for (unsigned int idx = 0; idx < models.size() + cameras.size(); idx++) {
            if (idx < models.size()) {
                models.at(idx).get()->selected = false;
            }
            else {
                cameras.at(idx - models.size()).get()->selected = false;
            }
        }
    }

    Model* getModel(unsigned int idx) {
        return models.at(idx).get();
    }

    Model* getModelFromID(unsigned int id) {
        for (unsigned int idx = 0; idx < models.size(); idx++) {
            if (models.at(idx).get()->id == id) {
                Model* model = models.at(idx).get();
                return model;
            }
        }
    }

    RenderCamera* getCamera(unsigned int idx) {
        return cameras.at(idx).get();
    }

    RenderCamera* getCameraFromID(unsigned int id) {
        for (unsigned int idx = 0; idx < cameras.size(); idx++) {
            if (cameras.at(idx).get()->id == id) {
                RenderCamera* camera = cameras.at(idx).get();
                return camera;
            }
        }
    }

    HitData hit(Ray r, QMatrix4x4 view) {
        HitData out = { INFINITY, QVector3D(0.0f, 0.0f, 0.0f), nullptr };

        for (unsigned int mdx = 0; mdx < models.size(); mdx++) {
            Model* model = models.at(mdx).get();
            Mesh mesh = model->mesh;

            std::vector<Vertex> data = mesh.data;

            for (int vdx = 0; vdx < data.size(); vdx += 3) {
                Vertex a = data[vdx];
                Vertex b = data[vdx + 1];
                Vertex c = data[vdx + 2];

                QVector3D A = QVector3D(QVector4D(a.position, 1.0f) * (model->getModelMatrix()));
                QVector3D B = QVector3D(QVector4D(b.position, 1.0f) * (model->getModelMatrix()));
                QVector3D C = QVector3D(QVector4D(c.position, 1.0f) * (model->getModelMatrix()));

                QVector3D AB = B - A;
                QVector3D BC = B - C;
                QVector3D AC = C - A;
                QVector3D P = QVector3D().crossProduct(r.direction(), AC);
                double det = QVector3D().dotProduct(AB, P);

                if (abs(det) < 0.0000001) continue;

                double invDet = 1 / det;

                QVector3D tuv = r.origin() - A;
                double u = QVector3D().dotProduct(tuv, P) * invDet;
                if (u < 0 || u > 1) continue;

                QVector3D q = QVector3D().crossProduct(tuv, AB);
                double v = QVector3D().dotProduct(r.direction(), q) * invDet;
                if (v < 0 || u + v > 1) continue;

                float t = QVector3D().dotProduct(AC, q) * invDet;

                if (t > 0.0001f && t < out.t) {
                    QVector3D normal = QVector3D().crossProduct(BC, AC).normalized();

                    if (QVector3D().dotProduct(normal, r.direction()) > 0) {
                        normal = (normal * -1.0f);
                    }

                    out = { t, normal, model };
                }
            };
        }

        return out;
    };
};

#endif // !WORLD_H