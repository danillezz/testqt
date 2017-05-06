#ifndef SETTINGSWINDOW_H
#define SETTINGSWINDOW_H

#include <QWidget>
#include <QSqlTableModel>
#include <settings.h>

namespace Ui {
class SettingsWindow;
}

class SettingsWindow : public QWidget
{
    Q_OBJECT

public:
    explicit SettingsWindow(QWidget *parent = 0);
    ~SettingsWindow();

private slots:
    void onOk();
signals:
    void SettingsChange();
private:
    Settings s;
    QSqlTableModel model;
    Ui::SettingsWindow *ui;
};

#endif // SETTINGSWINDOW_H
