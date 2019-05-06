#include "facemodelslist.h"
#include <QDebug>
#include <QAbstractItemView>

FaceModelsList::FaceModelsList(QObject *parent) : QObject(parent)
{

     
}

int FaceModelsList::size()
{
    return faceModels.size();
}

FaceModel* FaceModelsList::at(int position)
{
    return faceModels.at(position);
}

bool FaceModelsList::updateData()
{
    faceModels.clear();
    QString actualUserName = qgetenv("USER");

    QVariantMap args;

    args[QStringLiteral("user")] = actualUserName;

    KAuth::Action getModelsAction(QStringLiteral("org.kde.kcontrol.kcmhowdy.getmodels"));
    getModelsAction.setHelperId(QStringLiteral("org.kde.kcontrol.kcmhowdy"));
    getModelsAction.setArguments(args);

    auto job = getModelsAction.execute();

    job->exec();

    if (job->error()){
        qDebug() << "Updatedata action failed";
        exit(255);
        qDebug() << job->errorString();
        qDebug() << job->errorText();
        return false;
    } else {

        qDebug() << "Updatedata action succeeded";

        QString mstring = job->data()["message"].toString();
        qDebug()<<mstring<<endl;



                QStringList list = mstring.split("\n", QString::SkipEmptyParts);

                   QTextStream out(stdout);

                for(int i=2; i< list.size(); i++){
                    FaceModel *f = new FaceModel(list.at(i));
                    faceModels.push_back(f);

                }

                return true;
    }


}

QVector<FaceModel*> FaceModelsList::getModels()
{
    return faceModels;
}
