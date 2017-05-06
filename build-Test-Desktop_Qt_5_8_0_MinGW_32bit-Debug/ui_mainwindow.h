/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTableView *tableView;
    QLabel *lblObject;
    QPushButton *btnNext;
    QPushButton *btnPrev;
    QPushButton *btnSettings;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(262, 378);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tableView = new QTableView(centralWidget);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(10, 60, 241, 301));
        tableView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableView->setVerticalScrollMode(QAbstractItemView::ScrollPerItem);
        lblObject = new QLabel(centralWidget);
        lblObject->setObjectName(QStringLiteral("lblObject"));
        lblObject->setGeometry(QRect(10, 10, 241, 20));
        QFont font;
        font.setFamily(QStringLiteral("Times New Roman"));
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        lblObject->setFont(font);
        lblObject->setTextFormat(Qt::AutoText);
        lblObject->setAlignment(Qt::AlignCenter);
        btnNext = new QPushButton(centralWidget);
        btnNext->setObjectName(QStringLiteral("btnNext"));
        btnNext->setGeometry(QRect(160, 30, 31, 23));
        btnPrev = new QPushButton(centralWidget);
        btnPrev->setObjectName(QStringLiteral("btnPrev"));
        btnPrev->setGeometry(QRect(70, 30, 31, 23));
        btnSettings = new QPushButton(centralWidget);
        btnSettings->setObjectName(QStringLiteral("btnSettings"));
        btnSettings->setGeometry(QRect(123, 30, 16, 16));
        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\320\237\320\276\320\263\320\276\320\264\320\260", Q_NULLPTR));
        lblObject->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\">\320\234\320\276\321\201\320\272\320\262\320\260</p></body></html>", Q_NULLPTR));
        btnNext->setText(QApplication::translate("MainWindow", ">", Q_NULLPTR));
        btnPrev->setText(QApplication::translate("MainWindow", "<", Q_NULLPTR));
        btnSettings->setText(QApplication::translate("MainWindow", "*", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
