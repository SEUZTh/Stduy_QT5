#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    setPalette(QPalette(Qt::white));
    setAutoFillBackground(true);
    resize(300, 300);
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
    int side = qMin(W, H); // 取最小值
    QRect rect((W-side)/2, (H-side)/2, side, side); // 保证绘制的图形是正方形
    painter.drawRect(rect); // 绘制矩形
    painter.setViewport(rect); // 设置视口
    painter.setWindow(-100, -100, 200, 200); // 设置窗口

    QLinearGradient linearGrad(0, 0, 100, 0); // 线性渐变
    linearGrad.setColorAt(0, Qt::yellow); // 设置渐变颜色
    linearGrad.setColorAt(1, Qt::green); // 设置渐变颜色
    linearGrad.setSpread(QGradient::PadSpread); // 设置渐变模式

    painter.setCompositionMode(QPainter::RasterOp_NotSourceXorDestination); // 设置组合模式
    painter.setBrush(linearGrad); // 设置画刷
    for(int i = 0; i < 36; i++) {
        painter.drawEllipse(QPoint(50,0),50,50); // 绘制圆形
        painter.rotate(10);
    }
}

