#include "howdyauthhelper.h"
#include <QDebug>
#include <QProcess>
#include <QString>

#include <QSharedPointer>

#include <KSharedConfig>
#include <KConfig>
#include <KConfigGroup>

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

ActionReply HowdyAuthHelper::startcommand(const QVariantMap &args)
{
        QString modelName = args["modelName"].toString();

        QString dpkg_command = args["command"].toString() + args["modelId"].toString() + " --user " + args["user"].toString();
        QProcess *myProcess = new QProcess(this);
        myProcess->start(dpkg_command);
        myProcess->waitForStarted();
        myProcess->waitForReadyRead();

        QString output(myProcess->readAllStandardOutput());

        QTextStream out(stdout);
        out<<output<<endl;

        if(modelName.isNull()){
            myProcess->write("y");
        } else {
            myProcess->write(modelName.toLatin1());
        }


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

KAUTH_HELPER_MAIN("org.kde.kcontrol.kcmhowdy", HowdyAuthHelper)

#include "moc_howdyauthhelper.cpp"
