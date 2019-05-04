#include "facemodelslist.h"
#include <QDebug>


FaceModelsList::FaceModelsList(QObject *parent)
{
     myModel = new QStandardItemModel(0, 0, this);
}

bool FaceModelsList::updateData()
{
    QString actualUserName = qgetenv("USER");

    QVariantMap args;

    args[QStringLiteral("user")] = actualUserName;

    KAuth::Action getModelsAction(QStringLiteral("org.kde.kcontrol.howdy.getmodels"));
    getModelsAction.setHelperId(QStringLiteral("org.kde.kcontrol.howdy"));
    getModelsAction.setArguments(args);

    auto job = getModelsAction.execute();

    job->exec();

    if (job->error()){
        qDebug() << "Save Failed";
        qDebug() << job->errorString();
        qDebug() << job->errorText();
        return false;
    } else {

        qDebug() << "Option saved";

        QString mstring = job->data()["message"].toString();
        qDebug()<<mstring;



                QStringList list = mstring.split("\n", QString::SkipEmptyParts);

                   QTextStream out(stdout);

                for(int i=2; i< list.size(); i++){
                    FaceModel *f = new FaceModel(list.at(i));
                    qDebug()<<f->getName()<<endl;;
//                    modelList.insert(make_pair(p->getId().toInt(),p));
//                    QStandardItem *id = new QStandardItem(p->getId());
//                    QStandardItem *date = new QStandardItem(p->getDate());
//                    QStandardItem *name = new QStandardItem(p->getName());
//                    QStandardItem *remove = new QStandardItem(QString(""));

//                    myModel->setItem(i-2,0, id);
//                    myModel->setItem(i-2,1, date);
//                    myModel->setItem(i-2,2, name);
//                    myModel->setItem(i-2,3, remove);
                }

                for(int i=0; i<faceModels.size(); i++)
                {
                    myModel->setItem(i,0, (faceModels.at(i)).getId());
                    myModel->setItem(i,1, (faceModels.at(i)).getDate());
                    myModel->setItem(i,2, (faceModels.at(i)).getName());

                }
                return true;
    }


}

QStandardItemModel *FaceModelsList::getModel()
{
    return myModel;
}
