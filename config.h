#ifndef CONFIG_H
#define CONFIG_H
#include <utility>
#include <string>

using namespace std;

class Config
{
public:
    Config();
    bool loadFile();
    pair<string,bool> getDetectionNotice();

private:
    pair <string,bool> mDetectionNotice = make_pair("detection_notice", false);
    pair <string,bool> mNoConfirmation = make_pair("no_confirmation", false);
    pair <string,bool> mSuppressUnknown = make_pair("suppress_unknown", false);
    pair <string,bool> mIgnoreSsh = make_pair("ignore_ssh", true);
    pair <string,bool> mIgnoreClosedLid = make_pair("ignore_closed_lid", true);
    pair <string,bool> mDisabled = make_pair("disabled", false);
    pair <string,bool> mUseCnn = make_pair("use_cnn", false);


};

#endif // CONFIG_H
