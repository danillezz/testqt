#ifndef XMLPARSER_H
#define XMLPARSER_H

#include <object.h>
#include <QObject>
#include <QtSql>
#include <QXmlStreamReader>


class XMLParser : public QObject
{

    Q_OBJECT
public:
    XMLParser();
    ~XMLParser();

signals:
void NewObjectDataXml(const Object NewObj);

private:
    void parseXML(QFile *file);
    QSqlDatabase dbase;
    QTimer *timer;
private slots:
void InfoHandler();

};

#endif // XMLPARSER_H
