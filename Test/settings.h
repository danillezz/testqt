#ifndef SETTINGS_H
#define SETTINGS_H
#include <object.h>
#include <QList>
#include <QtSql>

class Settings
{

private:
QList <ObjectSettings> objsettings;
ObjectSettings objsetting;
QSqlDatabase dbase;
public:
    Settings();
    ~Settings();
QList <ObjectSettings> GetSettings();
void NewTimes(int time_1, int time_2);
void Refresh();
int count();
void GetSettings(QSqlTableModel* model);
int time1,time2;
};

#endif // SETTINGS_H
