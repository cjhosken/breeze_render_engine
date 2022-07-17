#ifndef QVECTOR3DFIELD_H
#define QVECTOR3DFIELD_H

#include "../../common.h"
#include "floatfield.h"

class QVector3DField : public QWidget {
	Q_OBJECT
public:
	QHBoxLayout* root;
	QLabel* label;
	FloatField* xEdit;
	FloatField* yEdit;
	FloatField* zEdit;

	QVector3DField(QString n, QWidget* parent = nullptr) : QWidget(parent) {
		root = new QHBoxLayout(this);

		label = new QLabel(n);
		label->setStyleSheet(".QLabel {color: white;}");
		xEdit = new FloatField(-INFINITY, INFINITY, 0);
		yEdit = new FloatField(-INFINITY, INFINITY, 0);
		zEdit = new FloatField(-INFINITY, INFINITY, 0);

		connect(xEdit->edit, &QLineEdit::textEdited, this, &QVector3DField::fieldChanged);
		connect(yEdit->edit, &QLineEdit::textEdited, this, &QVector3DField::fieldChanged);
		connect(zEdit->edit, &QLineEdit::textEdited, this, &QVector3DField::fieldChanged);

		root->addWidget(label);
		root->addWidget(xEdit);
		root->addWidget(yEdit);
		root->addWidget(zEdit);
	}

	void fromQVector3D(QVector3D vec) {
		xEdit->set(vec.x());
		yEdit->set(vec.y());
		zEdit->set(vec.z());
	}

signals:
	void edited(QVector3D out);

public slots:
	void fieldChanged() {
		QVector3D out(xEdit->get(), yEdit->get(), zEdit->get());

		emit edited(out);
	}
};

#endif