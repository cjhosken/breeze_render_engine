#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include "../common.h"
#include "applicationsettings.h"
#include "glwidget.h"

#include "dragbar.h"
#include "propertiespanel.h"
#include "root.h"

QT_BEGIN_NAMESPACE

class Ui_Window
{
public:
    ApplicationSettings settings;
    QWidget* centralWidget;
    GLWidget* glCanvas;
    DragBar* dragBar;
    PropertiesPanel* propertiesPanel;
    QWidget* toolBar;
    QWidget* debugBar;

    QPushButton* appButton;

    QPushButton* b1;
    QPushButton* b2;
    QPushButton* b3;
    QPushButton* b4;
    QPushButton* b5;
    QPushButton* b6;
    QPushButton* b7;

    //QPushButton* d0;
    QPushButton* d1;
    QPushButton* d2;

    QPushButton* t1;
    QPushButton* t2;
    QPushButton* t3;

    QPushButton* r1;
    QPushButton* r2;

    void setupUi(QMainWindow* Window)
    {
        Window->resize(settings.APP_WIDTH, settings.APP_HEIGHT);
        centralWidget = new QWidget(Window);

        glCanvas = new GLWidget(centralWidget);
        glCanvas->setGeometry(QRect(0, 0, settings.APP_WIDTH, settings.APP_HEIGHT));

        dragBar = new DragBar(centralWidget);
        dragBar->setGeometry(QRect(0, 0, settings.APP_WIDTH, 30));

        propertiesPanel = new PropertiesPanel(centralWidget);
        propertiesPanel->setGeometry(QRect(1320, 100, 235, 755));
        propertiesPanel->root->setGeometry(QRect(10, 10, 215, 735));

        appButton = new QPushButton(centralWidget);
        appButton->setGeometry(QRect(23, 21, 50, 50));
        appButton->setIcon(QIcon("assets/images/logo.png"));
        appButton->setStyleSheet(".QPushButton {color: white; background-color: transparent;}");
        appButton->setIconSize(QSize(45, 45));

        toolBar = new QWidget(centralWidget);
        toolBar->setGeometry(QRect(23, 105, 50, 350));
        toolBar->setStyleSheet(".QWidget{background-color: rgba(15, 15, 15, 200); border-radius: 20px;}");

        b1 = new QPushButton(toolBar);
        b1->setGeometry(QRect(0, 0, 50, 50));
        b1->setIcon(QIcon("assets/images/icons/cursor.png"));
        b1->setStyleSheet(".QPushButton {color: white; transparent; border-radius: 20px;};");
        b1->setIconSize(QSize(28, 28));

        b2 = new QPushButton(toolBar);
        b2->setGeometry(QRect(0, 50, 50, 50));
        b2->setIcon(QIcon("assets/images/icons/cube.png"));
        b2->setStyleSheet(".QPushButton {color: white; transparent; border-radius: 20px;};");
        b2->setIconSize(QSize(28, 28));

        b3 = new QPushButton(toolBar);
        b3->setGeometry(QRect(0, 100, 50, 50));
        b3->setIcon(QIcon("assets/images/icons/plane.png"));
        b3->setStyleSheet(".QPushButton {color: white; transparent; border-radius: 20px;};");
        b3->setIconSize(QSize(28, 28));

        b4 = new QPushButton(toolBar);
        b4->setGeometry(QRect(0, 150, 50, 50));
        b4->setIcon(QIcon("assets/images/icons/sphere.png"));
        b4->setStyleSheet(".QPushButton {color: white; transparent; border-radius: 20px;};");
        b4->setIconSize(QSize(28, 28));

        b5 = new QPushButton(toolBar);
        b5->setGeometry(QRect(0, 200, 50, 50));
        b5->setIcon(QIcon("assets/images/icons/add.png"));
        b5->setStyleSheet(".QPushButton {color: white; transparent; border-radius: 20px;};");
        b5->setIconSize(QSize(28, 28));

        b6 = new QPushButton(toolBar);
        b6->setGeometry(QRect(0, 250, 50, 50));
        b6->setIcon(QIcon("assets/images/icons/light.png"));
        b6->setStyleSheet(".QPushButton {color: white; transparent; border-radius: 20px;};");
        b6->setIconSize(QSize(28, 28));

        b7 = new QPushButton(toolBar);
        b7->setGeometry(QRect(0, 300, 50, 50));
        b7->setIcon(QIcon("assets/images/icons/more.png"));
        b7->setStyleSheet(".QPushButton {color: white; transparent; border-radius: 20px;};");
        b7->setIconSize(QSize(28, 28));

        debugBar = new QWidget(centralWidget);
        debugBar->setGeometry(QRect(23, 765, 50, 100));
        debugBar->setStyleSheet(".QWidget{background-color: rgba(15, 15, 15, 200); border-radius: 20px;}");

        /*
        d0 = new QPushButton(centralWidget);
        d0->setGeometry(QRect(23, 700, 50, 50));
        d0->setIcon(QIcon("assets/images/icons/log.png"));
        d0->setStyleSheet(".QPushButton {color: white; transparent; border-radius: 20px;};");
        d0->setIconSize(QSize(28, 28));
        */

        d1 = new QPushButton(debugBar);
        d1->setGeometry(QRect(0, 0, 50, 50));
        d1->setIcon(QIcon("assets/images/icons/info.png"));
        d1->setStyleSheet(".QPushButton {color: white; transparent; border-radius: 20px 0px 00px 20px;}");
        d1->setIconSize(QSize(28, 28));

        d2 = new QPushButton(debugBar);
        d2->setGeometry(QRect(0, 50, 50, 50));
        d2->setIcon(QIcon("assets/images/icons/code.png"));
        d2->setStyleSheet(".QPushButton {color: white; transparent; border-radius: 0px 20px 20px 0px;}");
        d2->setIconSize(QSize(28, 28));



        t1 = new QPushButton(centralWidget);
        t1->setGeometry(QRect(738, 30, 35, 35));
        t1->setIcon(QIcon("assets/images/icons/wire.png"));
        t1->setStyleSheet(".QPushButton {color: white; background-color: transparent; border-radius: 17px;}");
        t1->setIconSize(QSize(26, 26));

        t2 = new QPushButton(centralWidget);
        t2->setGeometry(QRect(783, 30, 35, 35));
        t2->setIcon(QIcon("assets/images/icons/solid.png"));
        t2->setStyleSheet(".QPushButton {color: white; background-color: transparent; border-radius: 17px;}");
        t2->setIconSize(QSize(26, 26));

        t3 = new QPushButton(centralWidget);
        t3->setGeometry(QRect(828, 30, 35, 35));
        t3->setIcon(QIcon("assets/images/icons/shaded.png"));
        t3->setStyleSheet(".QPushButton {color: white; background-color: transparent; border-radius: 17px;}");
        t3->setIconSize(QSize(26, 26));



        r1 = new QPushButton(centralWidget);
        r1->setGeometry(QRect(1480, 30, 35, 35));
        r1->setIcon(QIcon("assets/images/icons/bug.png"));
        r1->setStyleSheet(".QPushButton {color: white; background-color: rgba(15, 15, 15, 200); border-radius: 17px;}");
        r1->setIconSize(QSize(26, 26));

        r2 = new QPushButton(centralWidget);
        r2->setGeometry(QRect(1520, 30, 35, 35));
        r2->setIcon(QIcon("assets/images/icons/close.png"));
        r2->setStyleSheet(".QPushButton {color: white; background-color: rgba(15, 15, 15, 200); border-radius: 17px;}");
        r2->setIconSize(QSize(26, 26));
     

        Window->setCentralWidget(centralWidget);
        retranslateUi(Window);

        QMetaObject::connectSlotsByName(Window);
    } // setupUi

    void retranslateUi(QMainWindow* Window)
    {
        Window->setWindowFlags(Qt::FramelessWindowHint);


    } // retranslateUi
};

namespace Ui {
    class Window : public Ui_Window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H