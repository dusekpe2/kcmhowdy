#include "widget.h"
#include "ui_widget.h"
#include <QStandardItemModel>
#include <QProcess>
#include <iostream>
#include <QTextStream>
#include <QMessageBox>
#include <parser.h>
#include <QPushButton>
#include <QSignalMapper>
#include <QDebug>

using namespace std;



Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    mConfig = new Config(this);

    QVBoxLayout *layout = new QVBoxLayout();
    ui->Config->setLayout(layout);
    layout->addWidget(mConfig);


    updateTable();

//    connect(ui->comboDetectionNotice, SIGNAL(currentTextChanged(QString)), this, SLOT(comboBoxChanged(QString)));

    connect(ui->textEdit, SIGNAL(textChanged()), this, SLOT(hasChanged()));
    connect(ui->disableButton, SIGNAL(clicked()), this, SLOT(handleDisableButton()));
    connect(ui->enableButton, SIGNAL(clicked()), this, SLOT(handleEnableButton()));
    connect(ui->clearButton, SIGNAL(clicked()), this, SLOT(handleClearButton()));
    connect(ui->addButton, SIGNAL(clicked()), this, SLOT(handleAddButton()));

    connect(mConfig, SIGNAL(changed(bool)), SIGNAL(changed(bool)));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::hasChanged()
{
    Q_EMIT changed(true);
}

void Widget::save()
{
    mConfig->save();
}

void Widget::loadDefaults()
{
    ui->textEdit->setText("");
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
     char *answer = this->showDialog("Clear", "Remove all models?");

     startCommand("pkexec sudo howdy clear", "", answer);
    updateTable();
}

void Widget::handleAddButton()
{
    QString modelName = ui->textEdit->toPlainText();
    QByteArray ba = modelName.toLocal8Bit();
    this->startCommand("pkexec sudo howdy add", "", ba.data());
    this->updateTable();
    ui->textEdit->clear();
}

void Widget::handleRemoveButton(int id)
{
     char *answer = this->showDialog("Remove", "Remove model with id " + QString::number(id) + "?");

     startCommand("pkexec sudo howdy remove", QString::number(id), answer);
     updateTable();
}

char* Widget::showDialog(QString name, QString message)
{
    char *answer;

    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, name, message,
                                   QMessageBox::Yes|QMessageBox::No);
     if (reply == QMessageBox::Yes) {

       answer = "y";
     } else {
        answer = "n";
     }

     return answer;
}

void Widget::startCommand(QString command, QString argument, char *answer)
{
    QString dpkg_command = command + " " + argument;
      QProcess *myProcess = new QProcess(this);
      myProcess->start(dpkg_command);
      myProcess->waitForStarted();
      myProcess->waitForReadyRead();

      QString output(myProcess->readAllStandardOutput());

      QTextStream out(stdout);
      out<<output<<endl;
      myProcess->write(answer);

      myProcess->waitForBytesWritten();
      myProcess->closeWriteChannel();
      myProcess->waitForFinished();
}

void Widget::updateTable()
{
    QString dpkg_command = "pkexec sudo howdy list";
        QProcess *myProcess = new QProcess(this);
        myProcess->start(dpkg_command);
        myProcess->waitForFinished();

        QString output(myProcess->readAllStandardOutput());

        QStringList list = output.split("\n", QString::SkipEmptyParts);

           QTextStream out(stdout);

        QStandardItemModel *myModel = new QStandardItemModel(0, 0, this);


        for(int i=2; i< list.size(); i++){
            Parser p(list.at(i));
            QStandardItem *id = new QStandardItem(p.getId());
            QStandardItem *date = new QStandardItem(p.getDate());
            QStandardItem *name = new QStandardItem(p.getName());
            QStandardItem *remove = new QStandardItem(QString(""));
            myModel->setItem(i-2,0, id);
            myModel->setItem(i-2,1, date);
            myModel->setItem(i-2,2, name);
            myModel->setItem(i-2,3, remove);
        }

        ui->tableView->setModel(myModel);
        ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);

        for(int i=2; i<list.size(); i++)
        {
            QSignalMapper *mapper = new QSignalMapper();

            QPushButton *button = new QPushButton("&Delete", this);
            ui->tableView->setIndexWidget(myModel->index(i-2,3, QModelIndex()), button);
            connect(button, SIGNAL(clicked()), mapper, SLOT(map()));
            mapper->setMapping(button, i-2);
            connect(mapper, SIGNAL(mapped(int)), this, SLOT(handleRemoveButton(int)));

        }

        myModel->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
        myModel->setHeaderData(1, Qt::Horizontal, QObject::tr("Date"));
        myModel->setHeaderData(2, Qt::Horizontal, QObject::tr("Label"));
        myModel->setHeaderData(3, Qt::Horizontal, QObject::tr("Delete"));
}

