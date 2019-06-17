#ifndef FACEMODELSLIST_H
#define FACEMODELSLIST_H

#include "facemodel.h"
#include <KAuth>
#include <QFile>

class FaceModelsList : public QAbstractTableModel
{
    Q_OBJECT

public:
    explicit FaceModelsList(QString fileName, QObject *parent=nullptr);
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;
    bool updateData();
    FaceModel at(int position);
private:
    QFile mFile;
    QList<FaceModel> mFaceModels;
};

#endif // FACEMODELSLIST_H
