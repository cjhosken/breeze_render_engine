#include "src/interface/mainwindow.h"

#include <QTTest/QTest>

int main(int argc, char** argv) {
	QApplication app(argc, argv);

	QCoreApplication::setApplicationName("Breeze Render Engine");
	QCoreApplication::setOrganizationName("cjhosken");
	QCoreApplication::setApplicationVersion("2022.6.7");
	app.setWindowIcon(QIcon("assets/images/logo.png"));

	QPixmap pixmap("assets/images/splash.png");
	QSplashScreen* splash = new QSplashScreen(pixmap);
	splash->show();
	app.processEvents();

	QSurfaceFormat format;
	format.setSamples(16);
	format.setVersion(4, 5);
	format.setProfile(QSurfaceFormat::CoreProfile);
	QSurfaceFormat::setDefaultFormat(format);

	ApplicationSettings settings = ApplicationSettings();

	MainWindow mainWindow = MainWindow(settings);

	QTimer::singleShot(settings.splashTime, splash, SLOT(close()));
	QTimer::singleShot(settings.splashTime, &mainWindow, SLOT(show()));

	return app.exec();
}