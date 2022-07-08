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
        setProperty("class", "PropertiesPanel");
        setStyleSheet(".QWidget {background-color: transparent;} .PropertiesPanel{background-color: rgba(15, 15, 15, 200); border-radius: 20px;}");

        root = new QTabWidget(this);
        root->setStyleSheet(".QTabWidget::tab-bar {alignment: center;} QTabWidget::pane{ border: none; } QTabBar::tab { background-color: transparent; color: white;} ");
        renderTab = new RenderTab();
        worldTab = new WorldTab();
        objectTab = new ObjectTab();
        root->addTab(renderTab, "Rendering");
        root->addTab(worldTab, "World");
        root->addTab(objectTab, "Object");
    }
};

#endif
