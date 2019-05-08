#include "facemodelslist.h"
#include <QDebug>
#include <QAbstractItemView>
#include <QJsonDocument>
#include <QJsonArray>
#include <QDateTime>

FaceModelsList::FaceModelsList(QObject *parent) :
    QAbstractTableModel(parent)
{
    mFile.setFileName("/lib/security/howdy/models/petr.dat");
    updateData();

}

int FaceModelsList::rowCount(const QModelIndex &parent) const
{
    return faceModels.size();
}
int FaceModelsList::columnCount(const QModelIndex &parent) const
{
    return 4;
}

QVariant FaceModelsList::data(const QModelIndex &index, int role) const
{
    int row = index.row();
    int col = index.column();

    if(role == Qt::TextAlignmentRole)
        return Qt::AlignCenter;

    if(role == Qt::DisplayRole && col==0)
    {
        return faceModels.at(row).getId();
    }

    if(role == Qt::DisplayRole && col==1)
    {
        return faceModels.at(row).getDate();
    }

    if(role == Qt::DisplayRole && col==2)
    {
        return faceModels.at(row).getName();
    }

    if(role == Qt::DisplayRole && col==3)
    {
        return "delete";
    }

    return QVariant();
}

QVariant FaceModelsList::headerData(int section, Qt::Orientation orientation, int role) const
{
    if(role ==Qt::DisplayRole && orientation == Qt::Horizontal){
        switch (section) {
        case 0:
            return QString("Id");
        case 1:
            return QString("Date");
        case 2:
            return QString("Name");
        case 3:
            return QString("Delete");
        }
    }
    return QVariant();
}

int FaceModelsList::size()
{
    return faceModels.size();
}

//FaceModel* FaceModelsList::at(int position)
//{
//    return faceModels.at(position);
//}

bool FaceModelsList::updateData()
{
    removeRows(0, 1);
    faceModels.clear();
    beginResetModel();

    QString fileContent;

    if(mFile.exists())
    {
        if(!mFile.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            return false;
        }
    }

    fileContent = mFile.readAll();
    mFile.close();

    QJsonDocument document = QJsonDocument::fromJson(fileContent.toUtf8());

    if(document.isArray()){
        QJsonArray models= document.array();

        for(int i = 0; i<models.size(); i++)
        {

            double id = models.at(i)["id"].toDouble();
            double time = models.at(i)["time"].toDouble();
            QString name = models.at(i)["label"].toString();

            FaceModel model(id, time, name);

            faceModels.append(model);


        }

        endResetModel();


        return true;
    } else {
        return false;
    }
//             QJsonArray sett2 = d;
//                   QJsonValue value = sett2.value(QString("label"));
//                   qDebug() << value;
//    faceModels.clear();
//    QString actualUserName = qgetenv("USER");

//    QVariantMap args;

//    args[QStringLiteral("user")] = actualUserName;

//    KAuth::Action getModelsAction(QStringLiteral("org.kde.kcontrol.kcmhowdy.getmodels"));
//    getModelsAction.setHelperId(QStringLiteral("org.kde.kcontrol.kcmhowdy"));
//    getModelsAction.setArguments(args);

//    auto job = getModelsAction.execute();

//    job->exec();

//    if (job->error()){
//        qDebug() << "Updatedata action failed";
//        exit(255);
//        qDebug() << job->errorString();
//        qDebug() << job->errorText();
//        return false;
//    } else {

//        qDebug() << "Updatedata action succeeded";

//        QString mstring = job->data()["message"].toString();
//        qDebug()<<mstring<<endl;



//                QStringList list = mstring.split("\n", QString::SkipEmptyParts);

//                   QTextStream out(stdout);

//                for(int i=2; i< list.size(); i++){
//                    FaceModel *f = new FaceModel(list.at(i));
//                    faceModels.push_back(f);

//                }

//                return true;
//    }


}

QList<FaceModel> FaceModelsList::getModels()
{
    return faceModels;
}
