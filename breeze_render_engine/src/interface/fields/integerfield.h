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
		QSettings settings;
		validator = new QIntValidator(min, max, this);
		root = new QHBoxLayout(this);

		label = new QLabel(n);
		label->setProperty("class", "label");
		label->setStyleSheet(settings.value("styles/root").toString());
		edit = new QLineEdit();
		edit->setAutoFillBackground(true);

		edit->setValidator(validator);
		edit->setText(QString::number(mid));
		edit->setAlignment(Qt::AlignCenter);

		edit->setProperty("class", "lineEdit");
		edit->setStyleSheet(settings.value("styles/root").toString());

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