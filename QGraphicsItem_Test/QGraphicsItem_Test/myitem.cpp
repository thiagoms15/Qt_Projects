#include "myitem.h"

myItem::myItem()
{
    //Random start rotation
    angle = (qrand() % 360);
    setRotation(angle);

    //Set the speed
    speed = 5;

    //Random start position
    int startX = 0;
    int startY = 0;

    if((qrand() % 1)){
        startX = (qrand() % 200);
        startY = (qrand() % 200);
    }
    else{
        startX = (qrand() % -100);
        startY = (qrand() % -100);
    }

    setPos(mapToParent(startX, startY));
}

QRectF myItem::boundingRect() const
{
    return QRect(0, 0, 20, 20);
}

void myItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED (option);
    Q_UNUSED (widget);
    QRectF rec = boundingRect();
    QBrush Brush (Qt::gray);

    //Basic colliction detection
    if(scene()->collidingItems(this).isEmpty()){
        //        no collision
        Brush.setColor(Qt::green);

    }
    else
    {
        //Collision
        Brush.setColor(Qt::red);
        DoCollisions();

    }
    painter->fillRect(rec, Brush);
    painter->drawRect(rec);

}

void myItem::advance(int phase)
{
    if(!phase){
        return;
    }
//    QPointF location = this->pos();

    setPos(mapToParent(0,-(speed)));

}

void myItem::DoCollisions()
{
    //Set a new position

    //Change the angle
    if(((qrand() % 1 ))){
        setRotation(rotation() + (180 + (qrand() % 10)));
    }
    else{
        setRotation(rotation() + (180 + (qrand() % -10)));

    }

    //See if the new position is on bounds
    QPointF newPoint = mapToParent(-(boundingRect().width()), -(boundingRect().width() + 2));

    int startX;
    int startY;

    if(scene()->sceneRect().contains(newPoint)){
        //Move it back bounds
        setPos(mapToParent(0, 0));
    }
    else{
        //Set the new position
        startX = (qrand() % -15);
        startY = (qrand() % -15);
        setPos(mapToParent(startX, startY));
    }
}
