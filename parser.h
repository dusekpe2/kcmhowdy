#ifndef PARSER_H
#define PARSER_H
#include <QString>

class Parser
{
public:
    Parser(QString listLine);
    ~Parser();
    QString getId();
    QString getDate();
    QString getName();
private:
    QString m_Id;
    QString m_Date;
    QString m_Name;

    void setElements(QString inputString);
};

#endif // PARSER_H
