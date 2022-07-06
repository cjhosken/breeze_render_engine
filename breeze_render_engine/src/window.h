#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>
#include <QVBoxLayout>
#include <QStackedWidget>
#include <QHBoxLayout>

#include <QKeyEvent>
#include <QMouseEvent>

#include <QPushButton>

#include "glwidget.h"
#include "interface/dragbar.h"

class Window : public QWidget {
	Q_OBJECT
public:
	GLWidget* glWidget;

	Window() {
		setMouseTracking(true);
		glWidget = new GLWidget();
		QStackedWidget* stackedWidget = new QStackedWidget;
		stackedWidget->addWidget(glWidget);

		QVBoxLayout* root = new QVBoxLayout;
		root->addWidget(stackedWidget);

		root->setContentsMargins(0, 0, 0, 0);
		setLayout(root);
		setContentsMargins(0, 0, 0, 0);

		setWindowFlag(Qt::FramelessWindowHint);
		resize(APP_WIDTH, APP_HEIGHT);
	}

protected:
	void keyPressEvent(QKeyEvent* ev) {
		if (ev->key() == Qt::Key_Escape) {
			close();
		}
		else if (ev->key() == Qt::Key_R)
			glWidget->render();
		else
			QWidget:keyPressEvent(ev);
	}

	void mouseMoveEvent(QMouseEvent* ev) {
		float xPos = static_cast<float>(ev->pos().x());
		float yPos = static_cast<float>(ev->pos().y());

		qDebug() << yPos;

		lastX = xPos;
		lastY = yPos;

		QWidget::mouseMoveEvent(ev);
	}
private:
	float lastX;
	float lastY;

	bool firstMouse;

};

#endif // !WINDOW_H