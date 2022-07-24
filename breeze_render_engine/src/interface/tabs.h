#ifndef TABS_H
#define TABS_H

#include "../common.h"
#include "fields.h"

class RenderTab : public QTabWidget {
public:
    IntegerField* widthInput;
    IntegerField* heightInput;

    IntegerField* samplesInput;
    IntegerField* bouncesInput;

    QPushButton* renderButton;

    RenderTab(QWidget* parent = nullptr) : QTabWidget(parent) {
        QSettings settings;
        setAutoFillBackground(true);
        /*
            width:  ( i )
            height: ( i )
            samples: ( i )
            bounces: ( i )
            
            [ render ] 

        */
        QGroupBox* dims = new QGroupBox("Dimensions");
        dims->setProperty("class", "group");
        dims->setStyleSheet(settings.value("styles/root").toString());
        widthInput = new IntegerField("Width:", 1, 2147483647, 640);

        heightInput = new IntegerField("Height:", 1, 2147483647, 480);

        QVBoxLayout* dimsVBox = new QVBoxLayout;
        dimsVBox->addWidget(widthInput);
        dimsVBox->addWidget(heightInput);
        dims->setLayout(dimsVBox);


        QGroupBox* rays = new QGroupBox("Rays");
        rays->setProperty("class", "group");
        rays->setStyleSheet(settings.value("styles/root").toString());

        samplesInput = new IntegerField("Samples:", 1, 2147483647, 16);

        bouncesInput = new IntegerField("Bounces:", 1, 2147483647, 4);

        QVBoxLayout* raysVBox = new QVBoxLayout;
        raysVBox->addWidget(samplesInput);
        raysVBox->addWidget(bouncesInput);
        rays->setLayout(raysVBox);

        renderButton = new QPushButton("Render");
        renderButton->setProperty("class", "wireButton");
        renderButton->setStyleSheet(settings.value("styles/root").toString());

        QVBoxLayout* vbox = new QVBoxLayout();
        vbox->addWidget(dims);
        vbox->addWidget(rays);

        vbox->addWidget(renderButton);

        vbox->addStretch();

        setLayout(vbox);
    }
};

class WorldTab : public QTabWidget {
public:
    SliderField* fov;
    ColorField* gradIn;
    ColorField* gradOut;
    
    WorldTab(QWidget* parent = nullptr) : QTabWidget(parent) {
        QSettings settings;
        setAutoFillBackground(true);

        QGroupBox* view = new QGroupBox("Viewport Controls");
        view->setProperty("class", "group");
        view->setStyleSheet(settings.value("styles/root").toString());
        fov = new SliderField("FOV:", 1, 180, 35);

        QVBoxLayout* viewVBox = new QVBoxLayout;
        viewVBox->addWidget(fov);
        view->setLayout(viewVBox);

        QGroupBox* back = new QGroupBox("Viewport Background");
        back->setProperty("class", "group");
        back->setStyleSheet(settings.value("styles/root").toString());
        gradIn = new ColorField("Inner Gradient:");
        gradOut = new ColorField("Outer Gradient:");

        QVBoxLayout* backVBox = new QVBoxLayout;
        backVBox->addWidget(gradIn);
        backVBox->addWidget(gradOut);

        back->setLayout(backVBox);

        QVBoxLayout* vbox = new QVBoxLayout();
        vbox->addWidget(view);
        vbox->addWidget(back);
        vbox->addStretch();

        setLayout(vbox);
    }
};

class ObjectTab : public QTabWidget {
public:
    QLineEdit* name;

    QGroupBox* transform;
    QVector3DField* loc;
    QVector3DField* rot;
    QVector3DField* sca;

    QGroupBox* material;
    ColorField* color;
    SliderField* rough;
    SliderField* spec;

    QGroupBox* camera;
    SliderField* fov;
    BoolField* dof;
    FloatField* aperture;
    FloatField* distance;

    QVBoxLayout* vbox;
    

    ObjectTab(QWidget* parent = nullptr) : QTabWidget(parent) {
        QSettings settings;

        name = new QLineEdit();
        name->setProperty("class", "transparentTextInput");
        name->setStyleSheet(settings.value("styles/root").toString());

        transform = new QGroupBox("Transforms");
        transform->setProperty("class", "group");
        transform->setStyleSheet(settings.value("styles/root").toString());

        loc = new QVector3DField("Loc:", -INFINITY, INFINITY, 0);
        rot = new QVector3DField("Rot:", -INFINITY, INFINITY, 0);
        sca = new QVector3DField("Scale:", -INFINITY, INFINITY, 0);

        QVBoxLayout* transVBox = new QVBoxLayout;
        transVBox->addWidget(loc);
        transVBox->addWidget(rot);
        transVBox->addWidget(sca);

        transform->setLayout(transVBox);


        material = new QGroupBox("Material");
        material->setProperty("class", "group");
        material->setStyleSheet(settings.value("styles/root").toString());
        color = new ColorField("Color:");
        rough = new SliderField("Roughness:", 0, 100, 50);
        spec = new SliderField("Specular:", 0, 100, 50);

        QVBoxLayout* matVBox = new QVBoxLayout;
        matVBox->addWidget(color);
        matVBox->addWidget(rough);
        matVBox->addWidget(spec);

        material->setLayout(matVBox);

        camera = new QGroupBox("Camera");
        camera->setProperty("class", "group");
        camera->setStyleSheet(settings.value("styles/root").toString());
        fov = new SliderField("FOV:", 0, 180, 35);
        dof = new BoolField("DOF:", true);
        aperture = new FloatField("Aperture: ", 0.0f, INFINITY, 2.0f);
        distance = new FloatField("Distance: ", 0.0f, INFINITY, 2.0f);

        vbox = new QVBoxLayout();
        vbox->addWidget(name);
        vbox->addWidget(transform);
        vbox->addWidget(material);
        vbox->addStretch();
        setLayout(vbox);
    }

