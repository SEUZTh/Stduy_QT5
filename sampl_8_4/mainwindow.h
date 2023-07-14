#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsItem>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    QLabel *labViewCord; // 显示视图坐标的标签
    QLabel *labSceneCord; // 显示场景坐标的标签
    QLabel *labItemCord; // 显示图元坐标的标签
    QGraphicsScene *scene; // 场景

    void initGraphics(); // 初始化场景中的图元
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
protected:
    void resizeEvent(QResizeEvent *event) override;
private:
    Ui::MainWindow *ui;

private slots:
    void on_mouseMovePoint(QPoint point); // 鼠标移动事件的槽函数
    void on_mouseClicked(QPoint point); // 鼠标按下事件的槽函数`
};
#endif // MAINWINDOW_H
