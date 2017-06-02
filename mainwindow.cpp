#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStringList>
#include <QFileDialog>
#include <QStandardPaths>
#include <QDebug>
#include <QFile>
#include <QMessageBox>

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
    QString desktop = QStandardPaths::locate(QStandardPaths::DesktopLocation, QString(), QStandardPaths::LocateDirectory);
    //qDebug() << QStandardPaths::DesktopLocation;
    fileName = QFileDialog::getOpenFileName(this, tr("Open File"), desktop, tr("txt files (*.txt)"));
    qDebug() << fileName;
    //ui->listWidget->addItems(filenames);


    QFile file(fileName);
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream in(&file);
    QString word = in.readAll();
    QStringList fileWords = word.split(" ");

    for(int i = 0; i < fileWords.length(); i++)
    {
        qDebug() << fileWords[i];
    }
    //file.open(fileName);

}

