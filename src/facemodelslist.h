#ifndef FACEMODELSLIST_H
#define FACEMODELSLIST_H
#include <KAuth>
#include <QVector>
#include "facemodel.h"
#include <QStandardItemModel>

class FaceModelsList : QObject
{
    Q_OBJECT

public:
    explicit FaceModelsList(QObject *parent=nullptr);
    bool updateData();
    int size();
    FaceModel* at(int position);
    QVector<FaceModel*> getModels();
private:
    QVector<FaceModel*> faceModels;
};

#endif // FACEMODELSLIST_H
