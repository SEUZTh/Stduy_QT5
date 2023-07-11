#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    /**
     * "isBoy" 属性被设置为 true 或 false，
     * 可能表示这个特定的 QSpinBox 是否关联到 "boy" 或 "girl"。
     * 这样做的一个潜在的好处是，
     * 你可以在后续的代码中通过 property() 函数获取这些属性，
     * 以便根据属性的值改变控件的行为。
     * 例如，如果你有一个函数需要处理 QSpinBox 的值改变，
     * 你可以检查 "isBoy" 属性，
     * 以便知道你正在处理 "boy" 还是 "girl" 的 spin box。
    */
    ui->spinBoxBoy->setProperty("isBoy", true);
    ui->spinBoxGirl->setProperty("isBoy", false);

    boy = new QPerson("Mike");
    boy->setProperty("score", 95);
    boy->setProperty("age", 23);
    boy->setProperty("sex", "boy");
    connect(boy, &QPerson::ageChanged, this, &Widget::on_ageChanged);

    girl = new QPerson("Lily");
    girl->setProperty("score", 99);
    girl->setProperty("age", 24);
    girl->setProperty("sex", "girl");
    connect(girl, &QPerson::ageChanged, this, &Widget::on_ageChanged);

    connect(ui->spinBoxBoy, SIGNAL(valueChanged(int)), this, SLOT(on_spin_valueChanged(int)));
    connect(ui->spinBoxGirl, SIGNAL(valueChanged(int)), this, SLOT(on_spin_valueChanged(int)));
}

Widget::~Widget()
{
    delete ui;
}

/**
 * @brief 这个槽函数的作用是响应一个 QSpinBox 的值变化的信号，
 * 并根据 QSpinBox 的 "isBoy" 属性，
 * 将新的值设置为 "boy" 或 "girl" 对象的年龄。
 * @param arg1
 * @note
 * 1. sender() 返回发送信号的对象的指针。
 * 2. qobject_cast() 函数用于将一个 QObject 指针转换为另一个 QObject 指针。
*/
void Widget::on_spin_valueChanged(int arg1)
{
    /**
     * 标记 arg1 这个函数参数为未使用。
     * 这样可以避免编译器关于未使用参数的警告。
    */
    Q_UNUSED(arg1);
    QSpinBox *spinBox = qobject_cast<QSpinBox*>(sender());
    if(spinBox->property("isBoy").toBool())
        boy->setAge(spinBox->value());
    else
        girl->setAge(spinBox->value());
}

void Widget::on_ageChanged(unsigned int value)
{
    Q_UNUSED(value)
    QPerson *aPerson = qobject_cast<QPerson*>(sender());
    QString aName = aPerson->property("name").toString();
    QString aSex = aPerson->property("sex").toString();
    unsigned aAge = aPerson->age();
    ui->txtEdit->appendPlainText(aName + "," + aSex + QString::asprintf(", 年龄=%d", aAge));
}

void Widget::on_btnBoyInc_clicked()
{
    boy->incAge();
}

void Widget::on_btnGirlInc_clicked()
{
    girl->incAge();
}

void Widget::on_btnClassInfo_clicked()
{
    const QMetaObject *meta = girl->metaObject();
    ui->txtEdit->clear();
    ui->txtEdit->appendPlainText("==元对象信息==\n");
    ui->txtEdit->appendPlainText(QString("类名：%1\n").arg(meta->className()));
    ui->txtEdit->appendPlainText("==属性信息==\n");
    for(int i = meta->propertyOffset(); i < meta->propertyCount(); i++) {
        QMetaProperty prop = meta->property(i);
        const char* propName = prop.name();
        QString propVlaue = boy->property(propName).toString();
        ui->txtEdit->appendPlainText(QString("属性名：%1, 属性值：%2\n").arg(propName).arg(propVlaue));
    }
    ui->txtEdit->appendPlainText("");
    ui->txtEdit->appendPlainText("==类信息==\n");
    for(int i = meta->classInfoOffset(); i < meta->classInfoCount(); i++) {
        QMetaClassInfo classInfo = meta->classInfo(i);
        ui->txtEdit->appendPlainText(QString("name: %1, value: %2\n").arg(classInfo.name()).arg(classInfo.value()));
    }
}

