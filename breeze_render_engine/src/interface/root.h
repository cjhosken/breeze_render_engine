#ifndef ROOT_H
#define ROOT_H

#include "../common.h"
#include <QPainterPath>

class Root : public QWidget {
public:
	Root(QWidget* parent = nullptr) : QWidget(parent) {
		setAttribute(Qt::WA_TranslucentBackground);
		const int radius = 50;
	}
};

#endif