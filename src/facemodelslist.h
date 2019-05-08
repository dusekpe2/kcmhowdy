#ifndef FACEMODELSLIST_H
#define FACEMODELSLIST_H
#include <KAuth>
#include <QVector>
#include "facemodel.h"
#include <QStandardItemModel>
#include <QFile>
#include <QAbstractTableModel>

class FaceModelsList : public QAbstractTableModel
{
    Q_OBJECT

public:
    explicit FaceModelsList(QObject *parent=nullptr);
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;
    bool updateData();
    int size();
//    FaceModel* at(int position);
    QList<FaceModel> getModels();
private:
    QFile mFile;

private:
    QList<FaceModel> faceModels;
};

#endif // FACEMODELSLIST_H
