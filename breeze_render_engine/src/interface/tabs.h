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

class WorldTab : public QWidget {
public:
    SliderField* fov;
    ColorField* gradIn;
    ColorField* gradOut;
    
    WorldTab(QWidget* parent = nullptr) : QWidget(parent) {
        QSettings settings;
        setAutoFillBackground(true);
        /*
            fov:    ( f )
            
            Gradient-Inner:    ( r ), ( g ), ( b )
            Gradient-Outer:    ( r ), ( g ), ( b )

        */
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

class ObjectTab : public QWidget {
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
    

    ObjectTab(QWidget* parent = nullptr) : QWidget(parent) {
        QSettings settings;

        name = new QLineEdit();
        name->setStyleSheet("QLineEdit {background-color: transparent; border: none; color: white;}");

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


        QVBoxLayout* camVBox = new QVBoxLayout;
        camVBox->addWidget(fov);
        camVBox->addWidget(dof);
        camVBox->addWidget(aperture);
        camVBox->addWidget(distance);

        camera->setLayout(matVBox);


        /*
                        Name

            Location:    ( x ), ( y ), ( z )
            Rotation:    ( x ), ( y ), ( z )
            Scale:       ( x ), ( y ), ( z )

            Color:       ( r ), ( g ), ( b )
            Roughness:   ( f )
            Specular:    ( f )
        */

        vbox = new QVBoxLayout();
        setLayout(vbox);
        hide();
    }

    void setModel(Model* &m) {
        //clear();
        name->setText(QString::fromStdString(m->name));
        loc->fromQVector3D(m->location);
        rot->fromQVector3D(m->rotation);
        sca->fromQVector3D(m->scale);

        color->popup->setCurrentColor(m->material.color);
        color->changeColor();

        rough->set(m->material.roughness * 100);
        spec->set(m->material.specular * 100);

        vbox->addWidget(name);
        vbox->addWidget(transform);
        vbox->addWidget(material);
        vbox->addStretch();

        repaint();
    }

    void setCamera(RenderCamera c) {
        //clear();
        loc->fromQVector3D(c.location);
        rot->fromQVector3D(c.rotation);
        sca->fromQVector3D(c.scale);

        fov->set(c.fov);
        
        vbox->addWidget(transform);
        vbox->addWidget(camera);
        vbox->addStretch();

        repaint();
    }
private:
    void clear()
    {
        while (QLayoutItem* item = vbox->takeAt(0))
        {
                if (QWidget* widget = item->widget())
                    widget->deleteLater();

            delete item;
        }
    }

};

#endif