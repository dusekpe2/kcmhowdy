#ifndef FACEMODEL_H
#define FACEMODEL_H

#include <QStandardItemModel>


class FaceModel
{
public:
    FaceModel(QString listLine);
    ~FaceModel();
    QStandardItem* getId() const;
    QStandardItem* getDate() const;
    QStandardItem* getName() const;
private:
    QStandardItem *m_Id;
    QStandardItem *m_Date;
    QStandardItem *m_Name;

    void setElements(QString inputString);

};

#endif // FACEMODEL_H
