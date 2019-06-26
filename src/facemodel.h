#ifndef FACEMODEL_H
#define FACEMODEL_H

#include <QStandardItemModel>

/**
 * Class for model of face 
 **/
class FaceModel
{
public:
    FaceModel(double id, double time, QString name);
    ~FaceModel();
    QString getId() const;
    QString getDate() const;
    QString getName() const;

private:
    QString mId;
    QString mDate;
    QString mName;
};

#endif // FACEMODEL_H
