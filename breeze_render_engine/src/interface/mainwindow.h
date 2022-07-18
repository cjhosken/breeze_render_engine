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

		connect(ui->appQuitButton, SIGNAL(triggered()), this, SLOT(onExitButtonClick()));

		connect(ui->toggleObjectSelectionButton, SIGNAL(clicked()), this, SLOT(onToggleSelectButtonClick()));
		connect(ui->addCubeButton, SIGNAL(clicked()), this, SLOT(onAddCubeButtonClick()));
		connect(ui->addPlaneButton, SIGNAL(clicked()), this, SLOT(onAddPlaneButtonClick()));
		connect(ui->addSphereButton, SIGNAL(clicked()), this, SLOT(onAddSphereButtonClick()));
		connect(ui->addOBJButton, SIGNAL(clicked()), this, SLOT(onAddOBJButtonClick()));
		connect(ui->addLightButton, SIGNAL(clicked()), this, SLOT(onAddLightButtonClick()));
		// Extra Buttons
		connect(ui->addCircle, SIGNAL(triggered()), this, SLOT(onAddCircleButtonClick()));
		connect(ui->addTriangle, SIGNAL(triggered()), this, SLOT(onAddTriangleButtonClick()));
		connect(ui->addCylinder, SIGNAL(triggered()), this, SLOT(onAddCylinderButtonClick()));
		connect(ui->addMonkey, SIGNAL(triggered()), this, SLOT(onAddMonkeyButtonClick()));
		connect(ui->addTeapot, SIGNAL(triggered()), this, SLOT(onAddTeapotButtonClick()));

		connect(ui->wireViewButton, SIGNAL(clicked()), this, SLOT(onWireViewButtonClick()));
		connect(ui->solidViewButton, SIGNAL(clicked()), this, SLOT(onSolidViewButtonClick()));
		connect(ui->shadedViewButton, SIGNAL(clicked()), this, SLOT(onLightViewButtonClick()));

		connect(ui->docsButton, SIGNAL(clicked()), this, SLOT(onDocumentationButtonClick()));
		connect(ui->codeButton, SIGNAL(clicked()), this, SLOT(onCodeButtonClick()));

		connect(ui->reportBugButton, SIGNAL(clicked()), this, SLOT(onBugButtonClick()));
		connect(ui->closeButton, SIGNAL(clicked()), this, SLOT(onExitButtonClick()));

		// PROPERTIES

		// RENDERING

		connect(ui->propertiesPanel->renderTab->widthInput->edit, SIGNAL(textEdited(QString)), this, SLOT(setRenderWidth(QString)));
		connect(ui->propertiesPanel->renderTab->widthInput->edit, SIGNAL(textEdited(QString)), this, SLOT(setRenderHeight(QString)));

		connect(ui->propertiesPanel->renderTab->widthInput->edit, SIGNAL(textEdited(QString)), this, SLOT(setRenderSamples(QString)));
		connect(ui->propertiesPanel->renderTab->widthInput->edit, SIGNAL(textEdited(QString)), this, SLOT(setRenderBounces(QString)));

		connect(ui->propertiesPanel->renderTab->renderButton, SIGNAL(clicked()), this, SLOT(onRenderButton()));

		// WORLD

		connect(ui->propertiesPanel->worldTab->fov->edit, SIGNAL(valueChanged(int)), this, SLOT(onViewportFOVChanged(int)));

		connect(ui->propertiesPanel->worldTab->gradIn->popup, SIGNAL(colorSelected(QColor)), this, SLOT(updateInnerBackgroundGradient(QColor)));
		connect(ui->propertiesPanel->worldTab->gradOut->popup, SIGNAL(colorSelected(QColor)), this, SLOT(updateOuterBackgroundGradient(QColor)));
		connect(ui->propertiesPanel->worldTab->gradIn->popup, SIGNAL(currentColorChanged(QColor)), this, SLOT(updateInnerBackgroundGradient(QColor)));
		connect(ui->propertiesPanel->worldTab->gradOut->popup, SIGNAL(currentColorChanged(QColor)), this, SLOT(updateOuterBackgroundGradient(QColor)));


		// OBJECT

		connect(ui->glCanvas, SIGNAL(updateSelection()), this, SLOT(updatePropertiesPanel()));

		connect(ui->propertiesPanel->objectTab->name, SIGNAL(textEdited(QString)), this, SLOT(renameSelectedObject(QString)));

		connect(ui->propertiesPanel->objectTab->loc, SIGNAL(edited(QVector3D)), this, SLOT(setSelectedObjectLocation(QVector3D)));
		connect(ui->propertiesPanel->objectTab->rot, SIGNAL(edited(QVector3D)), this, SLOT(setSelectedObjectRotation(QVector3D)));
		connect(ui->propertiesPanel->objectTab->sca, SIGNAL(edited(QVector3D)), this, SLOT(setSelectedObjectScale(QVector3D)));

		connect(ui->propertiesPanel->objectTab->color->popup, SIGNAL(colorSelected(QColor)), this, SLOT(setSelectedObjectColor(QColor)));
		connect(ui->propertiesPanel->objectTab->color->popup, SIGNAL(currentColorChanged(QColor)), this, SLOT(setSelectedObjectColor(QColor)));
		connect(ui->propertiesPanel->objectTab->rough->edit, SIGNAL(valueChanged(int)), this, SLOT(setSelectedObjectRoughness(int)));
		connect(ui->propertiesPanel->objectTab->spec->edit, SIGNAL(valueChanged(int)), this, SLOT(setSelectedObjectSpecular(int)));
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

			else if (keyEvent->key() == Qt::Key_Delete) {
				ui->glCanvas->world.removeID(ui->glCanvas->selectedObject->id);
				ui->glCanvas->selectedObject = NULL;
			}
		}
		return QMainWindow::eventFilter(target, ev);
	}

