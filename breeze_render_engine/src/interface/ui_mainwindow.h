#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include "../common.h"
#include "glwidget.h"

#include "dragbar.h"
#include "propertiespanel.h"

#include "widgets/qiconbutton.h"
#include "widgets/qtoggleiconbutton.h"
#include "widgets/qconfirmbox.h"

QT_BEGIN_NAMESPACE

class Ui_Window
{
public:
    QWidget* centralWidget;
    GLWidget* glCanvas;
    DragBar* dragBar;
    PropertiesPanel* propertiesPanel;
    QWidget* toolBar;
    QWidget* debugBar;

    QIconButton* appButtons;
    QMenu* appButtonsMenu;
    QAction* appQuitButton;

    QToggleIconButton* toggleObjectSelectionButton;
    QIconButton* addCubeButton;
    QIconButton* addPlaneButton;
    QIconButton* addSphereButton;
    QIconButton* addCameraButton;
    QIconButton* addLightButton;
    QIconButton* addExtrasButton;

    QIconButton* docsButton;
    QIconButton* codeButton;

    QToggleIconButton* wireViewButton;
    QToggleIconButton* solidViewButton;
    QToggleIconButton* shadedViewButton;

    QIconButton* reportBugButton;
    QIconButton* closeButton;

    QMenu* extraButtonsMenu;

    QAction* addCircle;
    QAction* addTriangle;
    QAction* addCylinder;
    QAction* addMonkey;
    QAction* addTeapot;
    QAction* addOBJ;

    void setupUi(QMainWindow* Window)
    {
        QSettings settings;
        Window->resize(settings.value("app/width").toInt(), settings.value("app/height").toInt());
        centralWidget = new QWidget(Window);

        glCanvas = new GLWidget(centralWidget);
        glCanvas->setGeometry(QRect(0, 0, settings.value("app/width").toInt(), settings.value("app/height").toInt()));

        dragBar = new DragBar(centralWidget);
        dragBar->setGeometry(QRect(0, 0, settings.value("app/width").toInt(), 30));

        propertiesPanel = new PropertiesPanel(centralWidget);
        propertiesPanel->setGeometry(QRect(1320, 100, 235, 755));
        propertiesPanel->root->setGeometry(QRect(10, 10, 215, 735));

        appButtons = new QIconButton(QIcon(":/assets/images/logo.png"), 45, centralWidget);
        appButtons->setGeometry(QRect(23, 30, 50, 50));
        appButtons->setProperty("class", "appButton");

        appButtonsMenu = new QMenu();
        appButtonsMenu->setProperty("class", "menu");
        appButtonsMenu->setStyleSheet(settings.value("styles/root").toString());
        appQuitButton = new QAction("Quit");
        appButtonsMenu->addAction(appQuitButton);
        appButtons->setMenu(appButtonsMenu);

        toolBar = new QWidget(centralWidget);
        toolBar->setGeometry(QRect(23, 105, 50, 350));
        toolBar->setProperty("class", "panel");
        toolBar->setStyleSheet(settings.value("styles/root").toString());

        toggleObjectSelectionButton = new QToggleIconButton(QIcon(":/assets/images/icons/cursor.png"), 28, toolBar);
        toggleObjectSelectionButton->setGeometry(QRect(0, 0, 50, 50));
        toggleObjectSelectionButton->setChecked(true);
        toggleObjectSelectionButton->setColor();

        addCubeButton = new QIconButton(QIcon(":/assets/images/icons/cube.png"), 28, toolBar);
        addCubeButton->setGeometry(QRect(0, 50, 50, 50));

        addPlaneButton = new QIconButton(QIcon(":/assets/images/icons/plane.png"), 28, toolBar);
        addPlaneButton->setGeometry(QRect(0, 100, 50, 50));

        addSphereButton = new QIconButton(QIcon(":/assets/images/icons/sphere.png"), 28, toolBar);
        addSphereButton->setGeometry(QRect(0, 150, 50, 50));

        addCameraButton = new QIconButton(QIcon(":/assets/images/icons/camera.png"), 28, toolBar);
        addCameraButton->setGeometry(QRect(0, 200, 50, 50));

        addLightButton = new QIconButton(QIcon(":/assets/images/icons/light.png"), 28, toolBar);
        addLightButton->setGeometry(QRect(0, 250, 50, 50));

        addExtrasButton = new QIconButton(QIcon(":/assets/images/icons/more.png"), 28, toolBar);
        addExtrasButton->setGeometry(QRect(0, 300, 50, 50));

        extraButtonsMenu = new QMenu();
        extraButtonsMenu->setProperty("class", "menu");
        extraButtonsMenu->setStyleSheet(settings.value("styles/root").toString());
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
        addOBJ = new QAction("OBJ");
        extraButtonsMenu->addAction(addOBJ);

        addExtrasButton->setMenu(extraButtonsMenu);

        debugBar = new QWidget(centralWidget);
        debugBar->setGeometry(QRect(23, 765, 50, 100));
        debugBar->setProperty("class", "panel");
        debugBar->setStyleSheet(settings.value("styles/root").toString());


        docsButton = new QIconButton(QIcon(":/assets/images/icons/info.png"), 28, debugBar);
        docsButton->setGeometry(QRect(0, 0, 50, 50));

        codeButton = new QIconButton(QIcon(":/assets/images/icons/code.png"), 28, debugBar);
        codeButton->setGeometry(QRect(0, 50, 50, 50));

        wireViewButton = new QToggleIconButton(QIcon(":/assets/images/icons/wire.png"), 28, centralWidget);
        wireViewButton->setGeometry(QRect(725, 30, 50, 50));
        wireViewButton->setChecked(false);
        wireViewButton->setColor();

        solidViewButton = new QToggleIconButton(QIcon(":/assets/images/icons/solid.png"), 28, centralWidget);
        solidViewButton->setGeometry(QRect(775, 30, 50, 50));
        solidViewButton->setChecked(true);
        solidViewButton->setColor();

        shadedViewButton = new QToggleIconButton(QIcon(":/assets/images/icons/shaded.png"), 28, centralWidget);
        shadedViewButton->setGeometry(QRect(825, 30, 50, 50));
        shadedViewButton->setChecked(false);
        shadedViewButton->setColor();

        reportBugButton = new QIconButton(QIcon(":/assets/images/icons/bug.png"), 28, centralWidget);
        reportBugButton->setGeometry(QRect(1470, 30, 50, 50));

        closeButton = new QIconButton(QIcon(":/assets/images/icons/close.png"), 28, centralWidget);
        closeButton->setGeometry(QRect(1520, 30, 50, 50));
     
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