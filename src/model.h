#ifndef MODEL_H
#define MODEL_H

#include <QWidget>
#include <map>
#include "parser.h"
#include <iostream>
#include "facemodelslist.h"

using namespace std;

namespace Ui {
class Model;
}

class Model : public QWidget
{
    Q_OBJECT

public:
    explicit Model(QWidget *parent = nullptr);
    ~Model();

public Q_SLOTS:
    void handleClearButton();
    void handleRemoveButton(int id);
    void handleCheckBox(bool state);

Q_SIGNALS:
    void disabledSignal(bool state);

private:
    Ui::Model *ui;
    const char* showDialog(QString name, QString message);
    void startCommand(QString command, QString argument, const char *answer);
    void updateTable();
    map<int, Parser*> modelList;
    FaceModelsList myList;
};

#endif // MODEL_H
