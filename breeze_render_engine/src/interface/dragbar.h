#ifndef DRAGBAR_H
#define DRAGBAR_H

#include "../../common.h"
#include <QWidget>

class DragBar : public QWidget {
public:
	DragBar() {
        setGeometry(0, 0, APP_WIDTH, 100);

        QPalette pal = QPalette();

        // set black background
        // Qt::black / "#000000" / "black"
        pal.setColor(QPalette::Window, Qt::red);

        setAutoFillBackground(true);
        setPalette(pal);
        show();
	}

protected:
    void mousePressEvent(QMouseEvent* ev)
    {
        if (ev->button() == Qt::LeftButton) {
            dragPosition = ev->globalPos() - frameGeometry().topLeft();
            ev->accept();
        }
    }
    void mouseMoveEvent(QMouseEvent* ev)
    {
        if (ev->buttons() & Qt::LeftButton) {
            move(ev->globalPos() - dragPosition);
            ev->accept();
        }
    }
private:
    QPoint dragPosition;

};



#endif // !DRAGBAR_H