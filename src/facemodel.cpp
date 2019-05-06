#include "facemodel.h"
#include <QDebug>

FaceModel::FaceModel(QString listLine)
{
    this->setElements(listLine);
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