private slots:

	void setSelectedObjectLocation(QVector3D l) {
		ui->glCanvas->selectedObject->location = l;
		ui->glCanvas->repaint();
	}

	void setSelectedObjectRotation(QVector3D r) {
		ui->glCanvas->selectedObject->rotation = r;
		ui->glCanvas->repaint();
	}

	void setSelectedObjectScale(QVector3D s) {
		ui->glCanvas->selectedObject->scale = s;
		ui->glCanvas->repaint();
	}

	void renameSelectedObject(QString n) {
		ui->glCanvas->selectedObject->name = n.toStdString();
		ui->glCanvas->repaint();
	}

	void setSelectedObjectColor(QColor col) {
		QVector3D vCol(col.red() / 255.0f, col.green() / 255.0f, col.blue() / 255.0f);

		ui->glCanvas->selectedObject->material.color = vCol;
		ui->glCanvas->repaint();

	}

	void setSelectedObjectRoughness(int r) {
		ui->glCanvas->selectedObject->material.roughness = r / 100.0f;
		ui->glCanvas->repaint();
	}

	void setSelectedObjectSpecular(int s) {
		ui->glCanvas->selectedObject->material.specular = s / 100.0f;
		ui->glCanvas->repaint();
	}

	void setRenderWidth(QString num_s) {
		ui->glCanvas->renderCamera.settings.width = num_s.toInt();
	}


	void setRenderHeight(QString num_s) {
		ui->glCanvas->renderCamera.settings.height = num_s.toInt();
	}


	void setRenderSamples(QString num_s) {
		ui->glCanvas->renderCamera.settings.samples = num_s.toInt();
	}


	void setRenderBounces(QString num_s) {
		ui->glCanvas->renderCamera.settings.bounces = num_s.toInt();
	}

	void updatePropertiesPanel() {
		ui->propertiesPanel->objectTab->loadModel(ui->glCanvas->selectedObject);
	}

	void updateInnerBackgroundGradient(QColor innerColor) {
		QVector3D inner(innerColor.red() / 255.0f, innerColor.green() / 255.0f, innerColor.blue() / 255.0f);

		ui->glCanvas->cvs.setInnerColor(inner);
		ui->glCanvas->repaint();
	}

	void updateOuterBackgroundGradient(QColor outerColor) {

		QVector3D outer(outerColor.red() / 255.0f, outerColor.green() / 255.0f, outerColor.blue() / 255.0f);

		ui->glCanvas->cvs.setOuterColor(outer);
		ui->glCanvas->repaint();
	}

	void onViewportFOVChanged(int value) {
		ui->glCanvas->setFOV(float(value));
		ui->glCanvas->repaint();
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

	void onAddCylinderButtonClick() {
		ui->glCanvas->addCylinder();
	}

	void onAddTriangleButtonClick() {
		ui->glCanvas->addTriangle();
	}

	void onAddMonkeyButtonClick() {
		ui->glCanvas->addOBJ(":/assets/models/suzanne.obj");
	}

	void onAddTeapotButtonClick() {
		ui->glCanvas->addOBJ(":/assets/models/teapot.obj");
	}

	void onAddOBJButtonClick() {
		std::string path = QFileDialog::getOpenFileName(this, tr("Open File"), ":/assets/models", tr(".OBJ Files (*.obj)")).toStdString();

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