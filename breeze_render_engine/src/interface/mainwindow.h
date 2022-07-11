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

		connect(ui->appButton, SIGNAL(clicked()), this, SLOT(onLogoMenuButtonClick()));

		connect(ui->toggleObjectSelectionButton, SIGNAL(clicked()), this, SLOT(onToggleSelectButtonClick()));
		connect(ui->addCubeButton, SIGNAL(clicked()), this, SLOT(onAddCubeButtonClick()));
		connect(ui->addPlaneButton, SIGNAL(clicked()), this, SLOT(onAddPlaneButtonClick()));
		connect(ui->addSphereButton, SIGNAL(clicked()), this, SLOT(onAddSphereButtonClick()));
		connect(ui->addOBJButton, SIGNAL(clicked()), this, SLOT(onAddOBJButtonClick()));
		connect(ui->addLightButton, SIGNAL(clicked()), this, SLOT(onAddLightButtonClick()));
		// Extra Buttons
		connect(ui->addCircle, SIGNAL(clicked()), this, SLOT(onAddCircleButton()));
		connect(ui->addTriangle, SIGNAL(clicked()), this, SLOT(onAddTriangleButton()));
		connect(ui->addCylinder, SIGNAL(clicked()), this, SLOT(onAddCylinderButton()));
		connect(ui->addMonkey, SIGNAL(clicked()), this, SLOT(onAddMonkeyButton()));
		connect(ui->addTeapot, SIGNAL(clicked()), this, SLOT(onAddTeapotButton()));

		connect(ui->wireViewButton, SIGNAL(clicked()), this, SLOT(onWireViewButtonClick()));
		connect(ui->solidViewButton, SIGNAL(clicked()), this, SLOT(onSolidViewButtonClick()));
		connect(ui->shadedViewButton, SIGNAL(clicked()), this, SLOT(onLightViewButtonClick()));

		connect(ui->docsButton, SIGNAL(clicked()), this, SLOT(onDocumentationButtonClick()));
		connect(ui->codeButton, SIGNAL(clicked()), this, SLOT(onCodeButtonClick()));

		connect(ui->reportBugButton, SIGNAL(clicked()), this, SLOT(onBugButtonClick()));
		connect(ui->closeButton, SIGNAL(clicked()), this, SLOT(onExitButtonClick()));
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
				exit();				
			}
		}
		return QMainWindow::eventFilter(target, ev);
	}

private slots:
	void onLogoMenuButtonClick() {
		QMenu* menu = new QMenu(this);
		menu->addAction(tr("Sub-action"));
		ui->appButton->setMenu(menu);
	}

	void onToggleSelectButtonClick() {
		ui->glCanvas->selecting = !ui->glCanvas->selecting;
	}

	void onAddCubeButtonClick() {
		ui->glCanvas->addCube();
	}

	void onAddPlaneButtonClick() {
		ui->glCanvas->addPlane();
	}

	void onAddSphereButtonClick() {
		ui->glCanvas->addSphere();
	}

	void onAddCircleButtonClick() {
		ui->glCanvas->addCircle();
	}

	void onAddTriangleButtonClick() {
		ui->glCanvas->addTriangle();
	}

	void onAddMonkeyButtonClick() {
		ui->glCanvas->addOBJ("assets/models/suzanne.obj");
	}

	void onAddTeapotButtonClick() {
		ui->glCanvas->addOBJ("assets/models/teapot.obj");
	}

	void onAddOBJButtonClick() {
		std::string path = QFileDialog::getOpenFileName(this, tr("Open File"), "assets/models", tr(".OBJ Files (*.obj)")).toStdString();

		ui->glCanvas->addOBJ(path);
	}

	void onAddLightButtonClick() {
		ui->glCanvas->world.add(std::make_shared<Light>("Light"));
	}

	void onSolidViewButtonClick() {
		ui->glCanvas->setSceneDrawType(DEFAULT);
	}

	void onWireViewButtonClick() {
		ui->glCanvas->setSceneDrawType(WIRE);
	}

	void onLightViewButtonClick() {
		ui->glCanvas->setSceneDrawType(LIGHT);
	}

	void onExitButtonClick() {
		exit();
	}

	void onBugButtonClick() {
		system("explorer https://github.com/Christopher-Hosken/breeze_render_engine/issues/new");
	}


	void onCodeButtonClick() {
		system("explorer https://github.com/Christopher-Hosken/breeze_render_engine");
	}

	void onDocumentationButtonClick() {
		system("explorer https://github.com/Christopher-Hosken/breeze_render_engine/blob/master/README.md");
	}

	void onRenderButton() {
		ui->glCanvas->render();
	}

private:
	void exit() {
		if (!quitting) {
			quitting = true;
			QMessageBox* confirmBox = new QMessageBox(this);
			confirmBox->setWindowTitle("Quit?");
			confirmBox->setText("Are you sure you want to quit? Your progress will not be saved.");
			confirmBox->setStandardButtons(QMessageBox::Yes | QMessageBox::No);
			confirmBox->setStyleSheet(".QMessageBox {background-color: rgba(15, 15, 15, 200); border-radius: 8px;} .QMessageBox QLabel{ color: rgb(200, 200, 200);} .QMessageBox QPushButton {background-color:transparent; alignment: center; color: white; border: solid white 1px;}");

			if (confirmBox->exec() == QMessageBox::Yes) {
				this->close();
			}
			else {
				quitting = false;
			}
		}
	}

	Ui::Window* ui;
	QString currentFile;

	bool quitting = false;
};

#endif // !WINDOW_H