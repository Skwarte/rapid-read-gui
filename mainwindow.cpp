#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStringList>
#include <QFileDialog>
#include <QStandardPaths>
#include <QDebug>
#include <QFile>
#include <QMessageBox>
#include <unistd.h>
#include <QThread>
#include "qapplication.h"

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
    fileName = QFileDialog::getOpenFileName(this, tr("Open File"), desktop, tr("txt files (*.txt)"), 0, QFileDialog::DontUseNativeDialog);
    qDebug() << fileName;
    //ui->listWidget->addItems(filenames);


    QFile file(fileName);
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream in(&file);
    QString word = in.readAll();
    QStringList fileWords = word.split(" ");
//    ui->currWord->setText(fileWords[0]);
//    QThread::sleep(7);
//        ui->currWord->repaint();
//    ui->currWord->setText(fileWords[1]);
//    QThread::sleep(7);
//        ui->currWord->repaint();
//    ui->currWord->setText(fileWords[2]);
//        ui->currWord->repaint();
//        QThread::sleep(1);

        for(int i = 0; i < fileWords.length(); i++)
        {
             qDebug() << fileWords[i];
            ui->currWord->setText(fileWords[i]);
            qApp->processEvents();
            QThread::usleep(60000000/450); //second spent on each word
        }
//        QThread::sleep(2);
//        ui->currWord->hide();
//        QThread::sleep(2);
//        ui->currWord->setText("End of file has been reached. Please select another file.");
//        ui->currWord->show();
}

