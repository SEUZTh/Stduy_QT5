#include "mygraphicsview.h"

MYGraphicsView::MYGraphicsView(QWidget *parent)
    : QGraphicsView{parent}
{

}

void MYGraphicsView::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton) { // 左键按下
        QPoint point = event->pos(); // 获取鼠标位置
        emit mouseClicked(point); // 发送信号
    }
    QGraphicsView::mousePressEvent(event); // 调用父类的鼠标按下事件
}

void MYGraphicsView::mouseMoveEvent(QMouseEvent *event)
{
    QPoint point = event->pos(); // 获取鼠标位置
    emit mouseMovePoint(point); // 发送信号
    QGraphicsView::mouseMoveEvent(event); // 调用父类的鼠标移动事件
}
