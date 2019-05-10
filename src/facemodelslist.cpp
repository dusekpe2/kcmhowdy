#include "facemodelslist.h"
#include <QDebug>
#include <QAbstractItemView>
#include <QJsonDocument>
#include <QJsonArray>
#include <QDateTime>

FaceModelsList::FaceModelsList(QString fileName, QObject *parent) :
    QAbstractTableModel(parent)
{
    mFile.setFileName(fileName);
    updateData();

}

FaceModel FaceModelsList::at(int position)
{
    return mFaceModels.at(position);
}

int FaceModelsList::rowCount(const QModelIndex &parent) const
{
    return mFaceModels.size();
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
        return mFaceModels.at(row).getId();
    }

    if(role == Qt::DisplayRole && col==1)
    {
        return mFaceModels.at(row).getDate();
    }

    if(role == Qt::DisplayRole && col==2)
    {
        return mFaceModels.at(row).getName();
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

bool FaceModelsList::updateData()
{
    removeRows(0, 1);
    mFaceModels.clear();
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

            mFaceModels.append(model);


        }

        endResetModel();


        return true;
    } else {
        return false;
    }

}
