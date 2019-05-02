#include "model.h"
#include "ui_model.h"
#include <QProcess>
#include <QStandardItemModel>
#include <QTextStream>
#include <QSignalMapper>
#include <QMessageBox>
#include <QDebug>
#include <QDate>
#include <QSortFilterProxyModel>

Model::Model(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Model)
{
    ui->setupUi(this);

    updateTable();
    ui->checkAllow->setChecked(true);

    connect(ui->checkAllow, SIGNAL(clicked(bool)), this, SLOT(handleCheckBox(bool)));

}

Model::~Model()
{
    delete ui;

}

void Model::handleClearButton()
{
     const char *answer = showDialog("Clear", "Remove all models?");

     startCommand("pkexec sudo howdy clear", "", answer);
    updateTable();
}

const char* Model::showDialog(QString name, QString message)
{
    const char *answer;

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

void Model::startCommand(QString command, QString argument,const char *answer)
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

void Model::handleRemoveButton(int id)
{
     const char *answer = this->showDialog("Remove", "Remove model with id " + QString::number(id) + "?");

     startCommand("pkexec sudo howdy remove", QString::number(id), answer);
     updateTable();
}

void Model::handleCheckBox(bool state)
{
    emit disabledSignal(true);
}

void Model::updateTable()
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
            Parser *p = new Parser(list.at(i));
            modelList.insert(make_pair(p->getId().toInt(),p));
            QStandardItem *id = new QStandardItem(p->getId());
            QStandardItem *date = new QStandardItem(p->getDate());
            QStandardItem *name = new QStandardItem(p->getName());
            QStandardItem *remove = new QStandardItem(QString(""));

            myModel->setItem(i-2,0, id);
            myModel->setItem(i-2,1, date);
            myModel->setItem(i-2,2, name);
            myModel->setItem(i-2,3, remove);
        }

        qDebug()<<modelList[0]->getName();

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
        ui->tableView->setSortingEnabled(true);
        ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        myModel->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
        myModel->setHeaderData(1, Qt::Horizontal, QObject::tr("Date"));
        myModel->setHeaderData(2, Qt::Horizontal, QObject::tr("Label"));
        myModel->setHeaderData(3, Qt::Horizontal, QObject::tr("Delete"));
}
