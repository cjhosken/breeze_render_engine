#ifndef QICONBUTTON_H
#define QICONBUTTON_H

#include "../../common.h"

class QIconButton : public QPushButton {

public:
	QIconButton(QIcon icon, int size, QWidget* parent = nullptr) : QPushButton(parent) {
		QSettings settings;
		setIcon(icon);
		setIconSize(QSize(size, size));

		setProperty("class", "iconButton");
		setStyleSheet(settings.value("styles/root").toString());
	}
};


#endif

