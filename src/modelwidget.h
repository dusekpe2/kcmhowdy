#ifndef MODEL_H
#define MODEL_H

#include <QWidget>
#include <map>
#include <iostream>
#include "facemodelslist.h"

using namespace std;

namespace Ui {
class ModelWidget;
}

class ModelWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ModelWidget(QWidget *parent = nullptr);
    ~ModelWidget();

public Q_SLOTS:
    void handleClearButton();
    void handleRemoveButton(int id);
    void handleCheckBox(bool state);

Q_SIGNALS:
    void disabledSignal(bool state);

private:
    Ui::ModelWidget *ui;
    FaceModelsList myList;

private:
    const char* showDialog(QString name, QString message);
    void updateTable();
    void prepareUi();
    //    void startCommand(QString command, QString argument, const char *answer);

};

#endif // MODEL_H
