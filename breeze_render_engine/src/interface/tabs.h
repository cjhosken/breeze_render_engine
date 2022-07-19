#ifndef TABS_H
#define TABS_H

#include "../common.h"
#include "fields.h"

class RenderTab : public QWidget {
public:
    IntegerField* widthInput;
    IntegerField* heightInput;

    IntegerField* samplesInput;
    IntegerField* bouncesInput;

    QPushButton* renderButton;

    RenderTab(QWidget* parent = nullptr) : QWidget(parent) {
        setAutoFillBackground(true);
        /*
            width:  ( i )
            height: ( i )
            samples: ( i )
            bounces: ( i )
            
            [ render ] 

        */
        QGroupBox* dims = new QGroupBox("Dimensions");
        dims->setStyleSheet("QGroupBox {color: white;}");
        widthInput = new IntegerField("Width:", 1, 2147483647, 640);

        heightInput = new IntegerField("Height:", 1, 2147483647, 480);

        QVBoxLayout* dimsVBox = new QVBoxLayout;
        dimsVBox->addWidget(widthInput);
        dimsVBox->addWidget(heightInput);
        dims->setLayout(dimsVBox);


        QGroupBox* rays = new QGroupBox("Rays");
        rays->setStyleSheet("QGroupBox {color: white;}");
        samplesInput = new IntegerField("Samples:", 1, 2147483647, 16);

        bouncesInput = new IntegerField("Bounces:", 1, 2147483647, 4);

        QVBoxLayout* raysVBox = new QVBoxLayout;
        raysVBox->addWidget(samplesInput);
        raysVBox->addWidget(bouncesInput);
        rays->setLayout(raysVBox);

        renderButton = new QPushButton("Render");
        renderButton->setStyleSheet("QPushButton{background-color: transparent; padding: 5px; color: white; border: 1px solid white; border-radius: 10px;}");

        QVBoxLayout* vbox = new QVBoxLayout();
        vbox->addWidget(dims);
        vbox->addWidget(rays);

        vbox->addWidget(renderButton);

        vbox->addStretch();

        setLayout(vbox);
    }
};

class WorldTab : public QWidget {
public:
    SliderField* fov;
    ColorField* gradIn;
    ColorField* gradOut;
    
    WorldTab(QWidget* parent = nullptr) : QWidget(parent) {
        setAutoFillBackground(true);
        /*
            fov:    ( f )
            
            Gradient-Inner:    ( r ), ( g ), ( b )
            Gradient-Outer:    ( r ), ( g ), ( b )

        */
        QGroupBox* view = new QGroupBox("Viewport Controls");
        view->setStyleSheet(".QGroupBox {color: white;}");
        fov = new SliderField("FOV:", 1, 180, 35);

        QVBoxLayout* viewVBox = new QVBoxLayout;
        viewVBox->addWidget(fov);
        view->setLayout(viewVBox);

        QGroupBox* back = new QGroupBox("Viewport Background");
        back->setStyleSheet(".QGroupBox {color: white;}");
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

class ObjectTab : public QWidget {
public:
    QLineEdit* name;
    QVector3DField* loc;
    QVector3DField* rot;
    QVector3DField* sca;

    ColorField* color;
    SliderField* rough;
    SliderField* spec;

    QVBoxLayout* vbox;
    
    bool isCamera;

    ObjectTab(QWidget* parent = nullptr) : QWidget(parent) {
        setAutoFillBackground(true);


        /*
                        Name

            Location:    ( x ), ( y ), ( z )
            Rotation:    ( x ), ( y ), ( z )
            Scale:       ( x ), ( y ), ( z )

            Color:       ( r ), ( g ), ( b )
            Roughness:   ( f )
            Specular:    ( f )
        */

        isCamera = true;
        drawPanels();

        setLayout(vbox);
    }

    void drawPanels() {
        name = new QLineEdit();
        name->setStyleSheet("QLineEdit {background-color: transparent; border: none; color: white;}");

        QGroupBox* transform = new QGroupBox("Transforms");
        transform->setStyleSheet(".QGroupBox {color: white;}");
        loc = new QVector3DField("Loc:", -INFINITY, INFINITY, 0);
        rot = new QVector3DField("Rot:", -INFINITY, INFINITY, 0);
        sca = new QVector3DField("Scale:", -INFINITY, INFINITY, 0);

        QVBoxLayout* transVBox = new QVBoxLayout;
        transVBox->addWidget(loc);
        transVBox->addWidget(rot);
        transVBox->addWidget(sca);

        transform->setLayout(transVBox);

        vbox = new QVBoxLayout();

        vbox->addWidget(name);

        vbox->addWidget(transform);

            QGroupBox* material = new QGroupBox("Material");
            material->setStyleSheet(".QGroupBox {color: white;}");
            color = new ColorField("Color:");
            rough = new SliderField("Roughness:", 0, 100, 50);
            spec = new SliderField("Specular:", 0, 100, 50);

            QVBoxLayout* matVBox = new QVBoxLayout;
            matVBox->addWidget(color);
            matVBox->addWidget(rough);
            matVBox->addWidget(spec);

            material->setLayout(matVBox);
            vbox->addWidget(material);

        vbox->addStretch();
    }

    void loadModel(Model* &m) {
        name->setText(QString::fromStdString(m->name));
        loc->fromQVector3D(m->location);
        rot->fromQVector3D(m->rotation);
        sca->fromQVector3D(m->scale);

        color->fromQVector3D(m->material.color);
        color->changeColor();

        rough->set(m->material.roughness * 100);
        spec->set(m->material.specular * 100);
    }
};

#endif