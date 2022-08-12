#ifndef WINDOW_H
#define WINDOW_H

#include "../common.h"
#include "ui_mainwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui {
	class Window;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
	Q_OBJECT
public:

	MainWindow() : QMainWindow(), ui(new Ui::Window) {
		ui->setupUi(this);
		installEventFilter(this);
		QSettings settings;

		float radius = settings.value("app/borderRadius").toFloat();

		QPainterPath path;
		path.addRoundedRect(QRect(0, 0, settings.value("app/width").toInt(), settings.value("app/height").toInt()), radius, radius);
		QRegion mask = QRegion(path.toFillPolygon().toPolygon());
		setMask(mask);

		connect(ui->appQuitButton, SIGNAL(triggered()), this, SLOT(onExitButtonClick()));

		connect(ui->toggleObjectSelectionButton, SIGNAL(clicked()), this, SLOT(toggleSelectButton()));
		connect(ui->addCubeButton, SIGNAL(clicked()), this, SLOT(onAddCubeButtonClick()));
		connect(ui->addPlaneButton, SIGNAL(clicked()), this, SLOT(onAddPlaneButtonClick()));
		connect(ui->addSphereButton, SIGNAL(clicked()), this, SLOT(onAddSphereButtonClick()));
		connect(ui->addCameraButton, SIGNAL(clicked()), this, SLOT(onAddCameraButtonClick()));
		connect(ui->addOBJButton, SIGNAL(clicked()), this, SLOT(onAddOBJButtonClick()));
		// Extra Buttons
		connect(ui->addCircle, SIGNAL(triggered()), this, SLOT(onAddCircleButtonClick()));
		connect(ui->addTriangle, SIGNAL(triggered()), this, SLOT(onAddTriangleButtonClick()));
		connect(ui->addCylinder, SIGNAL(triggered()), this, SLOT(onAddCylinderButtonClick()));
		connect(ui->addMonkey, SIGNAL(triggered()), this, SLOT(onAddMonkeyButtonClick()));
		connect(ui->addTeapot, SIGNAL(triggered()), this, SLOT(onAddTeapotButtonClick()));

		connect(ui->wireViewButton, SIGNAL(clicked()), this, SLOT(onWireViewButtonClick()));
		connect(ui->solidViewButton, SIGNAL(clicked()), this, SLOT(onSolidViewButtonClick()));

		connect(ui->docsButton, SIGNAL(clicked()), this, SLOT(onDocumentationButtonClick()));
		connect(ui->codeButton, SIGNAL(clicked()), this, SLOT(onCodeButtonClick()));

		connect(ui->reportBugButton, SIGNAL(clicked()), this, SLOT(onBugButtonClick()));
		connect(ui->closeButton, SIGNAL(clicked()), this, SLOT(onExitButtonClick()));

		// PROPERTIES

		// RENDERING

		connect(ui->propertiesPanel->renderTab->widthInput->edit, SIGNAL(textEdited(QString)), this, SLOT(setRenderWidth(QString)));
		connect(ui->propertiesPanel->renderTab->heightInput->edit, SIGNAL(textEdited(QString)), this, SLOT(setRenderHeight(QString)));

		connect(ui->propertiesPanel->renderTab->samplesInput->edit, SIGNAL(textEdited(QString)), this, SLOT(setRenderSamples(QString)));
		connect(ui->propertiesPanel->renderTab->bouncesInput->edit, SIGNAL(textEdited(QString)), this, SLOT(setRenderBounces(QString)));

		connect(ui->propertiesPanel->renderTab->renderButton, SIGNAL(clicked()), this, SLOT(onRenderButton()));

		// WORLD

		connect(ui->propertiesPanel->worldTab->fov->edit, SIGNAL(valueChanged(int)), this, SLOT(onViewportFOVChanged(int)));

		connect(ui->propertiesPanel->worldTab->gradIn->popup, SIGNAL(colorSelected(QColor)), this, SLOT(updateInnerBackgroundGradient(QColor)));
		connect(ui->propertiesPanel->worldTab->gradOut->popup, SIGNAL(colorSelected(QColor)), this, SLOT(updateOuterBackgroundGradient(QColor)));
		connect(ui->propertiesPanel->worldTab->gradIn->popup, SIGNAL(currentColorChanged(QColor)), this, SLOT(updateInnerBackgroundGradient(QColor)));
		connect(ui->propertiesPanel->worldTab->gradOut->popup, SIGNAL(currentColorChanged(QColor)), this, SLOT(updateOuterBackgroundGradient(QColor)));

		ui->propertiesPanel->worldTab->gradIn->popup->setCurrentColor(settings.value("color/viewportGradientInner").value<QColor>());
		ui->propertiesPanel->worldTab->gradIn->changeColor();
		ui->propertiesPanel->worldTab->gradOut->popup->setCurrentColor(settings.value("color/viewportGradientOuter").value<QColor>());
		ui->propertiesPanel->worldTab->gradOut->changeColor();

		// OBJECT

		connect(ui->glCanvas, SIGNAL(updateSelection()), this, SLOT(updateObjectPanel()));	
		updateObjectPanel();
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
				if (ui->glCanvas->selectType != NONE) {
					ui->glCanvas->world.removeWithID(ui->glCanvas->selectID);
					ui->glCanvas->deselect();
					updateObjectPanel();
				}
			}
			else if (keyEvent->key() == Qt::Key_0) {
				ui->glCanvas->inCameraView = !ui->glCanvas->inCameraView;
				ui->glCanvas->repaint();
			}
		}
		return QMainWindow::eventFilter(target, ev);
	}

