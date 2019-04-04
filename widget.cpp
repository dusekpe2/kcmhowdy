#include "widget.h"
#include "ui_widget.h"
#include <QStandardItemModel>
#include <QProcess>
#include <iostream>
#include <QTextStream>
#include <QMessageBox>

using namespace std;

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    QString dpkg_command = "pkexec sudo howdy list";
        QProcess *myProcess = new QProcess(this);
        myProcess->start(dpkg_command);
        myProcess->waitForFinished();

        QString output(myProcess->readAllStandardOutput());

        QStringList list = output.split("\n", QString::SkipEmptyParts);

           QTextStream out(stdout);
    //       out<<list.at(1);

        QStandardItemModel *myModel = new QStandardItemModel(0, 0, this);


        for(int i=2; i< list.size(); i++){
            QStandardItem *item = new QStandardItem(list.at(i));
            myModel->setItem(i-2,0, item);
        }
        ui->tableView->setModel(myModel);
        ui->tableView->setColumnWidth(0,400);
        ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        myModel->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
        myModel->setHeaderData(1, Qt::Horizontal, QObject::tr("Date"));
        myModel->setHeaderData(2, Qt::Horizontal, QObject::tr("Label"));

        connect(ui->disableButton, SIGNAL(clicked()), this, SLOT(handleDisableButton()));
        connect(ui->enableButton, SIGNAL(clicked()), this, SLOT(handleEnableButton()));
        connect(ui->clearButton, SIGNAL(clicked()), this, SLOT(handleClearButton()));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::handleDisableButton()
{
    QString dpkg_command = "pkexec sudo howdy disable 1";
       QProcess *myProcess = new QProcess(this);
       myProcess->start(dpkg_command);
}

void Widget::handleEnableButton()
{
    QString dpkg_command = "pkexec sudo howdy disable 0";
        QProcess *myProcess = new QProcess(this);
        myProcess->start(dpkg_command);
}

void Widget::handleClearButton()
{
    char *r;

    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Test", "Quit?",
                                   QMessageBox::Yes|QMessageBox::No);
     if (reply == QMessageBox::Yes) {

       r = "y";
     } else {
        r = "n";
     }


    QString dpkg_command = "pkexec sudo howdy clear";
       QProcess *myProcess = new QProcess(this);
       myProcess->start(dpkg_command);
       myProcess->waitForStarted();
       myProcess->waitForReadyRead();

       QString output(myProcess->readAllStandardOutput());

       QTextStream out(stdout);
       out<<output<<endl;
       myProcess->write(r);

       myProcess->waitForBytesWritten();
       myProcess->closeWriteChannel();
       myProcess->waitForFinished();

}

void Widget::handleAddButton()
{

}
