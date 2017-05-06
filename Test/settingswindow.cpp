#include "settingswindow.h"
#include "ui_settingswindow.h"

SettingsWindow::SettingsWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SettingsWindow)
{
    ui->setupUi(this);
    s.GetSettings(&model);
        ui->tableView->setModel(&model);
        ui->spinBox->setValue(s.time1);
        ui->spinBox_2->setValue(s.time2);
        ui->tableView->resizeColumnsToContents();
    connect(ui->btnOk, SIGNAL(clicked()), this, SLOT(onOk()));
}

SettingsWindow::~SettingsWindow()
{
    delete ui;
}

void SettingsWindow::onOk() {
 s.NewTimes(ui->spinBox->value(),ui->spinBox_2->value());
 emit SettingsChange();
 this->hide();
 }


