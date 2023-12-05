#ifndef ESTATE_H
#define ESTATE_H

#include <QObject>
#include <string>

class Estate : public QObject
{
    Q_OBJECT
public:
    explicit Estate(QObject *parent = nullptr);
    Estate(QString inn, QString product, int count, QString company, QString inn_buyer);
    QString getCompany();
    QString getInn();
    QString getProd();
    int getCount();
    QString getInnBuyer();


private:
    QString company = "";
    QString inn = "";
    QString product = "";
    int count = 0;
    QString inn_buyer = "";

};

#endif // ESTATE_H
