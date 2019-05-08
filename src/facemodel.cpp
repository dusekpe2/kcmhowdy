#include "facemodel.h"
#include <QDebug>
#include<QDateTime>

FaceModel::FaceModel(double id, double time, QString name)
{
    m_Id = QString::number(id);
    QDateTime timestamp;
    timestamp.setTime_t(time);
    m_Date = timestamp.toString("dd.MM.yyyy hh:mm");
    m_Name = name;

}

QString FaceModel::getId() const
{
    return m_Id;
}

QString FaceModel::getDate() const
{
    return m_Date;
}

QString FaceModel::getName() const
{
    return m_Name;
}


FaceModel::~FaceModel()
{

}

void FaceModel::setElements(QString inputString)
{
    QRegExp rx("[ ]");
    QStringList list = inputString.split(rx, QString::SkipEmptyParts);
    qDebug()<<list.at(0)<<endl;
    m_Id = list.at(0);
    m_Date =list.at(1);
    m_Name = list.at(3);

//    this->m_Id = list.at(0);
//    this->m_Date = list.at(1);
//    this->m_Name = list.at(3);
}

