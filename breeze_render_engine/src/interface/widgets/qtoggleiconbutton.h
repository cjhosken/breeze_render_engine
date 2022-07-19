#ifndef QTOGGLEICONBUTTON_H
#define QTOGGLEICONBUTTON_H

#include "../../common.h"

class QToggleIconButton : public QPushButton {

public:
	QToggleIconButton(QIcon icon, int size, QWidget* parent = nullptr) : QPushButton(parent) {
		setIcon(icon);
		setIconSize(QSize(size, size));

		setProperty("class", "iconToggleButton");
		setCheckable(true);
	}


};


#endif

