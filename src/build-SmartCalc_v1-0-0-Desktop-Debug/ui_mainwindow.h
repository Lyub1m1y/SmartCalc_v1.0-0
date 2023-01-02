/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *simple;
    QPushButton *pushButton;
    QWidget *credit;
    QRadioButton *radioButton;
    QWidget *deposit;
    QCheckBox *checkBox;
    QPushButton *Help;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(492, 550);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(6, -2, 480, 481));
        tabWidget->setLayoutDirection(Qt::LeftToRight);
        tabWidget->setAutoFillBackground(false);
        simple = new QWidget();
        simple->setObjectName(QString::fromUtf8("simple"));
        pushButton = new QPushButton(simple);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(160, 60, 89, 25));
        tabWidget->addTab(simple, QString());
        credit = new QWidget();
        credit->setObjectName(QString::fromUtf8("credit"));
        radioButton = new QRadioButton(credit);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));
        radioButton->setGeometry(QRect(170, 170, 112, 23));
        tabWidget->addTab(credit, QString());
        deposit = new QWidget();
        deposit->setObjectName(QString::fromUtf8("deposit"));
        checkBox = new QCheckBox(deposit);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(140, 160, 92, 23));
        tabWidget->addTab(deposit, QString());
        Help = new QPushButton(centralwidget);
        Help->setObjectName(QString::fromUtf8("Help"));
        Help->setGeometry(QRect(200, 480, 89, 25));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 492, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
#if QT_CONFIG(accessibility)
        tabWidget->setAccessibleName(QString());
#endif // QT_CONFIG(accessibility)
#if QT_CONFIG(accessibility)
        tabWidget->setAccessibleDescription(QString());
#endif // QT_CONFIG(accessibility)
        pushButton->setText(QCoreApplication::translate("MainWindow", "\320\236\320\261\321\213", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(simple), QCoreApplication::translate("MainWindow", "\320\236\320\261\321\213\321\207\320\275\321\213\320\271", nullptr));
        radioButton->setText(QCoreApplication::translate("MainWindow", "\320\232\321\200\320\265\320\264\320\270\321\202", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(credit), QCoreApplication::translate("MainWindow", "\320\232\321\200\320\265\320\264\320\270\321\202\320\275\321\213\320\271", nullptr));
        checkBox->setText(QCoreApplication::translate("MainWindow", "\320\224\320\265\320\277\320\276\320\267", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(deposit), QCoreApplication::translate("MainWindow", "\320\224\320\265\320\277\320\276\320\267\320\270\321\202\320\275\321\213\320\271", nullptr));
        Help->setText(QCoreApplication::translate("MainWindow", "Help", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
