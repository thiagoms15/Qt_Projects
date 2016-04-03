#include "dialog.h"
#include "myitem.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    graphicsView = new QGraphicsView(this);
    scene = new QGraphicsScene();

    graphicsView->setScene(scene);
    graphicsView->setRenderHint(QPainter::Antialiasing);
    scene->setSceneRect(-200,-200, 300, 300);

    QPen myPen = QPen(Qt::red);
    QLineF TopLine(scene->sceneRect().topLeft(), scene->sceneRect().topRight());
    QLineF LeftLine(scene->sceneRect().topLeft(), scene->sceneRect().bottomLeft());
    QLineF RightLine(scene->sceneRect().topRight(), scene->sceneRect().bottomRight());
    QLineF BottomLine(scene->sceneRect().bottomLeft(), scene->sceneRect().bottomRight());

    scene->addLine(TopLine, myPen);
    scene->addLine(LeftLine, myPen);
    scene->addLine(RightLine, myPen);
    scene->addLine(BottomLine, myPen);

    int itemCount = 1;
    for(int i=0; i < itemCount; i++){
        myItem *item = new myItem();
        scene->addItem(item);
    }

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), scene, SLOT(advance()));
    timer->start(100);

    graphicsView->show();

}

Dialog::~Dialog()
{

    if (NULL != graphicsView){
        delete graphicsView;
        graphicsView = NULL;
    }
    if (NULL != scene){
        delete scene;
        scene = NULL;
    }
    if (NULL != timer){
        timer->stop();
        disconnect(timer, 0, 0, 0);
        delete timer;
        timer = NULL;
    }

}
