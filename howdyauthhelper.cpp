#include "howdyauthhelper.h"
#include <QDebug>
#include <QProcess>
#include <QString>

#include <QSharedPointer>

#include <KSharedConfig>
#include <KConfig>
#include <KConfigGroup>

ActionReply HowdyAuthHelper::getmodels(const QVariantMap &args)
{
        QString dpkg_command = "sudo howdy list --user " + args["user"].toString();
        QProcess *myProcess = new QProcess(this);
        myProcess->start(dpkg_command);
        myProcess->waitForFinished();

        QString output(myProcess->readAllStandardOutput());

        QVariantMap retdata;
           retdata["message"] = output;

        auto rc = ActionReply::SuccessReply();
        rc.setData(retdata);
        return rc;

}

ActionReply HowdyAuthHelper::addmodel(const QVariantMap &args)
{
        QString dpkg_command = "sudo howdy add --user " + args["user"].toString();
        QProcess *myProcess = new QProcess(this);
        myProcess->start(dpkg_command);
        myProcess->waitForFinished();

        QString output(myProcess->readAllStandardOutput());

        QVariantMap retdata;
           retdata["message"] = output;

        auto rc = ActionReply::SuccessReply();
        rc.setData(retdata);
        return rc;

}

ActionReply HowdyAuthHelper::save(const QVariantMap &args)
{
    KSharedConfigPtr howdyConfig = KSharedConfig::openConfig(args[QStringLiteral("conf")].toString());


    for(auto it  = args.constBegin(); it!= args.constEnd(); it++)
    {

        QStringList configFields = it.key().split('/');

        if(configFields.size()==2)
        {
            QString groupName = configFields[0];
            QString keyName = configFields[1];

            howdyConfig->group(groupName).writeEntry(keyName, it.value());
        }

    }

    howdyConfig->sync();


    return ActionReply::SuccessReply();

}

ActionReply HowdyAuthHelper::remove(const QVariantMap &args)
{
        QString dpkg_command = "sudo howdy remove " + args["modelId"].toString() + " --user " + args["user"].toString();
        QProcess *myProcess = new QProcess(this);
        myProcess->start(dpkg_command);
        myProcess->waitForStarted();
        myProcess->waitForReadyRead();

        QString output(myProcess->readAllStandardOutput());

        QTextStream out(stdout);
        out<<output<<endl;
        myProcess->write("y");

        myProcess->waitForBytesWritten();
        myProcess->closeWriteChannel();
        myProcess->waitForFinished();

        qDebug()<<output<<endl;
        QVariantMap retdata;
           retdata["message"] = output;

        auto rc = ActionReply::SuccessReply();
        rc.setData(retdata);
        return rc;

}

ActionReply HowdyAuthHelper::clear(const QVariantMap &args)
{
    QString dpkg_command = "sudo howdy clear --user " + args["user"].toString();
    QProcess *myProcess = new QProcess(this);
    myProcess->start(dpkg_command);
    myProcess->waitForStarted();
    myProcess->waitForReadyRead();

    QString output(myProcess->readAllStandardOutput());

    QTextStream out(stdout);
    out<<output<<endl;
    myProcess->write("y");

    myProcess->waitForBytesWritten();
    myProcess->closeWriteChannel();
    myProcess->waitForFinished();

    qDebug()<<output<<endl;

    QVariantMap retdata;
       retdata["message"] = output;



    auto rc = ActionReply::SuccessReply();
    rc.setData(retdata);
    return rc;

}



KAUTH_HELPER_MAIN("org.kde.kcontrol.kcmhowdy", HowdyAuthHelper);

#include "moc_howdyauthhelper.cpp"
