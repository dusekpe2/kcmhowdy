#ifndef MODEL_H
#define MODEL_H

#include <QWidget>
#include <map>
#include <iostream>
#include "facemodelslist.h"
#include "config.h"
#include <KSharedConfig>
#include <KConfig>
using namespace std;

namespace Ui {
class ModelWidget;
}

class ModelWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ModelWidget(const QString userName, const KSharedConfigPtr &config, const QString modelsFileName, QWidget *parent = nullptr);
    ~ModelWidget();
    void updateTable();

public Q_SLOTS:
    void handleClearButton();
    void handleRemoveButton(int id);
    void handleCheckBox(bool state);
    void hasChanged();
    void save();
    void load();

Q_SIGNALS:
void changed(bool state);

private:
    Ui::ModelWidget *ui;
    FaceModelsList mFacesModel;
    KSharedConfigPtr mConfig;
    bool mIsEnabled;
    QString mActualUserName;
private:
    QString showDialog(QString name, QString message);
    void prepareUi();
    //    void startCommand(QString command, QString argument, const char *answer);

};

#endif // MODEL_H
