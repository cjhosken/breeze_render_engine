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
		QSettings settings;
		validator = new QDoubleValidator(double(min), double(max), 3, this);
		root = new QHBoxLayout(this);

		edit = new QLineEdit();
		edit->setValidator(validator);

		edit->setProperty("class", "textEdit");
		edit->setStyleSheet(settings.value("styles/root").toString());

		edit->setText(QString::number(mid));
		edit->setAlignment(Qt::AlignCenter);

		root->addWidget(edit);
	}

	FloatField(QString n, float min, float max, float mid, QWidget* parent = nullptr) : QWidget(parent) {
		QSettings settings;
		validator = new QDoubleValidator(double(min), double(max), 3, this);
		root = new QHBoxLayout(this);

		label = new QLabel(n);
		label->setProperty("class", "label");
		label->setStyleSheet(settings.value("styles/root").toString());
		edit = new QLineEdit();
		edit->setValidator(validator);

		edit->setProperty("class", "lineEdit");
		edit->setStyleSheet(settings.value("styles/root").toString());
		edit->setPalette(QColor(255, 0, 0));

		edit->setText(QString::number(mid));
		edit->setAlignment(Qt::AlignCenter);

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