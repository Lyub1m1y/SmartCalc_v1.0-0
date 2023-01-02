#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDesktopServices>
#include <QUrl>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


//void MainWindow::on_pushButton_clicked()
//{
//    ui->label->setText("Button his pushed!");
//}


void MainWindow::on_Help_clicked()
{
    QDesktopServices::openUrl(QUrl("../dvi.html", QUrl::TolerantMode));
}

