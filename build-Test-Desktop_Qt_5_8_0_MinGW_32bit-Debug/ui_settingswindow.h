/********************************************************************************
** Form generated from reading UI file 'settingswindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGSWINDOW_H
#define UI_SETTINGSWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SettingsWindow
{
public:
    QTableView *tableView;
    QPushButton *btnOk;
    QLabel *label;
    QLabel *label_2;
    QSpinBox *spinBox;
    QSpinBox *spinBox_2;

    void setupUi(QWidget *SettingsWindow)
    {
        if (SettingsWindow->objectName().isEmpty())
            SettingsWindow->setObjectName(QStringLiteral("SettingsWindow"));
        SettingsWindow->resize(361, 300);
        tableView = new QTableView(SettingsWindow);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(10, 10, 341, 221));
        btnOk = new QPushButton(SettingsWindow);
        btnOk->setObjectName(QStringLiteral("btnOk"));
        btnOk->setGeometry(QRect(270, 260, 75, 23));
        label = new QLabel(SettingsWindow);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 250, 111, 41));
        label_2 = new QLabel(SettingsWindow);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(150, 250, 111, 41));
        spinBox = new QSpinBox(SettingsWindow);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setGeometry(QRect(60, 250, 42, 22));
        spinBox->setMinimum(1);
        spinBox_2 = new QSpinBox(SettingsWindow);
        spinBox_2->setObjectName(QStringLiteral("spinBox_2"));
        spinBox_2->setGeometry(QRect(200, 250, 42, 22));
        spinBox_2->setMinimum(1);

        retranslateUi(SettingsWindow);

        QMetaObject::connectSlotsByName(SettingsWindow);
    } // setupUi

    void retranslateUi(QWidget *SettingsWindow)
    {
        SettingsWindow->setWindowTitle(QApplication::translate("SettingsWindow", "Form", Q_NULLPTR));
        btnOk->setText(QApplication::translate("SettingsWindow", "OK", Q_NULLPTR));
        label->setText(QApplication::translate("SettingsWindow", "<html><head/><body><p>\320\237\320\265\321\200\320\270\320\276\320\264 </p><p>\320\277\320\265\321\200\320\265\320\272\320\273\321\216\321\207\320\265\320\275\320\270\321\217 (\321\201\320\265\320\272)</p></body></html>", Q_NULLPTR));
        label_2->setText(QApplication::translate("SettingsWindow", "<html><head/><body><p>\320\237\320\265\321\200\320\270\320\276\320\264</p><p>\320\276\320\261\320\275\320\276\320\262\320\273\320\265\320\275\320\270\321\217 (\321\201\320\265\320\272)</p></body></html>", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SettingsWindow: public Ui_SettingsWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGSWINDOW_H
