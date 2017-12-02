#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix(":/images/images/lock-icon.png");
    int w  = ui->labelPic->width();
    int h = ui->labelPic->height();
    ui->labelPic->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));
    ui->mainToolBar->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonLogin_clicked()
{
    QString username = ui->lineEditUserName->text();
    QString password = ui->lineEditPassword->text();

    if(username=="user" && password=="user")
    {
        QMessageBox::information(this, "Login", "Username and password are correct.");
        hide();
        secDialog = new SecDialog(this);
        secDialog->show();
    }
    else
    {
        QMessageBox::warning(this, "Login", "Username or password are not correct.");
        ui->lineEditUserName->setText("");
        ui->lineEditPassword->setText("");
        ui->statusBar->showMessage("Username is 'user' and password is 'user'.", 3000);
    }
}
