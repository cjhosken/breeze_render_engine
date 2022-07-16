#ifndef FIELDS_H
#define FIELDS_H

#include "../common.h"

class QVector3DField : public QWidget {
public:
	QVector3D data;
	QHBoxLayout* root;
	QLabel* label;
	QLineEdit* xEdit;
	QLineEdit* yEdit;
	QLineEdit* zEdit;

	QVector3DField(QString n, QWidget* parent = nullptr) : QWidget(parent) {
		root = new QHBoxLayout(this);

		label = new QLabel(n);
		label->setStyleSheet(".QLabel {color: white;}");
		xEdit = new QLineEdit();
		yEdit = new QLineEdit();
		zEdit = new QLineEdit();

		root->addWidget(label);
		root->addWidget(xEdit);
		root->addWidget(yEdit);
		root->addWidget(zEdit);
	}
};

class ColorField : public QWidget {
public:
	QVector3D data;
	QHBoxLayout* root;
	QLabel* label;
	QPushButton* edit;
	QColorDialog* popup;

	ColorField(QString n, QWidget* parent = nullptr) : QWidget(parent) {
		root = new QHBoxLayout(this);

		label = new QLabel(n);
		label->setStyleSheet(".QLabel {color: white;}");
		edit = new QPushButton();
		connect(edit, SIGNAL(triggered()), this, SLOT(openDialog()));

		root->addWidget(label);
		root->addWidget(edit);
	}

public slots:
	void openDialog() {
		popup = new QColorDialog();
		popup->open();
	}
};


class IntegerField : public QWidget {
public:
	QHBoxLayout* root;
	QLabel* label;
	QLineEdit* edit;

	IntegerField(QString n, QWidget* parent = nullptr) : QWidget(parent) {
		root = new QHBoxLayout(this);
		
		label = new QLabel(n);
		label->setStyleSheet(".QLabel {color: white;}");
		edit = new QLineEdit();

		root->addWidget(label);
		root->addWidget(edit);
	}
};

class FloatField : public QWidget {
public:
	QHBoxLayout* root;
	QLabel* label;
	QLineEdit* edit;

	FloatField(QString n, QWidget* parent = nullptr) : QWidget(parent) {
		root = new QHBoxLayout(this);

		label = new QLabel(n);
		label->setStyleSheet(".QLabel {color: white;}");
		edit = new QLineEdit();

		root->addWidget(label);
		root->addWidget(edit);
	}
};

class SliderField : public QWidget {
public:
	QHBoxLayout* root;
	QLabel*label;
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
};

class BoolField : public QWidget {
public:
	QHBoxLayout* root;
	QLabel* label;
	QCheckBox* edit;

	BoolField(QString n, QWidget* parent = nullptr) : QWidget(parent) {
		root = new QHBoxLayout(this);

		label = new QLabel(n);
		label->setStyleSheet(".QLabel {color: white;}");
		edit = new QCheckBox();

		root->addWidget(label);
		root->addWidget(edit);
	}
};





#endif 