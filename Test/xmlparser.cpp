#include "xmlparser.h"

XMLParser::XMLParser()
{    dbase=QSqlDatabase::addDatabase("QSQLITE");
     dbase.setDatabaseName("Test.sqlite");
     dbase.open();

     QSqlQuery qry;
     qry.exec("select * from Times where ID=2");
     qry.first();

  timer = new QTimer();
  connect(timer, SIGNAL(timeout()), this, SLOT(InfoHandler()));
  timer->start(qry.value(2).toInt()*1000);
  InfoHandler();
  qry.clear();

}

XMLParser::~XMLParser()
{
 timer->stop();
 timer->deleteLater();
 dbase.close();
}

void XMLParser::InfoHandler() {

    QSqlQuery qry;
    QFile *file;
    QString str;
    qry.exec("select * from Times where ID=2");
    qry.first();
    if (qry.value(2).toInt()*1000!=timer->interval())
        timer->start(qry.value(2).toInt()*1000);
    qry.exec("select * from Objects where FileName is not null");
    while (qry.next()) {
    str=qry.value(3).toString();
    file = new QFile(str);
    file->open(QIODevice::ReadOnly | QIODevice::Text);
    parseXML(file);
    }
    qry.clear();
}

void XMLParser::parseXML(QFile *file) {
    Object obj;
    ObjectParam param;
    QXmlStreamReader xml(file);

    while (!xml.atEnd() && !xml.hasError())
        {
            QXmlStreamReader::TokenType token = xml.readNext();
            if (token == QXmlStreamReader::StartDocument)
                continue;
            if (token == QXmlStreamReader::StartElement)
            if (xml.name() == "cityinfo") {
                while (!(xml.tokenType() == QXmlStreamReader::EndElement && xml.name() == "cityinfo"))
                    {
                        if (xml.tokenType() == QXmlStreamReader::StartElement)
                        {
                         if (xml.name() == "name"){
                            xml.readNext();
                            obj.objname=xml.text().toString();}
                         if (xml.name() == "temp"){
                             xml.readNext();
                             param.paramname="Температура"; param.value=xml.text().toDouble();
                             obj.params.append(param);
                               }
                         if (xml.name() == "pressure"){
                             xml.readNext();
                            param.paramname="Давление"; param.value=xml.text().toDouble();
                            obj.params.append(param);
                             }
                         if (xml.name() == "humidity"){
                             xml.readNext();
                            param.paramname="Влажность"; param.value=xml.text().toDouble();
                            obj.params.append(param);
                             }
                         if (xml.name() == "wind"){
                             xml.readNext();
                            param.paramname="Скорость ветра"; param.value=xml.text().toDouble();
                            obj.params.append(param);
                            }
                         if (xml.name() == "clouds"){
                             xml.readNext();
                            param.paramname="Облачность"; param.value=xml.text().toString();
                            obj.params.append(param);
                         }
                         if (xml.name() == "sunset"){
                             xml.readNext();
                            param.paramname="Рассвет"; param.value=xml.text().toString();
                            obj.params.append(param);
                         }
                         if (xml.name() == "sunrise"){
                             xml.readNext();
                            param.paramname="Закат"; param.value=xml.text().toString();
                            obj.params.append(param);
                         }
                            if (xml.name() == "date"){
                                xml.readNext();
                            param.paramname="Дата"; param.value=xml.text().toString();
                            obj.params.append(param);
                         }
                         if (xml.name() == "coords"){
                             xml.readNext();
                            param.paramname="Координаты"; param.value=xml.text().toString();
                            obj.params.append(param);
                        }
                        }
                        xml.readNext();
                    }

      }
    }

    emit NewObjectDataXml(obj);

}
