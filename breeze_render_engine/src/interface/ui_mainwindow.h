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

    QPushButton* appButtons;
    QMenu* appButtonsMenu;
    QAction* appQuitButton;

    QPushButton* toggleObjectSelectionButton;
    QPushButton* addCubeButton;
    QPushButton* addPlaneButton;
    QPushButton* addSphereButton;
    QPushButton* addOBJButton;
    QPushButton* addLightButton;
    QPushButton* addExtrasButton;

    QPushButton* docsButton;
    QPushButton* codeButton;

    QPushButton* wireViewButton;
    QPushButton* solidViewButton;
    QPushButton* shadedViewButton;

    QPushButton* reportBugButton;
    QPushButton* closeButton;



    QMenu* extraButtonsMenu;

    QAction* addCircle;
    QAction* addTriangle;
    QAction* addCylinder;
    QAction* addMonkey;
    QAction* addTeapot;


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

        appButtons = new QPushButton(centralWidget);
        appButtons->setGeometry(QRect(23, 21, 50, 50));
        appButtons->setIcon(QIcon(":/assets/images/logo.png"));
        appButtons->setStyleSheet(".QPushButton {color: white; background-color: transparent;}  .QPushButton::menu-indicator {width: 0px;}");
        appButtons->setIconSize(QSize(45, 45));

        appButtonsMenu = new QMenu();
        appButtonsMenu->setStyleSheet(".QMenu{background-color: rgba(15, 15, 15, 200); border-radius: 15px; color: white;}");
        appQuitButton = new QAction("Quit");
        appButtonsMenu->addAction(appQuitButton);
        appButtons->setMenu(appButtonsMenu);


        toolBar = new QWidget(centralWidget);
        toolBar->setGeometry(QRect(23, 105, 50, 350));
        toolBar->setStyleSheet(".QWidget{background-color: rgba(15, 15, 15, 200); border-radius: 20px;}");

        toggleObjectSelectionButton = new QPushButton(toolBar);
        toggleObjectSelectionButton->setGeometry(QRect(0, 0, 50, 50));
        toggleObjectSelectionButton->setIcon(QIcon(":/assets/images/icons/cursor.png"));
        toggleObjectSelectionButton->setStyleSheet(".QPushButton {color: white; transparent; border-radius: 20px;};");
        toggleObjectSelectionButton->setIconSize(QSize(28, 28));

        addCubeButton = new QPushButton(toolBar);
        addCubeButton->setGeometry(QRect(0, 50, 50, 50));
        addCubeButton->setIcon(QIcon(":/assets/images/icons/cube.png"));
        addCubeButton->setStyleSheet(".QPushButton {color: white; transparent; border-radius: 20px;};");
        addCubeButton->setIconSize(QSize(28, 28));

        addPlaneButton = new QPushButton(toolBar);
        addPlaneButton->setGeometry(QRect(0, 100, 50, 50));
        addPlaneButton->setIcon(QIcon(":/assets/images/icons/plane.png"));
        addPlaneButton->setStyleSheet(".QPushButton {color: white; transparent; border-radius: 20px;};");
        addPlaneButton->setIconSize(QSize(28, 28));

        addSphereButton = new QPushButton(toolBar);
        addSphereButton->setGeometry(QRect(0, 150, 50, 50));
        addSphereButton->setIcon(QIcon(":/assets/images/icons/sphere.png"));
        addSphereButton->setStyleSheet(".QPushButton {color: white; transparent; border-radius: 20px;};");
        addSphereButton->setIconSize(QSize(28, 28));

        addOBJButton = new QPushButton(toolBar);
        addOBJButton->setGeometry(QRect(0, 200, 50, 50));
        addOBJButton->setIcon(QIcon(":/assets/images/icons/add.png"));
        addOBJButton->setStyleSheet(".QPushButton {color: white; transparent; border-radius: 20px;};");
        addOBJButton->setIconSize(QSize(28, 28));

        addLightButton = new QPushButton(toolBar);
        addLightButton->setGeometry(QRect(0, 250, 50, 50));
        addLightButton->setIcon(QIcon(":/assets/images/icons/light.png"));
        addLightButton->setStyleSheet(".QPushButton {color: white; transparent; border-radius: 20px;};");
        addLightButton->setIconSize(QSize(28, 28));

        addExtrasButton = new QPushButton(toolBar);
        addExtrasButton->setGeometry(QRect(0, 300, 50, 50));
        addExtrasButton->setIcon(QIcon(":/assets/images/icons/more.png"));
        addExtrasButton->setStyleSheet(".QPushButton {color: white; transparent; border-radius: 20px;} .QPushButton::menu-indicator {width: 0px;}");
        addExtrasButton->setIconSize(QSize(28, 28));

        extraButtonsMenu = new QMenu();
        extraButtonsMenu->setStyleSheet(".QMenu{background-color: rgba(15, 15, 15, 200); border-radius: 15px; color: white;}");
        addCircle = new QAction("Circle");
        extraButtonsMenu->addAction(addCircle);
        addTriangle = new QAction("Triangle");
        extraButtonsMenu->addAction(addTriangle);
        addCylinder = new QAction("Cylinder");
        extraButtonsMenu->addAction(addCylinder);
        addMonkey = new QAction("Monkey");
        extraButtonsMenu->addAction(addMonkey);
        addTeapot = new QAction("Teapot");
        extraButtonsMenu->addAction(addTeapot);

        addExtrasButton->setMenu(extraButtonsMenu);


        debugBar = new QWidget(centralWidget);
        debugBar->setGeometry(QRect(23, 765, 50, 100));
        debugBar->setStyleSheet(".QWidget{background-color: rgba(15, 15, 15, 200); border-radius: 20px;}");


        docsButton = new QPushButton(debugBar);
        docsButton->setGeometry(QRect(0, 0, 50, 50));
        docsButton->setIcon(QIcon(":/assets/images/icons/info.png"));
        docsButton->setStyleSheet(".QPushButton {color: white; transparent; border-radius: 20px 0px 00px 20px;}");
        docsButton->setIconSize(QSize(28, 28));

        codeButton = new QPushButton(debugBar);
        codeButton->setGeometry(QRect(0, 50, 50, 50));
        codeButton->setIcon(QIcon(":/assets/images/icons/code.png"));
        codeButton->setStyleSheet(".QPushButton {color: white; transparent; border-radius: 0px 20px 20px 0px;}");
        codeButton->setIconSize(QSize(28, 28));



        wireViewButton = new QPushButton(centralWidget);
        wireViewButton->setGeometry(QRect(738, 30, 35, 35));
        wireViewButton->setIcon(QIcon(":/assets/images/icons/wire.png"));
        wireViewButton->setStyleSheet(".QPushButton {color: white; background-color: transparent; border-radius: 17px;}");
        wireViewButton->setIconSize(QSize(26, 26));

        solidViewButton = new QPushButton(centralWidget);
        solidViewButton->setGeometry(QRect(783, 30, 35, 35));
        solidViewButton->setIcon(QIcon(":/assets/images/icons/solid.png"));
        solidViewButton->setStyleSheet(".QPushButton {color: white; background-color: transparent; border-radius: 17px;}");
        solidViewButton->setIconSize(QSize(26, 26));

        shadedViewButton = new QPushButton(centralWidget);
        shadedViewButton->setGeometry(QRect(828, 30, 35, 35));
        shadedViewButton->setIcon(QIcon(":/assets/images/icons/shaded.png"));
        shadedViewButton->setStyleSheet(".QPushButton {color: white; background-color: transparent; border-radius: 17px;}");
        shadedViewButton->setIconSize(QSize(26, 26));



        reportBugButton = new QPushButton(centralWidget);
        reportBugButton->setGeometry(QRect(1480, 30, 35, 35));
        reportBugButton->setIcon(QIcon(":/assets/images/icons/bug.png"));
        reportBugButton->setStyleSheet(".QPushButton {color: white; background-color: rgba(15, 15, 15, 200); border-radius: 17px;}");
        reportBugButton->setIconSize(QSize(26, 26));

        closeButton = new QPushButton(centralWidget);
        closeButton->setGeometry(QRect(1520, 30, 35, 35));
        closeButton->setIcon(QIcon(":/assets/images/icons/close.png"));
        closeButton->setStyleSheet(".QPushButton {color: white; background-color: rgba(15, 15, 15, 200); border-radius: 17px;}");
        closeButton->setIconSize(QSize(26, 26));
     

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