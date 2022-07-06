#ifndef DRAGBAR_H
#define DRAGBAR_H

#include "../common.h"

class DragBar : public QWidget {
public:
    DragBar(QWidget* parent = nullptr) : QWidget(parent) {
        
    }

protected:

    void mousePressEvent(QMouseEvent* ev) override {
        isMouseDown = true;
        mouseClick = ev->pos();
    }

    void mouseReleaseEvent(QMouseEvent* ev) override {
        isMouseDown = false;
    }

    void mouseMoveEvent(QMouseEvent* ev) override {
        if (isMouseDown) {
            QPoint mousePoint = ev->globalPos() - mouseClick;
            window()->move(mousePoint);
        }
    }

private:
    QPoint mouseClick;
    bool isMouseDown = false;

};
 
#endif