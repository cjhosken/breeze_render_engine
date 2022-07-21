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
    
    PropertiesPanel(QWidget* parent = nullptr) : QWidget(parent) {
        QSettings settings;
        setProperty("class", "propertiesPanel");
        setStyleSheet(".QWidget {background-color: transparent;} .propertiesPanel{background-color: rgba(15, 15, 15, 200); border-radius: 20px;}");

        root = new QTabWidget(this);
        root->setStyleSheet(settings.value("styles/root").toString());

        renderTab = new RenderTab();

        worldTab = new WorldTab();

        objectTab = new ObjectTab();

        root->addTab(renderTab, "Render");
        root->addTab(worldTab, "World");
        root->addTab(objectTab, "Object");
    }
};

#endif
