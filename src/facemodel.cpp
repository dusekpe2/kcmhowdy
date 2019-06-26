#include "facemodel.h"
#include<QDateTime>

/**
 * Constructor of FaceModel
 * gets id, time and name in parameters and sets variables.
 * 
 **/
FaceModel::FaceModel(double id, double time, QString name)
{
    mId = QString::number(id);
    QDateTime timestamp;
    timestamp.setTime_t(time);
    mDate = timestamp.toString("dd.MM.yyyy hh:mm");
    mName = name;

}

/**
 * Getter for id 
 **/
QString FaceModel::getId() const
{
    return mId;
}

/**
 * Getter for date
 **/
QString FaceModel::getDate() const
{
    return mDate;
}

/**
 * Getter for name
 **/
QString FaceModel::getName() const
{
    return mName;
}

/**
 * Destructor
 * Nothing to do
 **/
FaceModel::~FaceModel()
{

}
