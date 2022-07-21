#ifndef QTOGGLEICONBUTTON_H
#define QTOGGLEICONBUTTON_H

#include "../../common.h"

class QToggleIconButton : public QPushButton {

public:
	QIcon defaultIcon;
	QIcon selectedIcon;

	QToggleIconButton(QIcon icon, int size, QWidget* parent = nullptr) : QPushButton(parent) {
		QSettings settings;

		QPixmap pixmap = icon.pixmap(72, 72, QIcon::Normal, QIcon::On);
		QBitmap mask = pixmap.createMaskFromColor(QColor(255, 255, 255), Qt::MaskOutColor);
		pixmap.fill(settings.value("color/selected").value<QColor>());
		pixmap.setMask(mask);
		selectedIcon = QIcon(pixmap);
		defaultIcon = icon;

		setIcon(defaultIcon);

		setIconSize(QSize(size, size));

		setProperty("class", "iconButton");
		setStyleSheet(settings.value("styles/root").toString());
		setCheckable(true);

		connect(this, &QPushButton::clicked, this, &QToggleIconButton::setColor);
	}

public slots:
	void setColor() {
		if (isChecked()) {
			setIcon(selectedIcon);
		}
		else {
			setIcon(defaultIcon);
		}
	}
};


#endif

