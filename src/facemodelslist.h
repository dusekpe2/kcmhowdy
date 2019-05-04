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
    QStandardItemModel *getModel();
private:
    QVector<FaceModel> faceModels;
    QStandardItemModel *myModel;
};

#endif // FACEMODELSLIST_H
