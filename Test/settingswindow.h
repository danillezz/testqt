#ifndef SETTINGSWINDOW_H
#define SETTINGSWINDOW_H

#include <QWidget>
#include <QtSql>

namespace Ui {
class SettingsWindow;
}

class SettingsWindow : public QWidget
{
    Q_OBJECT

public:
    explicit SettingsWindow(QWidget *parent = 0);
    ~SettingsWindow();
    void Refresh();
public slots:
    void onOk();
signals:
    void SettingsChange(const int time, const int count);
private:
    QSqlDatabase dbase;
    QSqlTableModel *model;
    Ui::SettingsWindow *ui;
};

#endif // SETTINGSWINDOW_H
