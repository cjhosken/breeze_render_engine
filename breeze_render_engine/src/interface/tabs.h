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
        widthInput = new IntegerField("Width:");

        heightInput = new IntegerField("Height:");

        QVBoxLayout* dimsVBox = new QVBoxLayout;
        dimsVBox->addWidget(widthInput);
        dimsVBox->addWidget(heightInput);
        dims->setLayout(dimsVBox);


        QGroupBox* rays = new QGroupBox("Rays");
        rays->setStyleSheet("QGroupBox {color: white;}");
        samplesInput = new IntegerField("Samples:");

        bouncesInput = new IntegerField("Bounces:");

        QVBoxLayout* raysVBox = new QVBoxLayout;
        raysVBox->addWidget(samplesInput);
        raysVBox->addWidget(bouncesInput);
        rays->setLayout(raysVBox);

        renderButton = new QPushButton("Render");

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
        fov = new SliderField("Viewport FOV:", 0, 180, 35);

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

    SliderField* fov;

    BoolField* isDOF;

    FloatField* focusDist;

    FloatField* aper;

    
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

        /*
                Camera

            Location:    ( x ), ( y ), ( z )
            Rotation:    ( x ), ( y ), ( z )
            Scale:       ( x ), ( y ), ( z )

            fov: ( f )

            dof: ( b )
            aperture: ( f )
        */


        name = new QLineEdit();

        QGroupBox* transform = new QGroupBox("Transforms");
        transform->setStyleSheet(".QGroupBox {color: white;}");
        loc = new QVector3DField("Location:");
        rot = new QVector3DField("Rotation:");
        sca = new QVector3DField("Scale:");

        QVBoxLayout* transVBox = new QVBoxLayout;
        transVBox->addWidget(loc);
        transVBox->addWidget(rot);
        transVBox->addWidget(sca);

        transform->setLayout(transVBox);

        QVBoxLayout* vbox = new QVBoxLayout();

        if (!isCamera) {
            vbox->addWidget(name);
        }

        vbox->addWidget(transform);

        if (!isCamera) {
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
        }
        else {
            QGroupBox* camera = new QGroupBox("Camera");
            camera->setStyleSheet(".QGroupBox {color: white;}");
            fov = new SliderField("FOV:", 0, 180, 35);

            isDOF = new BoolField("DOF:");

            focusDist = new FloatField("Distance: ");

            aper = new FloatField("Aperture:");

            QVBoxLayout* camVBox = new QVBoxLayout;
            camVBox->addWidget(fov);
            camVBox->addWidget(isDOF);
            camVBox->addWidget(focusDist);
            camVBox->addWidget(aper);

            camera->setLayout(camVBox);
            vbox->addWidget(camera);
        }

        vbox->addStretch();

        setLayout(vbox);
    }
};

#endif