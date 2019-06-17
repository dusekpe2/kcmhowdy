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
        QProcess *proccessToStart = new QProcess(this);
        proccessToStart->start(dpkg_command);
        proccessToStart->waitForStarted();
        proccessToStart->waitForReadyRead();

        if(proccessToStart->exitCode())
        {
            auto errorReplyAction = ActionReply::HelperErrorReply();
            errorReplyAction.addData("message", "Howdy is not installed");
            return errorReplyAction;
        }

        QString output(proccessToStart->readAllStandardOutput());

        QTextStream out(stdout);
        out<<output<<endl;

        if(modelName.isNull()){
            proccessToStart->write("y");
        } else {
            proccessToStart->write(modelName.toLatin1());
        }


        proccessToStart->waitForBytesWritten();
        proccessToStart->closeWriteChannel();
        proccessToStart->waitForFinished();

        if(proccessToStart->exitCode())
        {
            auto errorReplyAction = ActionReply::HelperErrorReply();
            QVariantMap retdata;
               retdata["message"] = "Camera not set correctly";
//            errorReplyAction.addData("message", "Camera not set correctly");
               errorReplyAction.setData(retdata);
            return errorReplyAction;
        }

        qDebug()<<output<<endl;
        QVariantMap retdata;
           retdata["message"] = output;

        auto successReplyAction = ActionReply::SuccessReply();
        successReplyAction.setData(retdata);
        return successReplyAction;

}

KAUTH_HELPER_MAIN("org.kde.kcontrol.kcmhowdy", HowdyAuthHelper)

#include "moc_howdyauthhelper.cpp"
