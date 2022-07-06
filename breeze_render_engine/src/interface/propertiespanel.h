#ifndef PROPERTIESPANEL_H
#define PROPERTIESPANEL_H

#include "../common.h"
#include "tabs.h"

class PropertiesPanel : public QTabWidget {
public:
    RenderTab* renderTab;
    WorldTab* worldTab;
    ObjectTab* objectTab;

    PropertiesPanel(QWidget* parent = nullptr) : QTabWidget(parent) {
        renderTab = new RenderTab();
        worldTab = new WorldTab();
        objectTab = new ObjectTab();
        addTab(renderTab, "Rendering");
        addTab(worldTab, "World");
        addTab(objectTab, "Object");
    }
};

#endif
