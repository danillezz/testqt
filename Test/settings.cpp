#include "settings.h"

Settings::Settings()
{
    QSqlQuery qry;
    dbase=QSqlDatabase::addDatabase("QSQLITE");
    dbase.setDatabaseName("Test.sqlite");
    dbase.open();
    qry = QSqlQuery("select * from Objects");
    while (qry.next()) {
    objsetting.id=qry.value(0).toInt();
    objsetting.objname=qry.value(1).toString();
    objsetting.engname=qry.value(2).toString();
    objsetting.filename=qry.value(3).toString();

    objsettings.append(objsetting);
    }
    qry.exec("select * from Times where ID=1");
    qry.first();
    time1=qry.value(2).toInt();
    qry.exec("select * from Times where ID=2");
    qry.first();
    time2=qry.value(2).toInt();
    qry.clear();
}

Settings::~Settings()
{
    objsettings.clear();
    dbase.close();
}

QList <ObjectSettings> Settings::GetSettings() {
    return objsettings;
}

int Settings::count() {
    return objsettings.count();
}

void Settings::GetSettings(QSqlTableModel* model){
    model->setTable("Objects");
    model->select();
}

void Settings::Refresh(){
    QSqlQuery qry;

    qry = QSqlQuery("select * from Objects");
    while (qry.next()) {
    objsetting.id=qry.value(0).toInt();
    objsetting.objname=qry.value(1).toString();
    objsetting.engname=qry.value(2).toString();
    objsetting.filename=qry.value(3).toString();

    objsettings.append(objsetting);
    }
    qry.exec("select * from Times where ID=1");
    qry.first();
    time1=qry.value(2).toInt();
    qry.exec("select * from Times where ID=2");
    qry.first();
    time2=qry.value(2).toInt();
    qry.clear();
}

void Settings::NewTimes(int time_1, int time_2) {
    QSqlQuery qry;
    qry.exec("update Times set Value="+QString(time_1)+" where ID=1");
    qry.exec("update Times set Value="+QString(time_2)+" where ID=2");
}
