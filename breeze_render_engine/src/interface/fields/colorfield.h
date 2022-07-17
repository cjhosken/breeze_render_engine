#ifndef COLORFIELD_H
#define COLORFIELD_H

#include "../../common.h"

class ColorField : public QWidget {
public:
	QHBoxLayout* root;
	QLabel* label;
	QPushButton* edit;
	QColorDialog* popup;

	ColorField(QString n, QWidget* parent = nullptr) : QWidget(parent) {
		popup = new QColorDialog();
		root = new QHBoxLayout(this);

		label = new QLabel(n);
		label->setStyleSheet(".QLabel {color: white;}");
		edit = new QPushButton();
		connect(edit, &QPushButton::clicked, this, &ColorField::openDialog);

		root->addWidget(label);
		root->addWidget(edit);
	}

	void fromQVector3D(QVector3D vec) {
		QColor color(vec.x() * 255.0f, vec.y() * 255.0f, vec.z() * 255.0f);
		popup->setCurrentColor(color);
	}

public slots:
	void openDialog() {
		popup->show();
	}
};


#endif