#include "addwidget.h"
#include "ui_addwidget.h"

#include <KAuth>
#include <QDebug>
#include <QMessageBox>

const int MAX_LENGTH = 24;
const QString DEFAULT_NAME = "noname";

AddWidget::AddWidget(const QString userName, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddWidget),
    actualUserName(userName)
{
    ui->setupUi(this);

    ui->lineEdit->setMaxLength(MAX_LENGTH);

    connect(ui->pushButtonAdd, SIGNAL(clicked()), this, SLOT(handleAddButton()));
}

AddWidget::~AddWidget()
{
    delete ui;
}

void AddWidget::handleAddButton()
{
    QVariantMap args;

    if(ui->lineEdit->text().size())
    {
        args["modelName"] = ui->lineEdit->text();
    } else {
        args["modelName"] = DEFAULT_NAME;
    }

    args["command"] = "sudo howdy add ";

    args[QStringLiteral("user")] = actualUserName;

    KAuth::Action startCommandAction(QStringLiteral("org.kde.kcontrol.kcmhowdy.startcommand"));
    startCommandAction.setHelperId(QStringLiteral("org.kde.kcontrol.kcmhowdy"));
    startCommandAction.setArguments(args);

    auto job = startCommandAction.execute();

    job->exec();

    if (job->error()){
        qDebug() << "Adding failed";
        qDebug() << job->errorString();
        qDebug() << job->errorText();
    } else {
        qDebug() << "Added";
        ui->lineEdit->clear();
    }
}
