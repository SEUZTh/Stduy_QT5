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


void Widget::on_pushButton_clicked()
{
    int num = ui->spinNum->value();
    float price = ui->spinPrice->value();
    float total = num * price;
    ui->spinTotal->setValue(total);
}


void Widget::on_spinNum_valueChanged(int arg1)
{
    Q_UNUSED(arg1);
    on_pushButton_clicked();
}


void Widget::on_btnDec_clicked()
{
    int value = ui->spinDec->value();
    ui->spinBin->setValue(value);
    ui->spinHex->setValue(value);
}

