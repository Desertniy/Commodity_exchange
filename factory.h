#ifndef FACTORY_H
#define FACTORY_H

#include <QObject>
#include "factory_help.h"

class factory : public QObject
{
    Q_OBJECT
public:
    explicit factory(QObject *parent = nullptr);
    virtual factory_help *create() = 0;

signals:

};

#endif // FACTORY_H
