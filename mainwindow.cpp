#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStringList>
#include <QFileDialog>
#include <QStandardPaths>
#include <QDebug>
//#include <QListWidget>
//#include <QListWidgetItem>
//#include "qlistwidget.h"

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

void MainWindow::on_pushButton_clicked()
{
  //  QString desk = (QString)QStandardPaths::DesktopLocation;
    QString homeLocation = QStandardPaths::locate(QStandardPaths::DesktopLocation, QString(), QStandardPaths::LocateDirectory);
    //qDebug() << QStandardPaths::DesktopLocation;
    QString filenames = QFileDialog::getOpenFileName(this, tr("Open File"), "", tr("txt files (*.txt)"));
    qDebug() << filenames;
    //ui->listWidget->addItems(filenames);
}

