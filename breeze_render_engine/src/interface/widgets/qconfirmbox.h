#ifndef QCONFIRMBOX_H
#define QCONFIRMBOX_H

#include "../../common.h"

class QConfirmBox : public QMessageBox {
public:
    QConfirmBox(QString title, QString message, QWidget* parent = nullptr) : QMessageBox(parent) {
        QSettings settings;

        setWindowTitle(title);
        setText(message);
        setStandardButtons(QMessageBox::Yes | QMessageBox::No);

        setProperty("class", "confirmationBox");
        setStyleSheet(settings.value("styles/root").toString());
    }
};

#endif