#include <QApplication>
#include <QSurfaceFormat>
#include <QIcon>

#include "src/window.h"

int main(int argc, char** argv) {
	QApplication app(argc, argv);

	QCoreApplication::setApplicationName("Breeze Render Engine");
	QCoreApplication::setOrganizationName("cjhosken");
	QCoreApplication::setApplicationVersion("2022.3.7");
	app.setWindowIcon(QIcon("assets/images/logo.png"));

	QSurfaceFormat format;
	format.setSamples(16);
	format.setVersion(4, 5);
	format.setProfile(QSurfaceFormat::CoreProfile);
	QSurfaceFormat::setDefaultFormat(format);

	Window window = Window();
	window.layout()->setSizeConstraint(QLayout::SetFixedSize);
	window.setAttribute(Qt::WA_TranslucentBackground);
	window.setAttribute(Qt::WA_NoSystemBackground, false);
	window.show();

	return app.exec();
}