#ifndef CONFIG_H
#define CONFIG_H
#include <QWidget>
#include <utility>
#include <vector>
#include <QString>
#include <map>
#include <QSettings>
using namespace std;
const QString INI_FILE = "/home/petr/untitled1/config.ini";
//const QString INI_FILE = "/lib/security/howdy/config.ini";

const QString DETECTION_NOTICE= "detection_notice";
const QString IGNORE_CLOSED_LID = "ignore_closed_lid";
const QString IGNORE_SSH = "ignore_ssh";
const QString NO_CONFIRMATION = "no_confirmation";
const QString SUPPRESS_UNKNOWN = "suppress_unknown";
const QString USE_CNN = "use_cnn";
const QString CERTAINTY = "certainty";
const QString DARK_THRESHOLD = "dark_threshold";
const QString DEVICE_FORMAT = "device_format";
const QString DEVICE_PATH = "device_path";
const QString EXPOSURE = "exposure";
const QString FORCE_MJPEG = "force_mjpeg";
const QString FRAME_HEIGHT = "frame_height";
const QString FRAME_WIDTH = "frame_width";
const QString MAX_HEIGHT = "max_height";
const QString RECORDING_PLUGIN = "recording_plugin";
const QString TIMEOUT = "timeout";
const QString END_REPORT = "end_report";

const QString CORE = "core";
const QString VIDEO = "video";
const QString DEBUG = "debug";

namespace Ui {
class ConfigForm;
}

class Config : public QWidget
{
    Q_OBJECT
public:

    explicit Config(QWidget *parent = nullptr);
    ~Config();
    void save();

public Q_SLOTS:
    void hasChanged();

Q_SIGNALS:
void changed(bool state);

private:
    Ui::ConfigForm *ui;
    void setValue(QString group, QString name, QString value);
    QString getValue(QString group, QString name);

private:

};

#endif // CONFIG_H
