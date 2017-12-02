#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
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
    }
}
