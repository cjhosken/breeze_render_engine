#ifndef QRENDERPOPUP_H
#define QRENDERPOPUP_H

#include "../../common.h"

#include <QProgressDialog>

class QRenderPopup : public QProgressDialog {
public:
    QRenderPopup(int max, QWidget* parent = nullptr) : QProgressDialog(parent) {
        QSettings settings;

        setProperty("class", "progressBox");
        setStyleSheet(settings.value("styles/root").toString());

        setMinimum(0);
        setMaximum(max);
        setValue(0);

        setWindowTitle("Rendering");

        setCancelButton(nullptr);
    }
};

#endif