#ifndef BOOLFIELD_H
#define BOOLFIELD_H

#include "../../common.h"

class BoolField : public QWidget {
public:
	QHBoxLayout* root;
	QLabel* label;
	QCheckBox* edit;

	BoolField(QString n, bool set, QWidget* parent = nullptr) : QWidget(parent) {
		root = new QHBoxLayout(this);

		label = new QLabel(n);
		label->setStyleSheet(".QLabel {color: white;}");
		edit = new QCheckBox();
		edit->setChecked(set);

		root->addWidget(label);
		root->addWidget(edit);
	}
};

#endif