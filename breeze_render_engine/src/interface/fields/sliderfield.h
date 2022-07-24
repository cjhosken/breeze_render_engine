#ifndef SLIDERFIELD_H
#define SLIDERFIELD_H

#include "../../common.h"

class SliderField : public QWidget {
public:
	QHBoxLayout* root;
	QLabel* label;
	QSlider* edit;

	SliderField(QString n, int min, int max, int set, QWidget* parent = nullptr) : QWidget(parent) {
		QSettings settings;
		root = new QHBoxLayout(this);

		label = new QLabel(n);
		label->setProperty("class", "label");
		label->setStyleSheet(settings.value("styles/root").toString());
		edit = new QSlider();
		edit->setMaximum(max);
		edit->setMinimum(min);
		edit->setValue(set);
		edit->setOrientation(Qt::Horizontal);
		edit->setProperty("class", "slider");
		edit->setStyleSheet(settings.value("styles/root").toString());

		root->addWidget(label);
		root->addWidget(edit);
	}

	void set(float s) {
		edit->setValue(s);
	}
};

#endif