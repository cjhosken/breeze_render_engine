#ifndef TABS_H
#define TABS_H

#include "../common.h"

class RenderTab : public QWidget {
public:
    RenderTab(QWidget* parent = nullptr) : QWidget(parent) {
        QLabel* name = new QLabel("Name:");
        QLineEdit* nameedit = new QLineEdit();
        QLabel* age = new QLabel("Age:");
        QLineEdit* ageedit = new QLineEdit();
        QLabel* nation = new QLabel("Nation:");
        QLineEdit* nationedit = new QLineEdit();

        QVBoxLayout* vbox = new QVBoxLayout();
        vbox->addWidget(name);
        vbox->addWidget(nameedit);
        vbox->addWidget(age);
        vbox->addWidget(ageedit);
        vbox->addWidget(nation);
        vbox->addWidget(nationedit);
        vbox->addStretch();

        setLayout(vbox);
    }
};

class WorldTab : public QWidget {
public:
    WorldTab(QWidget* parent = nullptr) : QWidget(parent) {
        QLabel* name = new QLabel("Name:");
        QLineEdit* nameedit = new QLineEdit();
        QLabel* age = new QLabel("Age:");
        QLineEdit* ageedit = new QLineEdit();
        QLabel* nation = new QLabel("Nation:");
        QLineEdit* nationedit = new QLineEdit();

        QVBoxLayout* vbox = new QVBoxLayout();
        vbox->addWidget(name);
        vbox->addWidget(nameedit);
        vbox->addWidget(age);
        vbox->addWidget(ageedit);
        vbox->addWidget(nation);
        vbox->addWidget(nationedit);
        vbox->addStretch();

        setLayout(vbox);
    }
};

class ObjectTab : public QWidget {
public:
    ObjectTab(QWidget* parent = nullptr) : QWidget(parent) {
        QLabel* name = new QLabel("Name:");
        QLineEdit* nameedit = new QLineEdit();
        QLabel* age = new QLabel("Age:");
        QLineEdit* ageedit = new QLineEdit();
        QLabel* nation = new QLabel("Nation:");
        QLineEdit* nationedit = new QLineEdit();

        QVBoxLayout* vbox = new QVBoxLayout();
        vbox->addWidget(name);
        vbox->addWidget(nameedit);
        vbox->addWidget(age);
        vbox->addWidget(ageedit);
        vbox->addWidget(nation);
        vbox->addWidget(nationedit);
        vbox->addStretch();

        setLayout(vbox);
    }
};

#endif