#ifndef QRENDERPOPUP_H
#define QRENDERPOPUP_H

#include "../../common.h"
#include <QProgressBar>

class QRenderPopup : public QMessageBox {
public:
    QProgressBar* progress;

    QRenderPopup(int max, QWidget* parent = nullptr) : QMessageBox(parent) {
        setWindowTitle("Rendering");
        setStyleSheet(".QMessageBox {background-color: rgba(15, 15, 15, 200); border-radius: 8px;} .QMessageBox QLabel{ color: rgb(200, 200, 200);} .QMessageBox QPushButton {background-color:transparent; alignment: center; color: white; border: solid white 1px;}");

        QVBoxLayout* vbox = new QVBoxLayout();

        progress = new QProgressBar();
        progress->setMinimum(0);
        progress->setMaximum(max);

        vbox->addWidget(progress);

        setLayout(vbox);
    }

public slots:
    void update(int value) {
        progress->setValue(value);
    }



};

#endif