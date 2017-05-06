#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "object.h"
#include <QStandardItemModel>
#include <settings.h>
#include <objectsinfo.h>
#include <settingswindow.h>


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
    Settings settings;
    SettingsWindow *sw;
    int time;
private slots:
    void next();
    void prev();
public slots:
    void onSettingsChanged();
    void onShowSettings();
    void onNewObjectData(const QList<Object> &NewInfo);
signals:
    void SettingsChange();
};

#endif // MAINWINDOW_H
