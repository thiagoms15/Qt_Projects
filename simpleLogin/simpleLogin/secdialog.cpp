#include "secdialog.h"
#include "ui_secdialog.h"
#include <QPixmap>

SecDialog::SecDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SecDialog)
{
    ui->setupUi(this);
    QPixmap pix(":/images/images/hello.jpeg");
    int w = ui->labelPicHello->width();
    int h = ui->labelPicHello->height();
    ui->labelPicHello->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));
}

SecDialog::~SecDialog()
{
    delete ui;
}
