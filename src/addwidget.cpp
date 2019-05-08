#include "addwidget.h"
#include "ui_addwidget.h"

#include <KAuth>
#include <QDebug>

AddWidget::AddWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddWidget)
{
    ui->setupUi(this);

    connect(ui->pushButtonAdd, SIGNAL(clicked()), this, SLOT(handleAddButton()));
}

AddWidget::~AddWidget()
{
    delete ui;
}

void AddWidget::handleAddButton()
{
    QVariantMap args;

    args["modelName"] = ui->lineEdit->text();
    args["command"] = "sudo howdy add ";
    QString actualUserName = qgetenv("USER");

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
