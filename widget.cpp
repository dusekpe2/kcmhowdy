#include "widget.h"
#include "ui_widget.h"
#include <QStandardItemModel>
#include <QProcess>
#include <iostream>
#include <QTextStream>
#include <QMessageBox>
#include <parser.h>
#include <QPushButton>

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
            Parser p(list.at(i));
            QStandardItem *id = new QStandardItem(p.getId());
            QStandardItem *date = new QStandardItem(p.getDate());
            QStandardItem *name = new QStandardItem(p.getName());
            QStandardItem *help = new QStandardItem(QString(""));
            myModel->setItem(i-2,0, id);
            myModel->setItem(i-2,1, date);
            myModel->setItem(i-2,2, name);
            myModel->setItem(i-2,3, help);
        }
        QPushButton *button = new QPushButton("&Delete", this);


        ui->tableView->setModel(myModel);
        ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        ui->tableView->setIndexWidget(myModel->index(1,3), button);
        myModel->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
        myModel->setHeaderData(1, Qt::Horizontal, QObject::tr("Date"));
        myModel->setHeaderData(2, Qt::Horizontal, QObject::tr("Label"));
        myModel->setHeaderData(3, Qt::Horizontal, QObject::tr("Delete"));

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
    reply = QMessageBox::question(this, "Clear", "Remove all models?",
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
