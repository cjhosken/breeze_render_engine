#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include "../common.h"
#include "glwidget.h"

#include "dragbar.h"
#include "propertiespanel.h"

#include "widgets/qiconbutton.h"
#include "widgets/qtoggleiconbutton.h"

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
    QIconButton* addOBJButton;
    QIconButton* addLightButton;
    QIconButton* addExtrasButton;

    QIconButton* docsButton;
    QIconButton* codeButton;

    QIconButton* wireViewButton;
    QIconButton* solidViewButton;
    QIconButton* shadedViewButton;

    QIconButton* reportBugButton;
    QIconButton* closeButton;

    QMenu* extraButtonsMenu;

    QAction* addCircle;
    QAction* addTriangle;
    QAction* addCylinder;
    QAction* addMonkey;
    QAction* addTeapot;


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
        appButtons->setGeometry(QRect(23, 21, 50, 50));
        appButtons->setStyleSheet(settings.value("styles/root").toString());

        appButtonsMenu = new QMenu();
        appButtonsMenu->setStyleSheet(".QMenu{background-color: rgba(15, 15, 15, 200); border-radius: 15px; color: white;}");
        appQuitButton = new QAction("Quit");
        appButtonsMenu->addAction(appQuitButton);
        appButtons->setMenu(appButtonsMenu);

        toolBar = new QWidget(centralWidget);
        toolBar->setGeometry(QRect(23, 105, 50, 350));
        toolBar->setStyleSheet(".QWidget{background-color: rgba(15, 15, 15, 200); border-radius: 20px;}");

        toggleObjectSelectionButton = new QToggleIconButton(QIcon(":/assets/images/icons/cursor.png"), 28, toolBar);
        toggleObjectSelectionButton->setGeometry(QRect(0, 0, 50, 50));
        toggleObjectSelectionButton->setProperty("class", "largeIconButton toggleIconButton");
        toggleObjectSelectionButton->setStyleSheet(settings.value("styles/root").toString());

        addCubeButton = new QIconButton(QIcon(":/assets/images/icons/cube.png"), 28, toolBar);
        addCubeButton->setGeometry(QRect(0, 50, 50, 50));
        addCubeButton->setProperty("class", "largeIconButton");
        addCubeButton->setStyleSheet(settings.value("styles/root").toString());

        addPlaneButton = new QIconButton(QIcon(":/assets/images/icons/plane.png"), 28, toolBar);
        addPlaneButton->setGeometry(QRect(0, 100, 50, 50));
        addPlaneButton->setProperty("class", "largeIconButton");
        addPlaneButton->setStyleSheet(settings.value("styles/root").toString());

        addSphereButton = new QIconButton(QIcon(":/assets/images/icons/sphere.png"), 28, toolBar);
        addSphereButton->setGeometry(QRect(0, 150, 50, 50));
        addSphereButton->setProperty("class", "largeIconButton");
        addSphereButton->setStyleSheet(settings.value("styles/root").toString());

        addOBJButton = new QIconButton(QIcon(":/assets/images/icons/add.png"), 28, toolBar);
        addOBJButton->setGeometry(QRect(0, 200, 50, 50));
        addOBJButton->setProperty("class", "largeIconButton");
        addOBJButton->setStyleSheet(settings.value("styles/root").toString());

        addLightButton = new QIconButton(QIcon(":/assets/images/icons/light.png"), 28, toolBar);
        addLightButton->setGeometry(QRect(0, 250, 50, 50));
        addLightButton->setProperty("class", "largeIconButton");
        addLightButton->setStyleSheet(settings.value("styles/root").toString());

        addExtrasButton = new QIconButton(QIcon(":/assets/images/icons/more.png"), 28, toolBar);
        addExtrasButton->setGeometry(QRect(0, 300, 50, 50));
        addExtrasButton->setProperty("class", "largeIconButton");
        addExtrasButton->setStyleSheet(settings.value("styles/root").toString());

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


        docsButton = new QIconButton(QIcon(":/assets/images/icons/info.png"), 28, debugBar);
        docsButton->setGeometry(QRect(0, 0, 50, 50));
        docsButton->setProperty("class", " topRoundedIconButton");
        docsButton->setStyleSheet(settings.value("styles/root").toString());

        codeButton = new QIconButton(QIcon(":/assets/images/icons/code.png"), 28, debugBar);
        codeButton->setGeometry(QRect(0, 50, 50, 50));
        codeButton->setProperty("class", "bottomRoundedIconButton");
        codeButton->setStyleSheet(settings.value("styles/root").toString());

        wireViewButton = new QIconButton(QIcon(":/assets/images/icons/wire.png"), 26, centralWidget);
        wireViewButton->setGeometry(QRect(738, 30, 35, 35));
        wireViewButton->setProperty("class", "smallIconButton");
        wireViewButton->setStyleSheet(settings.value("styles/root").toString());

        solidViewButton = new QIconButton(QIcon(":/assets/images/icons/solid.png"), 26, centralWidget);
        solidViewButton->setGeometry(QRect(783, 30, 35, 35));
        solidViewButton->setProperty("class", "smallIconButton");
        solidViewButton->setStyleSheet(settings.value("styles/root").toString());

        shadedViewButton = new QIconButton(QIcon(":/assets/images/icons/shaded.png"), 26, centralWidget);
        shadedViewButton->setGeometry(QRect(828, 30, 35, 35));
        shadedViewButton->setProperty("class", "smallIconButton");
        shadedViewButton->setStyleSheet(settings.value("styles/root").toString());

        reportBugButton = new QIconButton(QIcon(":/assets/images/icons/bug.png"), 26, centralWidget);
        reportBugButton->setGeometry(QRect(1480, 30, 35, 35));
        reportBugButton->setProperty("class", "greyIconButton smallIconButton");
        reportBugButton->setStyleSheet(settings.value("styles/root").toString());

        closeButton = new QIconButton(QIcon(":/assets/images/icons/close.png"), 26, centralWidget);
        closeButton->setGeometry(QRect(1520, 30, 35, 35));
        closeButton->setProperty("class", "greyIconButton smallIconButton");
        closeButton->setStyleSheet(settings.value("styles/root").toString());
     

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