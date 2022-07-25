#ifndef QVECTOR3DFIELD_H
#define QVECTOR3DFIELD_H

#include "../../common.h"
#include "floatfield.h"

class QVector3DField : public QWidget {
	Q_OBJECT
public:
	QHBoxLayout* root;
	QLabel* label;
	QLineEdit* xEdit;
	QLineEdit* yEdit;
	QLineEdit* zEdit;
	QValidator* validator;

	QVector3DField(QString n, float min, float max, float mid, QWidget* parent = nullptr) : QWidget(parent) {
		QSettings settings;
		validator = new QDoubleValidator(double(min), double(max), 3, this);
		root = new QHBoxLayout(this);

		label = new QLabel(n);
		label->setProperty("class", "label");
		label->setStyleSheet(settings.value("styles/root").toString());

		xEdit = new QLineEdit();
		xEdit->setValidator(validator);
		xEdit->setProperty("class", "lineEdit");
		xEdit->setStyleSheet(settings.value("styles/root").toString());
		xEdit->setText(QString::number(mid));
		xEdit->setAlignment(Qt::AlignCenter);

		yEdit = new QLineEdit();
		yEdit->setValidator(validator);
		yEdit->setProperty("class", "lineEdit");
		yEdit->setStyleSheet(settings.value("styles/root").toString());
		yEdit->setText(QString::number(mid));
		yEdit->setAlignment(Qt::AlignCenter);

		zEdit = new QLineEdit();
		zEdit->setValidator(validator);
		zEdit->setProperty("class", "lineEdit");
		zEdit->setStyleSheet(settings.value("styles/root").toString());
		zEdit->setText(QString::number(mid));
		zEdit->setAlignment(Qt::AlignCenter);

		connect(xEdit, &QLineEdit::textEdited, this, &QVector3DField::fieldChanged);
		connect(yEdit, &QLineEdit::textEdited, this, &QVector3DField::fieldChanged);
		connect(zEdit, &QLineEdit::textEdited, this, &QVector3DField::fieldChanged);

		root->addWidget(label);
		root->addWidget(xEdit);
		root->addWidget(yEdit);
		root->addWidget(zEdit);
	}

	void fromQVector3D(QVector3D vec) {
		xEdit->setText(QString::number(vec.x()));
		yEdit->setText(QString::number(vec.y()));
		zEdit->setText(QString::number(vec.z()));
	}

signals:
	void edited(QVector3D out);

public slots:
	void fieldChanged() {
		QVector3D out(xEdit->text().toFloat(), yEdit->text().toFloat(), zEdit->text().toFloat());

		emit edited(out);
	}
};

#endif