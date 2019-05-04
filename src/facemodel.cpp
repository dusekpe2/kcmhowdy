#include "facemodel.h"

FaceModel::FaceModel(QString listLine)
{
    this->setElements(listLine);
}

QStandardItem *FaceModel::getId() const
{
    return m_Id;
}

QStandardItem *FaceModel::getDate() const
{
    return m_Date;
}

QStandardItem *FaceModel::getName() const
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

    m_Id = new QStandardItem(list.at(0));
    m_Date = new QStandardItem(list.at(1));
    m_Name = new QStandardItem(list.at(3));

//    this->m_Id = list.at(0);
//    this->m_Date = list.at(1);
//    this->m_Name = list.at(3);
}

