#include "src/interface/mainwindow.h"
#include <QFontDatabase>

void loadSettings();

int main(int argc, char** argv) {
	QSettings::setDefaultFormat(QSettings::IniFormat);
	QCoreApplication::setApplicationName("Breeze Render Engine");
	QCoreApplication::setOrganizationName("cjhosken");
	QCoreApplication::setOrganizationDomain("cjhosken.io");
	QSettings settings;

	QApplication app(argc, argv);

	QCoreApplication::setApplicationVersion("2022.25.7");
	QCoreApplication::setAttribute(Qt::AA_UseDesktopOpenGL);
	app.setWindowIcon(QIcon(":/assets/images/logo.png"));

	QPixmap pixmap(":/assets/images/splash.png");
	QSplashScreen* splash = new QSplashScreen(pixmap);
	splash->show();
	app.processEvents();

	QSurfaceFormat format;
	format.setSamples(0);
	format.setVersion(3, 3);
	format.setProfile(QSurfaceFormat::CoreProfile);
	format.setSwapBehavior(QSurfaceFormat::DoubleBuffer);
	QSurfaceFormat::setDefaultFormat(format);

	settings.clear();
	loadSettings();

	MainWindow mainWindow = MainWindow();

	QTimer::singleShot(settings.value("app/splashTime").toInt(), splash, SLOT(close()));
	QTimer::singleShot(settings.value("app/splashTime").toInt(), &mainWindow, SLOT(show()));

	return app.exec();
}

void loadSettings() {
	QSettings settings;
	settings.setValue("app/width", 1600);
	settings.setValue("app/height", 900);

	settings.setValue("app/splashTime", 2000);

	settings.setValue("app/borderRadius", 35.0f);

	settings.setValue("color/selected", QColor(168, 74, 214));
	settings.setValue("color/wireDefault", QColor(170, 170, 170));
	settings.setValue("color/viewportGradientInner", QColor(25, 25, 25));;
	settings.setValue("color/viewportGradientOuter", QColor(13, 13, 20));

	QFile File(":/assets/styles/styles.css");
	File.open(QFile::ReadOnly);
	settings.setValue("styles/root", QLatin1String(File.readAll()));
}