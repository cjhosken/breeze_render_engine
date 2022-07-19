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
		label->setStyleSheet(".QLabel {color: rgb(100, 100, 100);}");
		edit = new QPushButton();
		connect(edit, &QPushButton::clicked, this, &ColorField::openDialog);
		connect(popup, &QColorDialog::currentColorChanged, this, &ColorField::changeColor);
		connect(popup, &QColorDialog::colorSelected, this, &ColorField::changeColor);

		root->addWidget(label);
		root->addWidget(edit);
	}

	void fromQVector3D(QVector3D vec) {
		QColor color(vec.x() * 255.0f, vec.y() * 255.0f, vec.z() * 255.0f);
		popup->setCurrentColor(color);
	}

	QString colorToString() {
		QColor color = popup->currentColor();

		QString out = "rgb(" + QString::number(color.red()) + ", " + QString::number(color.green()) + ", " + QString::number(color.blue()) + ")";
		return out;
	}

public slots:
	void openDialog() {
		popup->show();
	}

	void changeColor() {
		edit->setStyleSheet("QPushButton{background-color: " + colorToString() + "; border: 1px outset rgb(50, 50, 50); border-radius: 2px;}");
		repaint();
	}
};


#endif