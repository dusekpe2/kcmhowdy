#include "facemodel.h"
#include<QDateTime>

FaceModel::FaceModel(double id, double time, QString name)
{
    mId = QString::number(id);
    QDateTime timestamp;
    timestamp.setTime_t(time);
    mDate = timestamp.toString("dd.MM.yyyy hh:mm");
    mName = name;

}

QString FaceModel::getId() const
{
    return mId;
}

QString FaceModel::getDate() const
{
    return mDate;
}

QString FaceModel::getName() const
{
    return mName;
}


FaceModel::~FaceModel()
{

}
