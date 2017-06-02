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
    QFont font = ui->currWord->font();
    font.setPointSize(40);
    ui->currWord->setFont(font);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    if(ui->pushButton->text() == "Select File" || ui->pushButton->text() == "Select Another File")
    {
        QString desktop = QStandardPaths::locate(QStandardPaths::DesktopLocation, QString(), QStandardPaths::LocateDirectory);
        fileDir = QFileDialog::getOpenFileName(this, tr("Open File"), desktop, tr("txt files (*.txt)"), 0, QFileDialog::DontUseNativeDialog);
        QStringList fileName = fileDir.split("/");
        ui->currWord->setText("Selected File: " + fileName[fileName.length()-1]);
        ui->pushButton->setText("Go!");
    }
    else
    {
            ui->pushButton->hide();
            QFile file(fileDir);
            file.open(QIODevice::ReadOnly | QIODevice::Text);
            QTextStream in(&file);
            QString word = in.readAll();
            QStringList fileWords = word.split(" ");

            for(int i = 0; i < fileWords.length(); i++)
            {
                qDebug() << fileWords[i];
                ui->currWord->setText(fileWords[i]);
                qApp->processEvents();
                QThread::usleep(60000000/450); //second spent on each word
            }
            ui->pushButton->setText("Select Another File");
            ui->pushButton->show();
            //        QThread::sleep(2);
            //        ui->currWord->hide();
            //        QThread::sleep(2);
            // ui->currWord->setText("End of file has been reached. Please select another file.");
            //        ui->currWord->show();
    }

}

