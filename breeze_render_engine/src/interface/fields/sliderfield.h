#ifndef SLIDERFIELD_H
#define SLIDERFIELD_H

#include "../../common.h"

class SliderField : public QWidget {
public:
	QHBoxLayout* root;
	QLabel* label;
	QSlider* edit;

	SliderField(QString n, int min, int max, int set, QWidget* parent = nullptr) : QWidget(parent) {
		root = new QHBoxLayout(this);

		label = new QLabel(n);
		label->setStyleSheet(".QLabel {color: white;}");
		edit = new QSlider();
		edit->setMaximum(max);
		edit->setMinimum(min);
		edit->setValue(set);
		edit->setOrientation(Qt::Horizontal);

		root->addWidget(label);
		root->addWidget(edit);
	}

	void set(float s) {
		edit->setValue(s);
	}
};

#endif