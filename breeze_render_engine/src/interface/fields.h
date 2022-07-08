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
	QLineEdit* xEdit;
	QLineEdit* yEdit;
	QLineEdit* zEdit;

	ColorField(QString n, QWidget* parent = nullptr) : QWidget(parent) {
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