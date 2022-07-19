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
		QSettings settings;
		popup = new QColorDialog();
		root = new QHBoxLayout(this);

		label = new QLabel(n);
		label->setProperty("class", "label");
		label->setStyleSheet(settings.value("styles/root").toString());

		edit = new QPushButton();
		edit->setProperty("class", "colorButton");
		edit->setStyleSheet(settings.value("styles/root").toString());

		connect(edit, &QPushButton::clicked, this, &ColorField::openDialog);
		connect(popup, &QColorDialog::currentColorChanged, this, &ColorField::changeColor);
		connect(popup, &QColorDialog::colorSelected, this, &ColorField::changeColor);

		root->addWidget(label);
		root->addWidget(edit);
	}

private:
	QString colorToString() {
		QColor color = popup->currentColor();
		return "rgb(" + QString::number(color.red()) + ", " + QString::number(color.green()) + ", " + QString::number(color.blue()) + ")";
	}

public slots:
	void openDialog() {
		popup->show();
	}

	void changeColor() {
		edit->setStyleSheet(".colorButton{background-color: " + colorToString() + ";}");
		repaint();
	}
};


#endif