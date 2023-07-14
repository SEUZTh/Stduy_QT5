#ifndef MYGRAPHICSVIEW_H
#define MYGRAPHICSVIEW_H

#include <QObject>
#include <QGraphicsView>
#include <QMouseEvent>

class MYGraphicsView : public QGraphicsView
{
    Q_OBJECT
public:
    explicit MYGraphicsView(QWidget *parent = nullptr);
protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;

signals:
    void mouseMovePoint(QPoint point);
    void mouseClicked(QPoint point);

};

#endif // MYGRAPHICSVIEW_H
