#include "parser.h"
#include <QRegExp>
#include <QStringList>
#include <QDebug>

Parser::Parser(QString listLine)
{
    this->setElements(listLine);
}

QString Parser::getId()
{
    return m_Id;
}

QString Parser::getDate()
{
    return m_Date;
}

QString Parser::getName()
{
    return m_Name;
}

Parser::~Parser()
{

}

void Parser::setElements(QString inputString)
{
    QRegExp rx("[ ]");
    QStringList list = inputString.split(rx, QString::SkipEmptyParts);

    this->m_Id = list.at(0);
    this->m_Date = list.at(1);
    this->m_Name = list.at(3);


    qDebug() << list;
}
