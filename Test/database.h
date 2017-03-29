#ifndef DATABASE_H
#define DATABASE_H
#include "QtSql"
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QUrlQuery>
#include <QNetworkReply>
#include <QUrl>
#include <QTimer>

class Database : public QObject
{
public:
    Database();
    ~Database();
    QString GetNextCity();
    QString GetPrevCity();
    void GetWeather(QSqlQueryModel* model);

private:
    QSqlDatabase dbase;
    QSqlQuery qrycity;
    QTimer *timer;
private slots:
    void ParseJSON();
};

#endif // DATABASE_H
