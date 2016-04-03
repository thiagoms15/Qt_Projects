#ifndef MYITEM_H
#define MYITEM_H

#include <QPainter>
#include <QGraphicsItem>
#include <QGraphicsScene>

class myItem : public QGraphicsItem
{
public:
    myItem();

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

protected:

    void advance(int phase);

private:

    qreal angle;
    qreal speed;

    void DoCollisions();

};

#endif // MYITEM_H
