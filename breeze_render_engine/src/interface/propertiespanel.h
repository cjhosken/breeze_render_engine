#ifndef PROPERTIESPANEL_H
#define PROPERTIESPANEL_H

#include "../common.h"
#include "tabs.h"

class PropertiesPanel : public QWidget {
public:
    QTabWidget* root;
    RenderTab* renderTab;
    WorldTab* worldTab;
    ObjectTab* objectTab;
    CameraTab* cameraTab;
    
    PropertiesPanel(QWidget* parent = nullptr) : QWidget(parent) {
        QSettings settings;
        setProperty("class", "propertiesPanel");
        setStyleSheet(settings.value("styles/root").toString());

        root = new QTabWidget(this);

        renderTab = new RenderTab();
        worldTab = new WorldTab();

        root->addTab(renderTab, "Render");
        root->addTab(worldTab, "World");
    }
};

#endif
