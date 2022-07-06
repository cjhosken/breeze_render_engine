#ifndef WINDOW_H
#define WINDOW_H

#include "../common.h"
#include "applicationsettings.h"
#include "ui_mainwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui {
	class Window;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
	Q_OBJECT
public:
	ApplicationSettings settings;

	MainWindow(ApplicationSettings &set) : QMainWindow(), ui(new Ui::Window) {
		settings = set;
		ui->setupUi(this);
		installEventFilter(this);

		float radius = 35.0f;

		QPainterPath path;
		path.addRoundedRect(QRect(0, 0, settings.APP_WIDTH, settings.APP_HEIGHT), radius, radius);
		QRegion mask = QRegion(path.toFillPolygon().toPolygon());
		setMask(mask);

	}
	~MainWindow() {
		delete ui;
	};

	bool eventFilter(QObject* target, QEvent* ev)
	{
		if (ev->type() == QEvent::KeyPress)
		{
			QKeyEvent* keyEvent = static_cast<QKeyEvent*>(ev);

			if (keyEvent->key() == Qt::Key_Escape)
			{
				this->close();
				return QMainWindow::eventFilter(target, ev);
			}
		}
		return QMainWindow::eventFilter(target, ev);
	}

private:
	Ui::Window* ui;
	QString currentFile;
};

#endif // !WINDOW_H