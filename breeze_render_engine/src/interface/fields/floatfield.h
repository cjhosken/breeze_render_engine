#ifndef FLOATFIELD_H
#define FLOATFIELD_H

#include "../../common.h"

class FloatField : public QWidget {
public:
	QHBoxLayout* root;
	QLabel* label;
	QLineEdit* edit;
	QValidator* validator;

	FloatField(float min, float max, float mid, QWidget* parent = nullptr) : QWidget(parent) {
		validator = new QDoubleValidator(double(min), double(max), 3, this);
		root = new QHBoxLayout(this);

		edit = new QLineEdit();
		edit->setValidator(validator);

		edit->setText(QString::number(mid));

		root->addWidget(edit);
		root->setAlignment(Qt::AlignCenter);
	}

	FloatField(QString n, float min, float max, float mid, QWidget* parent = nullptr) : QWidget(parent) {
		validator = new QDoubleValidator(double(min), double(max), 3, this);
		root = new QHBoxLayout(this);

		label = new QLabel(n);
		label->setStyleSheet(".QLabel {color: rgb(100, 100, 100);}");
		edit = new QLineEdit();
		edit->setValidator(validator);

		edit->setText(QString::number(mid));

		root->addWidget(label);
		root->addWidget(edit);
	}

	void set(float f) {
		edit->setText(QString::number(f));
	}

	float get() {
		return edit->text().toFloat();
	}
};

#endif