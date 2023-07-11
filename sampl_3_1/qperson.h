#ifndef QPERSON_H
#define QPERSON_H

#include <QObject>

class QPerson : public QObject
{
    Q_OBJECT
    Q_CLASSINFO("author", "Arxibye")
    Q_CLASSINFO("company", "NCHL")
    Q_CLASSINFO("version", "1.0")
    /**
     * "age"：
     * 这是一个unsigned类型的属性。
     * 它有一个getter方法(READ age)，
     * 一个setter方法(WRITE setAge)，
     * 以及一个Qt信号(NOTIFY ageChanged)。
     * 这意味着，
     * 我们可以获取这个属性的值（通过age()方法），
     * 设置这个属性的值（通过setAge()方法），
     * 并在属性值改变时发出一个信号（通过ageChanged信号）。
    */
    Q_PROPERTY(unsigned age READ age WRITE setAge NOTIFY ageChanged)
    /**
     * "name"：
     * 这是一个QString类型的属性。
     * 它的值直接存储在m_name成员变量中。
     * 没有指定getter或setter方法，
     * 所以我们可以直接访问和修改这个成员变量。
     * 同样，没有定义NOTIFY标志，
     * 所以我们不能在这个属性改变时发出信号。
    */
    Q_PROPERTY(QString name MEMBER m_name)
    /**
     * "score"：
     * 这是一个int类型的属性。
     * 它的值直接存储在m_score成员变量中。
     * 没有指定getter或setter方法，
     * 所以我们可以直接访问和修改这个成员变量。
     * 同样，没有定义NOTIFY标志，
     * 所以我们不能在这个属性改变时发出信号。
    */
    Q_PROPERTY(int score MEMBER m_score)
private:
    unsigned m_age = 10;
    QString m_name;
    int m_score = 79;
public:
    /**
     * explicit 关键字用于修饰构造函数，
     * 以防止其进行隐式的类型转换。
    */
    explicit QPerson(QString name, QObject *parent = nullptr);
    unsigned age();
    void setAge(unsigned int value);
    void incAge();

signals:
    void ageChanged(unsigned value);

};

#endif // QPERSON_H
