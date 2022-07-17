#ifndef INTEGERFIELD_H
#define INTEGERFIELD_H

#include "../../common.h"

class IntegerField : public QWidget {
public:
	QHBoxLayout* root;
	QLabel* label;
	QLineEdit* edit;
	QValidator* validator;

	IntegerField(QString n, int min, int max, int mid, QWidget* parent = nullptr) : QWidget(parent) {
		validator = new QIntValidator(min, max, this);
		root = new QHBoxLayout(this);

		label = new QLabel(n);
		label->setStyleSheet(".QLabel {color: white;}");
		edit = new QLineEdit();

		edit->setValidator(validator);
		edit->setText(QString::number(mid));

		root->addWidget(label);
		root->addWidget(edit);
	}

	void set(int i) {
		edit->setText(QString::number(i));
	}

	int get() {
		return edit->text().toInt();
	}
};

#endif