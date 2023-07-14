#include "mainwindow.h"
#include "./ui_mainwindow.h"

void MainWindow::initGraphics()
{
    QRectF rect(-200, -100, 400, 200); // 创建矩形
    scene = new QGraphicsScene(rect); // 创建场景
    ui->graphicsView->setScene(scene); // 将场景添加到视图中
    QGraphicsRectItem *item = new QGraphicsRectItem(rect); // 创建图元
    item->setFlag(QGraphicsItem::ItemIsFocusable, true);
    item->setFlag(QGraphicsItem::ItemIsSelectable, true);

    QPen pen;
    pen.setWidth(2); // 设置画笔宽度
    item->setPen(pen); // 设置图元的画笔
    scene->addItem(item); // 将图元添加到场景中

    QGraphicsEllipseItem *itemEllipse = new QGraphicsEllipseItem(-100, -50, 200, 100); // 创建椭圆图元
    itemEllipse->setBrush(QBrush(Qt::blue)); // 设置图元的画刷
    scene->addItem(itemEllipse); // 将图元添加到场景中

    QGraphicsEllipseItem *itemEllipse2 = new QGraphicsEllipseItem(-50, -50, 100, 100); // 创建圆图元
    itemEllipse2->setBrush(QBrush(Qt::red)); // 设置图元的画刷
    scene->addItem(itemEllipse2); // 将图元添加到场景中

    QGraphicsEllipseItem *itemEllipse3 = new QGraphicsEllipseItem(-100, -50, 200, 100); // 创建椭圆图元
    itemEllipse3->setFlag(QGraphicsItem::ItemIsFocusable, true);
    itemEllipse3->setFlag(QGraphicsItem::ItemIsSelectable, true);
    itemEllipse3->setFlag(QGraphicsItem::ItemIsMovable, true); // 设置
    itemEllipse3->setBrush(QBrush(Qt::blue)); // 设置图元的画刷
    scene->addItem(itemEllipse3); // 将图元添加到场景中

}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    labViewCord = new QLabel("View Cords:"); // 创建标签
    labViewCord->setMinimumWidth(150); // 设置标签最小宽度
    ui->statusbar->addWidget(labViewCord); // 将标签添加到状态栏

    labSceneCord = new QLabel("Scene Cords:");
    labSceneCord->setMinimumWidth(150);
    ui->statusbar->addWidget(labSceneCord);

    labItemCord = new QLabel("Item Cords:");
    labItemCord->setMinimumWidth(150);
    ui->statusbar->addWidget(labItemCord);

    ui->graphicsView->setCursor(Qt::CrossCursor); // 设置视图的鼠标样式为十字光标
    ui->graphicsView->setMouseTracking(true); // 设置视图追踪鼠标

    connect(ui->graphicsView, SIGNAL(mouseMovePoint(QPoint)), this, SLOT(on_mouseMovePoint(QPoint)));
    connect(ui->graphicsView, SIGNAL(mouseClicked(QPoint)), this, SLOT(on_mouseClicked(QPoint)));

    initGraphics(); // 初始化图形

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    ui->labViewSize->setText(QString::asprintf("Graphics View Cords"
                                               "width=%d, height=%d",
                                               ui->graphicsView->width(),
                                               ui->graphicsView->height())); // 显示视图的尺寸
    QRectF rect = ui->graphicsView->sceneRect();
    ui->labSceneRect->setText(QString::asprintf("QGraphicsView::sceneRect="
                                                "(L,T,W,H)=%.0f,%.0f,%.0f,%.0f",
                                                rect.left(),
                                                rect.top(),
                                                rect.width(),
                                                rect.height())); // 显示场景的尺寸
}

void MainWindow::on_mouseMovePoint(QPoint point)
{
    labViewCord->setText(QString::asprintf("View Cords: %d, %d", point.x(), point.y()));

    QPointF pointScene = ui->graphicsView->mapToScene(point); // 将视图坐标转换为场景坐标
    labSceneCord->setText(QString::asprintf("Scene Cords: %.0f, %.0f", pointScene.x(), pointScene.y()));

}

void MainWindow::on_mouseClicked(QPoint point)
{
    QPointF pointScene = ui->graphicsView->mapToScene(point); // 将视图坐标转换为场景坐标
    QGraphicsItem *item = NULL; // 获取鼠标下的图元
    item = scene->itemAt(pointScene, ui->graphicsView->transform()); // 获取鼠标下的图元
    if(item != NULL) { // 如果图元不为空
        QPointF pointItem = item->mapFromScene(pointScene); // 将场景坐标转换为图元坐标
        labItemCord->setText(QString::asprintf("Item Cords: %.0f, %.0f", pointScene.x(), pointScene.y())); // 显示图元坐标
    }

}

