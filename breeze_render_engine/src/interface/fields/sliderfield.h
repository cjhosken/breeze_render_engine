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
		label->setStyleSheet(".QLabel {color: rgb(100, 100, 100);}");
		edit = new QSlider();
		edit->setMaximum(max);
		edit->setMinimum(min);
		edit->setValue(set);
		edit->setOrientation(Qt::Horizontal);
		edit->setStyleSheet("QSlider::groove::horizontal {background-color: rgb(25, 25, 25); height: 4px; border-radius: 2px;} QSlider::handle::horizontal {background-color: white; border: 2px solid white; width: 10px; height: 10px; line-height: 10px;margin-top: -5px; margin-bottom: -5px;border-radius: 6px;}");

		root->addWidget(label);
		root->addWidget(edit);
	}

	void set(float s) {
		edit->setValue(s);
	}
};

#endif