#ifndef FACEMODEL_H
#define FACEMODEL_H

#include <QStandardItemModel>


class FaceModel
{
public:
    FaceModel(QString listLine);
    ~FaceModel();
    QString getId() const;
    QString getDate() const;
    QString getName() const;

private:
    QString m_Id;
    QString m_Date;
    QString m_Name;


    void setElements(QString inputString);

};

#endif // FACEMODEL_H
