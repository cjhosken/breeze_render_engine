#ifndef BOOLFIELD_H
#define BOOLFIELD_H

#include "../../common.h"

class BoolField : public QWidget {
public:
	QHBoxLayout* root;
	QLabel* label;
	QCheckBox* edit;

	BoolField(QString n, bool set, QWidget* parent = nullptr) : QWidget(parent) {
		QSettings settings;
		root = new QHBoxLayout(this);

		label = new QLabel(n);
		label->setProperty("class", "label");
		label->setStyleSheet(settings.value("styles/root").toString());
		edit = new QCheckBox();
		edit->setChecked(set);

		root->addWidget(label);
		root->addWidget(edit);
	}
};

#endif