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
		label->setStyleSheet(".QLabel {color: rgb(100, 100, 100);}");
		edit = new QLineEdit();



		edit->setValidator(validator);
		edit->setText(QString::number(mid));
		edit->setAlignment(Qt::AlignCenter);


		edit->setStyleSheet("QLineEdit{background-color: transparent; color: white; border: none; border-radius: 5px; text-align:center;}");

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