#include "facemodelslist.h"
#include <QJsonDocument>
#include <QJsonArray>

/**
 * Constructor
 * Gets filename in parameter and QObject as parent
 * Parameter filename is used as name of file where is located data.
 * 
 **/
FaceModelsList::FaceModelsList(QString fileName, QObject *parent) :
    QAbstractTableModel(parent)
{
    mFile.setFileName(fileName);
    updateData();

}

/**
 * Getter, return FaceModel at exact position
 * 
 **/
FaceModel FaceModelsList::at(int position)
{
    return mFaceModels.at(position);
}

/**
 * Getter, number of FaceModels in List
 * 
 **/
int FaceModelsList::rowCount(const QModelIndex & /*unused*/) const
{
    return mFaceModels.size();
}

/**
 * Getter, number of columns.
 * Is always 4, because of columns - id, date, name and delete button
 * 
 **/
int FaceModelsList::columnCount(const QModelIndex & /*unused*/) const
{
    return 4;
}

/**
 * Return data of columns and other stuff.
 * 
 **/
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

/**
 * Return data of header.
 * It is always id, date, name and delete
 * 
 **/
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

/**
 * This function updates data from JSON file
 * return true if everything went well
 * return false if there is some error
 * 
 **/
bool FaceModelsList::updateData()
{
    beginResetModel();
    mFaceModels.clear();
    endResetModel();

    QString fileContent;

    if(mFile.exists())
    {
        if(!mFile.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            return false;
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


            return true;

        } else {

            return false;
        }

    }

    return false;
}
