#include "howdy.h"
#include "ui_module.h"
#include <KPluginFactory>
#include <KAboutData>
#include <QStandardItemModel>
#include <QProcess>
#include <iostream>
#include <QTextStream>

K_PLUGIN_FACTORY(howdyConfigFactory, registerPlugin<Howdy>();)

using namespace std;

Howdy::Howdy(QWidget *parent, const QVariantList &args) :
    KCModule(parent, args),
    ui(new Ui::module)
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
    myModel->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));

    connect(ui->disableButton, SIGNAL(clicked()), this, SLOT(handleDisableButton()));
    connect(ui->enableButton, SIGNAL(clicked()), this, SLOT(handleEnableButton()));
}

Howdy::~Howdy()
{

}

void Howdy::save()
{

}

void Howdy::load()
{

}

void Howdy::defaults()
{
    system("gedit ahoj");
}

QString Howdy::quickHelp() const
{
    return "Ahoj";
}

void Howdy::handleDisableButton()
{
    QString dpkg_command = "pkexec sudo howdy disable 1";
    QProcess *myProcess = new QProcess(this);
    myProcess->start(dpkg_command);
}

void Howdy::handleEnableButton()
{
    QString dpkg_command = "pkexec sudo howdy disable 0";
    QProcess *myProcess = new QProcess(this);
    myProcess->start(dpkg_command);
}

#include "howdy.moc"
