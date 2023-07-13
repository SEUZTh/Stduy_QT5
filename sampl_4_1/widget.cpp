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
    QString str = ui->editNum->text();
    int num = str.toInt();
    str = ui->editPrice->text();
    float price = str.toFloat();
    float total = num * price;
    str = str.setNum(total, 'f', 2);
    ui->editTotal->setText(str);
}


void Widget::on_btnDec_clicked()
{
    QString str = ui->editDec->text();
    int value = str.toInt();
    str = str.setNum(value, 2);
    ui->editBin->setText(str);
    str = str.setNum(value, 16);
    ui->editHex->setText(str.toUpper());
}

// 二进制转换
void Widget::on_btnBin_clicked()
{
    QString str = ui->editBin->text();
    bool ok; // 用于判断转换是否成功
    int value = str.toInt(&ok, 2); // 2表示二进制
    ui->editDec->setText(QString::number(value));
    ui->editHex->setText(QString::number(value, 16).toUpper()); // 16表示十六进制
}