    void setModel(Model* m) {
        name->setText(m->name);
        loc->fromQVector3D(m->location);
        rot->fromQVector3D(m->rotation);
        sca->fromQVector3D(m->scale);

        color->popup->setCurrentColor(m->material.color);
        color->changeColor();

        rough->set(m->material.roughness * 100);
        spec->set(m->material.specular * 100);

        repaint();
    }
};

class LightTab : public QTabWidget {
public:
    QLineEdit* name;

    QGroupBox* transform;
    QVector3DField* loc;

    QGroupBox* light;
    ColorField* color;
    FloatField* strength;

    QVBoxLayout* vbox;


    LightTab(QWidget* parent = nullptr) : QTabWidget(parent) {
        QSettings settings;

        name = new QLineEdit();
        name->setProperty("class", "transparentTextInput");
        name->setStyleSheet(settings.value("styles/root").toString());

        transform = new QGroupBox("Transforms");
        transform->setProperty("class", "group");
        transform->setStyleSheet(settings.value("styles/root").toString());

        loc = new QVector3DField("Loc:", -INFINITY, INFINITY, 0);

        QVBoxLayout* transVBox = new QVBoxLayout;
        transVBox->addWidget(loc);

        transform->setLayout(transVBox);


        light = new QGroupBox("Light");
        light->setProperty("class", "group");
        light->setStyleSheet(settings.value("styles/root").toString());
        color = new ColorField("Color:");
        strength = new FloatField("Strength:", 0.0f, INFINITY, 1.0f);

        QVBoxLayout* litVBox = new QVBoxLayout;
        litVBox->addWidget(color);
        litVBox->addWidget(strength);

        light->setLayout(litVBox);

        vbox = new QVBoxLayout();
        vbox->addWidget(transform);
        vbox->addWidget(light);
        vbox->addStretch();
        setLayout(vbox);
    }

    void setLight(Light* l) {
        name->setText(l->name);
        loc->fromQVector3D(l->location);

        color->popup->setCurrentColor(l->light.color);
        color->changeColor();

        strength->set(l->light.strength);

        repaint();
    }
};

class CameraTab : public QTabWidget {
public:
    QLineEdit* name;

    QGroupBox* transform;
    QVector3DField* loc;
    QVector3DField* rot;

    QGroupBox* camera;
    SliderField* fov;
    BoolField* dof;
    FloatField* aperture;
    FloatField* distance;

    QVBoxLayout* vbox;


    CameraTab(QWidget* parent = nullptr) : QTabWidget(parent) {
        QSettings settings;

        name = new QLineEdit();
        name->setProperty("class", "transparentTextInput");
        name->setStyleSheet(settings.value("styles/root").toString());

        transform = new QGroupBox("Transforms");
        transform->setProperty("class", "group");
        transform->setStyleSheet(settings.value("styles/root").toString());

        loc = new QVector3DField("Loc:", -INFINITY, INFINITY, 0);
        rot = new QVector3DField("Rot:", -INFINITY, INFINITY, 0);

        QVBoxLayout* transVBox = new QVBoxLayout;
        transVBox->addWidget(loc);
        transVBox->addWidget(rot);

        transform->setLayout(transVBox);

        camera = new QGroupBox("Camera");
        camera->setProperty("class", "group");
        camera->setStyleSheet(settings.value("styles/root").toString());
        fov = new SliderField("FOV:", 0, 180, 35);
        dof = new BoolField("DOF:", true);
        aperture = new FloatField("Aperture: ", 0.0f, INFINITY, 2.0f);
        distance = new FloatField("Distance: ", 0.0f, INFINITY, 2.0f);


        QVBoxLayout* camVBox = new QVBoxLayout;
        camVBox->addWidget(fov);
        camVBox->addWidget(dof);
        camVBox->addWidget(aperture);
        camVBox->addWidget(distance);

        camera->setLayout(camVBox);

        vbox = new QVBoxLayout();
        vbox->addWidget(transform);
        vbox->addWidget(camera);
        vbox->addStretch();
        setLayout(vbox);
    }

    void setCamera(RenderCamera* c) {
        name->setText(c->name);
        loc->fromQVector3D(c->location);
        rot->fromQVector3D(c->rotation);

        fov->set(c->fov);
        dof->edit->setChecked(c->settings.dof);
        distance->set(c->settings.distance);
        aperture->set(c->settings.aperture);

        repaint();
    }
};

#endif