private slots:

	void setSelectedObjectLocation(QVector3D l) {
		if (ui->glCanvas->selectType == MODEL) {
			ui->glCanvas->world.getModelFromID(ui->glCanvas->selectID)->location = l;
		}
		else {
			ui->glCanvas->world.getCameraFromID(ui->glCanvas->selectID)->location = l;
		}
		ui->glCanvas->repaint();
	}

	void setSelectedObjectRotation(QVector3D r) {
		if (ui->glCanvas->selectType == MODEL) {
			ui->glCanvas->world.getModelFromID(ui->glCanvas->selectID)->rotation = r;
		}
		else {
			ui->glCanvas->world.getCameraFromID(ui->glCanvas->selectID)->rotation = r;
		}
		ui->glCanvas->repaint();
	}

	void setSelectedObjectScale(QVector3D s) {
		if (ui->glCanvas->selectType == MODEL) {
			ui->glCanvas->world.getModelFromID(ui->glCanvas->selectID)->scale = s;
		}
		else {
			ui->glCanvas->world.getCameraFromID(ui->glCanvas->selectID)->scale = s;
		}
		ui->glCanvas->repaint();
	}

	void renameSelectedObject(QString n) {
		if (ui->glCanvas->selectType == MODEL) {
			ui->glCanvas->world.getModelFromID(ui->glCanvas->selectID)->name = n;
		}
		else {
			ui->glCanvas->world.getCameraFromID(ui->glCanvas->selectID)->name = n;
		}

		ui->glCanvas->repaint();
	}

	void setSelectedObjectColor(QColor col) {
		if (ui->glCanvas->selectType == MODEL) {
			ui->glCanvas->world.getModelFromID(ui->glCanvas->selectID)->material.color = col;
			ui->glCanvas->repaint();
		}
	}

	void setSelectedObjectRoughness(int r) {
		if (ui->glCanvas->selectType == MODEL) {
			ui->glCanvas->world.getModelFromID(ui->glCanvas->selectID)->material.roughness = r / 100.0f;
			ui->glCanvas->repaint();
		}
	}

	void setSelectedObjectFOV(int f) {
		if (ui->glCanvas->selectType == CAMERA) {
			ui->glCanvas->world.getCameraFromID(ui->glCanvas->selectID)->setFov(f);
		}
		ui->glCanvas->repaint();
	}

	void setSelectedObjectDOF(bool b) {
		if (ui->glCanvas->selectType == CAMERA) {
			ui->glCanvas->world.getCameraFromID(ui->glCanvas->selectID)->dof = b;
		}
	}

	void setSelectedObjectDistance(QString num_f) {
		if (ui->glCanvas->selectType == CAMERA) {
			ui->glCanvas->world.getCameraFromID(ui->glCanvas->selectID)->distance = num_f.toFloat();
		}
	}

	void setSelectedObjectAperture(QString num_f) {
		if (ui->glCanvas->selectType == CAMERA) {
			ui->glCanvas->world.getCameraFromID(ui->glCanvas->selectID)->aperture = num_f.toFloat();
		}
	}

	void setRenderWidth(QString num_s) {

		ui->glCanvas->world.getCamera(0)->setWidth(num_s.toInt());
		ui->glCanvas->repaint();
	}

	void setRenderHeight(QString num_s) {
		ui->glCanvas->world.getCamera(0)->setHeight(num_s.toInt());
		ui->glCanvas->repaint();
	}

	void setRenderSamples(QString num_s) {
		ui->glCanvas->world.getCamera(0)->samples = num_s.toInt();
	}

	void setRenderBounces(QString num_s) {
		ui->glCanvas->world.getCamera(0)->bounces = num_s.toInt();
	}

	void updateObjectPanel() {
		int idx = ui->propertiesPanel->root->currentIndex();

		ui->propertiesPanel->root->removeTab(2);
		if (ui->glCanvas->selectType == MODEL) {
			ui->propertiesPanel->objectTab = new ObjectTab();
			ui->propertiesPanel->objectTab->setModel(ui->glCanvas->world.getModelFromID(ui->glCanvas->selectID));

			// RECONNECT OBJECT SLOTS
			connect(ui->propertiesPanel->objectTab->name, SIGNAL(textEdited(QString)), this, SLOT(renameSelectedObject(QString)));

			connect(ui->propertiesPanel->objectTab->loc, SIGNAL(edited(QVector3D)), this, SLOT(setSelectedObjectLocation(QVector3D)));
			connect(ui->propertiesPanel->objectTab->rot, SIGNAL(edited(QVector3D)), this, SLOT(setSelectedObjectRotation(QVector3D)));
			connect(ui->propertiesPanel->objectTab->sca, SIGNAL(edited(QVector3D)), this, SLOT(setSelectedObjectScale(QVector3D)));

			connect(ui->propertiesPanel->objectTab->color->popup, SIGNAL(colorSelected(QColor)), this, SLOT(setSelectedObjectColor(QColor)));
			connect(ui->propertiesPanel->objectTab->color->popup, SIGNAL(currentColorChanged(QColor)), this, SLOT(setSelectedObjectColor(QColor)));
			connect(ui->propertiesPanel->objectTab->rough->edit, SIGNAL(valueChanged(int)), this, SLOT(setSelectedObjectRoughness(int)));

			ui->propertiesPanel->root->addTab(ui->propertiesPanel->objectTab, "Object");

		} else if (ui->glCanvas->selectType == CAMERA) {
			ui->propertiesPanel->cameraTab = new CameraTab();
			ui->propertiesPanel->cameraTab->setCamera(ui->glCanvas->world.getCameraFromID(ui->glCanvas->selectID));

			// RECONNECT CAMERA SLOTS
			connect(ui->propertiesPanel->cameraTab->loc, SIGNAL(edited(QVector3D)), this, SLOT(setSelectedObjectLocation(QVector3D)));
			connect(ui->propertiesPanel->cameraTab->rot, SIGNAL(edited(QVector3D)), this, SLOT(setSelectedObjectRotation(QVector3D)));

			connect(ui->propertiesPanel->cameraTab->fov->edit, SIGNAL(valueChanged(int)), this, SLOT(setSelectedObjectFOV(int)));

			//connect(ui->propertiesPanel->cameraTab->dof->edit, SIGNAL(valueChanged(int)), this, SLOT(setSelectedObjectDOF(int)));

			connect(ui->propertiesPanel->cameraTab->distance->edit, SIGNAL(textEdited(QString)), this, SLOT(setSelectedObjectDistance(QString)));
			connect(ui->propertiesPanel->cameraTab->aperture->edit, SIGNAL(textEdited(QString)), this, SLOT(setSelectedObjectAperture(QString)));

			ui->propertiesPanel->root->addTab(ui->propertiesPanel->cameraTab, "Camera");
		}

		if (ui->glCanvas->selectType == NONE) {
			if (idx > 1) {
				idx = 1;
			}
		}

		ui->propertiesPanel->root->setCurrentIndex(idx);
	}

	void updateInnerBackgroundGradient(QColor inner) {

		ui->glCanvas->cvs.innerColor = inner;
		ui->glCanvas->repaint();
	}

	void updateOuterBackgroundGradient(QColor outer) {

		ui->glCanvas->cvs.outerColor = outer;
		ui->glCanvas->repaint();
	}

	void onViewportFOVChanged(int value) {
		ui->glCanvas->setFOV(float(value));
		ui->glCanvas->repaint();
	}

	void toggleSelectButton() {
		ui->glCanvas->selecting = !ui->glCanvas->selecting;
	}

	void onAddCubeButtonClick() {
		ui->glCanvas->world.add(std::make_shared<Cube>("Cube"));
	}

	void onAddPlaneButtonClick() {
		ui->glCanvas->world.add(std::make_shared<Plane>("Plane"));
	}

	void onAddSphereButtonClick() {
		ui->glCanvas->world.add(std::make_shared<Sphere>("Sphere"));
	}

	void onAddCircleButtonClick() {
		ui->glCanvas->world.add(std::make_shared<Circle>("Circle"));
	}

	void onAddCylinderButtonClick() {
		ui->glCanvas->world.add(std::make_shared<Cylinder>("Cylinder"));
	}

	void onAddTriangleButtonClick() {
		ui->glCanvas->world.add(std::make_shared<Triangle>("Triangle"));
	}

	void onAddMonkeyButtonClick() {
		ui->glCanvas->world.add(std::make_shared <OBJModel> (":/assets/models/monkey.obj","Monkey"));
	}

	void onAddTeapotButtonClick() {
		ui->glCanvas->world.add(std::make_shared <OBJModel>(":/assets/models/teapot.obj", "Utah Teapot"));
	}

	void onAddOBJButtonClick() {
		std::string path = QFileDialog::getOpenFileName(this, tr("Open File"), ":/assets/models", tr(".OBJ Files (*.obj)")).toStdString();

		ui->glCanvas->world.add(std::make_shared <OBJModel>(path, "Custom OBJ"));
	}

	void onAddCameraButtonClick() {
		ui->glCanvas->world.add(std::make_shared<RenderCamera>("Camera"));
	}

	void onSolidViewButtonClick() {
		ui->solidViewButton->setChecked(true);
		ui->solidViewButton->setColor();
		ui->wireViewButton->setChecked(false);
		ui->wireViewButton->setColor();
		ui->glCanvas->setSceneDrawType(DEFAULT);
		ui->glCanvas->repaint();
	}

	void onWireViewButtonClick() {
		ui->wireViewButton->setChecked(true);
		ui->wireViewButton->setColor();
		ui->solidViewButton->setChecked(false);
		ui->solidViewButton->setColor();
		ui->glCanvas->setSceneDrawType(WIRE);
		ui->glCanvas->repaint();
	}

	void onExitButtonClick() {
		exit();
	}

	void onBugButtonClick() {
		QDesktopServices service = QDesktopServices();
		service.openUrl(QUrl("https://github.com/Christopher-Hosken/breeze_render_engine/issues/new"));
	}


	void onCodeButtonClick() {
		QDesktopServices service = QDesktopServices();
		service.openUrl(QUrl("https://github.com/Christopher-Hosken/breeze_render_engine"));
	}

	void onDocumentationButtonClick() {
		QDesktopServices service = QDesktopServices();
		service.openUrl(QUrl("https://github.com/Christopher-Hosken/breeze_render_engine/blob/master/README.md"));
	}

	void onRenderButton() {
		ui->glCanvas->render();
	}

private:
	void exit() {
		if (!quitting) {
			QSettings settings;
			quitting = true;	

			QConfirmBox* confirm = new QConfirmBox("Quit?", "Are you sure you want to quit? Your progress wil not be saved. (for now)");

			if (confirm->exec() == QMessageBox::Yes) {
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