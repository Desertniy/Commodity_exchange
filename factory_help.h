#ifndef FACTORY_HELP_H
#define FACTORY_HELP_H

#include <QObject>
#include "estate.h"
#include <QRegularExpression>
#include <string>

class factory_help : public QObject
{
    Q_OBJECT

public:
    explicit factory_help(QObject *parent = nullptr);
    virtual Estate* getEst(QString inn, QString product, int count, QString company, QString inn_buyer) = 0;

};
#endif // FACTORY_HELP_H
