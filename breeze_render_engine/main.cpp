#include "src/interface/mainwindow.h"
#include <QFontDatabase>
#include <QSystemTrayIcon>

void loadSettings();

int main(int argc, char** argv) {;
	QCoreApplication::setApplicationName("Breeze Render Engine");
	QCoreApplication::setApplicationVersion("2022.13.8");
	QCoreApplication::setOrganizationName("cjhosken");
	QCoreApplication::setOrganizationDomain("cjhosken.io");
	QSettings settings;

	QSettings::setDefaultFormat(QSettings::IniFormat);
	QCoreApplication::setAttribute(Qt::AA_UseDesktopOpenGL);

	QApplication app(argc, argv);
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
	mainWindow.setWindowIcon(QIcon(":/assets/images/logo.png"));

	QTimer::singleShot(settings.value("app/splashTime").toInt(), splash, SLOT(close()));
	QTimer::singleShot(settings.value("app/splashTime").toInt(), &mainWindow, SLOT(show()));

	qDebug() << "    ____   ____   ______ ______ _____    ______";
	qDebug() << "   / __ ) / __ | / ____// ____//__  /   / ____/";
	qDebug() << "  / __  |/ /_/ // __/  / __/     / /   / __/";
	qDebug() << " / /_/ // _, _// /___ / /___    / /__ / /___";
	qDebug() << "/ _____//_/ |_|/_____//_____/   /____//_____/";

	qDebug() << "    ____   ______ _   __ ____   ______ ____";
	qDebug() << "   / __ | / ____// | / // __ | / ____// __ |";
	qDebug() << "  / /_/ // __/  /  |/ // / / // __/  / /_/ /";
	qDebug() << " / _, _// /___ / /|  // /_/ // /___ / _, _/";
	qDebug() << "/ _/ |_|/_____//_/ |_//_____//_____//_/ |_|";

	qDebug() << "    ______ _   __ ______ ____ _   __ ______";
	qDebug() << "   / ____// | / // ____//  _// | / // ____/";
	qDebug() << "  / __/  /  |/ // / __  / / /  |/ // __/";
	qDebug() << " / /___ / /|  // /_/ /_/ / / /|  // /___";
	qDebug() << "/ _____//_/ |_/ |____//___//_/ |_//_____/";

	
	qDebug() << "\nBy Christopher Hosken | Version 1.0.0 (Aug 13, 2022)";

	return app.exec();
}

void loadSettings() {
	QSettings settings;
	settings.setValue("app/width", 1600);
	settings.setValue("app/height", 900);
	settings.setValue("app/log", false);

	settings.setValue("app/splashTime", 12000);

	settings.setValue("app/borderRadius", 35.0f);

	settings.setValue("color/selected", QColor(168, 74, 214));
	settings.setValue("color/wireDefault", QColor(170, 170, 170));
	settings.setValue("color/viewportGradientInner", QColor(25, 25, 25));;
	settings.setValue("color/viewportGradientOuter", QColor(13, 13, 20));

	settings.setValue("render/width", 160);
	settings.setValue("render/height", 120);

	settings.setValue("render/samples", 16);
	settings.setValue("render/bounces", 4);

	settings.setValue("render/fov", 50);

	settings.setValue("view/fov", 35);

	QFile File(":/assets/styles/styles.css");
	File.open(QFile::ReadOnly);
	settings.setValue("styles/root", QLatin1String(File.readAll()));
}