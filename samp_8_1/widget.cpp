#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    setPalette(QPalette(Qt::white));
    setAutoFillBackground(true);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    int W = this->width();
    int H = this->height();

//    painter.setRenderHint(painter::Antialiasing);

    QPen pen;
    pen.setWidth(20);
    pen.setColor(Qt::red);
    pen.setStyle(Qt::DashDotDotLine);
    pen.setJoinStyle(Qt::RoundJoin);
    painter.setPen(pen);

    QBrush brush;
    brush.setColor(Qt::green);
    brush.setStyle(Qt::Dense5Pattern);
    painter.setBrush(brush);

    QRect rect(W/4, H/4, W/2, H/2);
//    painter.drawRect(rect);

    QFont font;
    font.setPointSize(30);

    QImage image(":images/images/qt.png");
    painter.drawImage(rect, image);
    painter.setFont(font);
    painter.drawText(rect, "Hello Qt");

    QPoint points[] = {QPoint(W/3, H/3), QPoint(W/2, H/2), QPoint(W/2, H/3)};
    painter.drawPolyline(points, 3);

}

