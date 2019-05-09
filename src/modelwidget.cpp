#include "modelwidget.h"
#include "ui_modelwidget.h"
#include <QProcess>
#include <QStandardItemModel>
#include <QTextStream>
#include <QSignalMapper>
#include <QMessageBox>
#include <QDebug>
#include <QDate>
#include <QSortFilterProxyModel>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QTableWidgetItem>
#include <KAuth>
#include <KConfigGroup>
#include <QState>

ModelWidget::ModelWidget(const KSharedConfigPtr &config, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ModelWidget),
    mConfig(config)
{
    ui->setupUi(this); 


    KConfigGroup coreGroup = KConfigGroup(mConfig, CORE);

    isEnabled = (coreGroup.readEntry(DISABLED, QString()) == "false");

   prepareUi();
   updateTable();


//   QString name = qgetenv("USER");
//   qDebug()<<name;

//    QString val;
//          QFile file;
//          file.setFileName("/lib/security/howdy/models/petr.dat");
//          file.open(QIODevice::ReadOnly | QIODevice::Text);
//          val = file.readAll();
//          file.close();
//          qDebug() << val;
//          QJsonDocument d = QJsonDocument::fromJson(val.toUtf8());
//          QJsonArray sett2 = d;
//                QJsonValue value = sett2.value(QString("label"));
//                qDebug() << value;
}

ModelWidget::~ModelWidget()
{
    delete ui;

}

void ModelWidget::hasChanged()
{
    qDebug()<<"hasChanged"<<endl;
    Q_EMIT changed(true);
}


void ModelWidget::handleClearButton()
{

   QString answer = showDialog("Clear", "Remove all models?");

    if(answer == "y"){
        QString actualUserName = qgetenv("USER");

        QVariantMap args;

        args["command"] = "sudo howdy clear ";
        args[QStringLiteral("user")] = actualUserName;

        KAuth::Action getModelsAction(QStringLiteral("org.kde.kcontrol.kcmhowdy.startcommand"));
        getModelsAction.setHelperId(QStringLiteral("org.kde.kcontrol.kcmhowdy"));
        getModelsAction.setArguments(args);

        auto job = getModelsAction.execute();

        job->exec();

        if (job->error()){
            qDebug() << "Clear Failed";
            qDebug() << job->errorString();
            qDebug() << job->errorText();
        } else {
            qDebug() << "Cleared";
        }
    }

}

QString ModelWidget::showDialog(QString name, QString message)
{   
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, name, message,
                                   QMessageBox::Yes|QMessageBox::No);
     if (reply == QMessageBox::Yes) {

       return "y";
     } else {
        return "n";
     }

}

void ModelWidget::handleRemoveButton(int id)
{

    qDebug()<<"Remove: "<<id<<endl;
    QString answer = this->showDialog("Remove", "Remove model with id " + QString::number(id) + "?");

    if(answer == "y")
    {

        QString actualUserName = qgetenv("USER");

        QVariantMap args;

        args["command"] = "sudo howdy remove ";
        args[QStringLiteral("user")] = actualUserName;
        args[QStringLiteral("modelId")] = id;
        KAuth::Action saveAction(QStringLiteral("org.kde.kcontrol.kcmhowdy.startcommand"));
        saveAction.setHelperId(QStringLiteral("org.kde.kcontrol.kcmhowdy"));
        saveAction.setArguments(args);

        auto job = saveAction.execute();

        job->exec();

        if (job->error()){
            qDebug() << "Save Failed";
            qDebug() << job->errorString();
            qDebug() << job->errorText();
        } else {
            qDebug() << "File saved";

            updateTable();
        }


    }


}

void ModelWidget::handleCheckBox(bool state)
{
    qDebug()<<"handleCheckBox"<<endl;
    isEnabled = state;
    hasChanged();

}

void ModelWidget::save()
{
    QVariantMap args;
    args[QStringLiteral("conf")] = mConfig->name();
    args[CORE+"/"+DISABLED] = !isEnabled;

    KAuth::Action saveAction(QStringLiteral("org.kde.kcontrol.kcmhowdy.save"));
    saveAction.setHelperId(QStringLiteral("org.kde.kcontrol.kcmhowdy"));
    saveAction.setArguments(args);

    auto job = saveAction.execute();

    job->exec();

    if (job->error()){
            qDebug() << "Save Failed";
            qDebug() << job->errorString();
            qDebug() << job->errorText();
    } else {
        qDebug() << "File saved";
    }

}

void ModelWidget::prepareUi()
{
    ui->checkAllow->setChecked(isEnabled);

    connect(ui->checkAllow, SIGNAL(clicked(bool)), this, SLOT(handleCheckBox(bool)));

    QTableWidgetItem *headerId = new QTableWidgetItem();
    headerId->setText("Id");

    QTableWidgetItem *headerDate = new QTableWidgetItem();
    headerDate->setText("Date");

    QTableWidgetItem *headerName = new QTableWidgetItem();
    headerName->setText("Name");

    QTableWidgetItem *headerDelete = new QTableWidgetItem();
    headerDelete->setText("Delete");

    ui->tableView->setModel(&myList);

//    ui->tableWidget->setColumnCount(4);
//    ui->tableWidget->setHorizontalHeaderItem(0, headerId);
//    ui->tableWidget->setHorizontalHeaderItem(1, headerDate);
//    ui->tableWidget->setHorizontalHeaderItem(2, headerName);
//    ui->tableWidget->setHorizontalHeaderItem(3, headerDelete);

//    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
//    ui->tableWidget->verticalHeader()->hide();
    connect(ui->clearButton, SIGNAL(clicked()), this, SLOT(handleClearButton()));

}

void ModelWidget::updateTable()
{
    myList.updateData();
    ui->tableView->update();
//    ui->tableWidget->setRowCount(0);

//    ui->tableWidget->setRowCount(myList.size());


//    for(int i=0; i<myList.size(); i++)
//    {
//        QTableWidgetItem *idItem = new QTableWidgetItem(myList.at(i)->getId());
//        idItem->setTextAlignment(Qt::AlignCenter);

//        QTableWidgetItem *dateItem = new QTableWidgetItem(myList.at(i)->getDate());
//        QTableWidgetItem *nameItem = new QTableWidgetItem(myList.at(i)->getName());


//        ui->tableWidget->setItem(i, 0, idItem);
//        ui->tableWidget->setItem(i, 1, dateItem);
//        ui->tableWidget->setItem(i, 2, nameItem);

//        QPushButton* btnRemove = new QPushButton();
//        btnRemove->setText("Remove");

//        ui->tableWidget->setCellWidget(i, 3, btnRemove);

//        QSignalMapper *mapper = new QSignalMapper();

//        connect(btnRemove, SIGNAL(clicked()), mapper, SLOT(map()));
//        mapper->setMapping(btnRemove, myList.at(i)->getId().toInt());
//        connect(mapper, SIGNAL(mapped(int)), this, SLOT(handleRemoveButton(int)));
//    }
}
