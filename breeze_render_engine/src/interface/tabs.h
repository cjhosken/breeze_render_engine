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
    WorldTab(QWidget* parent = nullptr) : QWidget(parent) {
        setAutoFillBackground(true);
        /*
            fov:    ( f )s
            
            Gradient-Inner:    ( r ), ( g ), ( b )
            Gradient-Outer:    ( r ), ( g ), ( b )

        */
        QGroupBox* view = new QGroupBox("Viewport Controls");
        view->setStyleSheet(".QGroupBox {color: white;}");
        FloatField* fov = new FloatField("Viewport Fov:");

        QVBoxLayout* viewVBox = new QVBoxLayout;
        viewVBox->addWidget(fov);
        view->setLayout(viewVBox);

        QGroupBox* back = new QGroupBox("Viewport Background");
        back->setStyleSheet(".QGroupBox {color: white;}");
        ColorField* gradIn = new ColorField("Inner Gradient:");
        ColorField* gradOut = new ColorField("Outer Gradient:");

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


        QLineEdit* name = new QLineEdit();

        QGroupBox* transform = new QGroupBox("Transforms");
        transform->setStyleSheet(".QGroupBox {color: white;}");
        QVector3DField* loc = new QVector3DField("Location:");
        QVector3DField* rot = new QVector3DField("Rotation:");
        QVector3DField* sca = new QVector3DField("Scale:");

        QVBoxLayout* transVBox = new QVBoxLayout;
        transVBox->addWidget(loc);
        transVBox->addWidget(rot);
        transVBox->addWidget(sca);

        transform->setLayout(transVBox);


        QGroupBox* material = new QGroupBox("Material");
        material->setStyleSheet(".QGroupBox {color: white;}");
        ColorField* color = new ColorField("Color:");
        FloatField* rough = new FloatField("Roughness:");
        FloatField* spec = new FloatField("Specular:");

        QVBoxLayout* matVBox = new QVBoxLayout;
        matVBox->addWidget(color);
        matVBox->addWidget(rough);
        matVBox->addWidget(spec);

        material->setLayout(matVBox);


        QVBoxLayout* vbox = new QVBoxLayout();

        vbox->addWidget(name);
        vbox->addWidget(transform);
        vbox->addWidget(material);
        vbox->addStretch();

        setLayout(vbox);
    }
};

#endif