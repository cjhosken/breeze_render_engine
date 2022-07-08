#ifndef WINDOW_H
#define WINDOW_H

#include "../common.h"
#include "applicationsettings.h"
#include "ui_mainwindow.h"

#include <QMessageBox>
#include <QFileDialog>
#include <QMenu>

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

		connect(ui->b1, SIGNAL(clicked()), this, SLOT(onToggleSelectButtonClick()));
		connect(ui->b2, SIGNAL(clicked()), this, SLOT(onAddCubeButtonClick()));
		connect(ui->b3, SIGNAL(clicked()), this, SLOT(onAddPlaneButtonClick()));
		connect(ui->b4, SIGNAL(clicked()), this, SLOT(onAddSphereButtonClick()));
		connect(ui->b5, SIGNAL(clicked()), this, SLOT(onAddOBJButtonClick()));
		connect(ui->b6, SIGNAL(clicked()), this, SLOT(onAddLightButtonClick()));
		connect(ui->b7, SIGNAL(clicked()), this, SLOT(onExtraToolsButtonClick()));

		connect(ui->t1, SIGNAL(clicked()), this, SLOT(onWireViewButtonClick()));
		connect(ui->t2, SIGNAL(clicked()), this, SLOT(onSolidViewButtonClick()));
		connect(ui->t3, SIGNAL(clicked()), this, SLOT(onLightViewButtonClick()));

		//connect(ui->d0, SIGNAL(clicked()), this, SLOT(onConsoleButtonClick()));
		connect(ui->d1, SIGNAL(clicked()), this, SLOT(onDocumentationButtonClick()));
		connect(ui->d2, SIGNAL(clicked()), this, SLOT(onCodeButtonClick()));

		connect(ui->r1, SIGNAL(clicked()), this, SLOT(onBugButtonClick()));
		connect(ui->r2, SIGNAL(clicked()), this, SLOT(onExitButtonClick()));
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
		ui->glCanvas->world.add(std::make_shared<Cube>("cube"));
	}

	void onAddPlaneButtonClick() {
		ui->glCanvas->world.add(std::make_shared<Plane>("plane"));
	}

	void onAddSphereButtonClick() {
		ui->glCanvas->world.add(std::make_shared<Sphere>("sphere"));
	}

	void onAddOBJButtonClick() {
		std::string path = QFileDialog::getOpenFileName(this, tr("Open File"), "assets/models", tr(".OBJ Files (*.obj)")).toStdString();

		ui->glCanvas->world.add(std::make_shared<OBJModel>(path, "obj"));
	}

	void onAddLightButtonClick() {
		ui->glCanvas->world.add(std::make_shared<Light>());
	}

	void onExtraToolsButtonClick() {
		QMenu* menu = new QMenu(this);
		menu->addAction(tr("Sub-action"));
		ui->b7->setMenu(menu);
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

	void onConsoleButtonClick() {
		
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