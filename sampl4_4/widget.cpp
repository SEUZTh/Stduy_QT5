#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_SliderRed_valueChanged(int value)
{
    QPalette pal = ui->textEdit->palette();
    QColor color;
    color.setRgb(ui->SliderRed->value(), ui->SliderGreen->value(), ui->SliderBlue->value(), ui->SliderAlpha->value());
    pal.setColor(QPalette::Base, color);
    ui->textEdit->setPalette(pal);
}


void Widget::on_SliderGreen_valueChanged(int value)
{
    on_SliderRed_valueChanged(value);
}


void Widget::on_SliderBlue_valueChanged(int value)
{
    on_SliderRed_valueChanged(value);
}


void Widget::on_SliderAlpha_valueChanged(int value)
{
    on_SliderRed_valueChanged(value);
}


void Widget::on_SliderH_valueChanged(int value)
{
    ui->progBarH->setValue(value);
    ui->ScrollBarH->setValue(value);
}


void Widget::on_dial_valueChanged(int value)
{
    ui->lcdNumber->display(value);
}


void Widget::on_radioBtnHex_clicked()
{
    ui->lcdNumber->setDigitCount(3);
    ui->lcdNumber->setHexMode();
}

