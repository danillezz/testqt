#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "object.h"
#include <QStandardItemModel>
#include <settingswindow.h>
#include <QTimer>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QList <Object> CurObjectInfo;
    QTimer *timer;
    int iterator;
    QStandardItemModel model;
    int objectscount;
    SettingsWindow *sw;
    int time;

private slots:
    void next();
    void prev();
public slots:
    void onSettingsChanged(const int newtime, const int newcount);
    void onShowSettings();
    void onNewObjectData(const Object &NewInfo);
signals:
    void SettingsChange();
};

#endif // MAINWINDOW_H
