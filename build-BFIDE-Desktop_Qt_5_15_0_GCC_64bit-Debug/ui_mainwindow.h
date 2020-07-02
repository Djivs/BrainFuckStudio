/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionCredits;
    QAction *actionCredits_2;
    QWidget *centralwidget;
    QWidget *widget;
    QVBoxLayout *verticalLayout_3;
    QPushButton *run;
    QTextEdit *prog;
    QPushButton *clear;
    QWidget *widget1;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QTextBrowser *output;
    QWidget *widget2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QTextEdit *input;
    QWidget *widget3;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_3;
    QVBoxLayout *verticalLayout_4;
    QRadioButton *bytes8;
    QRadioButton *bytes16;
    QRadioButton *bytes32;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        actionCredits = new QAction(MainWindow);
        actionCredits->setObjectName(QString::fromUtf8("actionCredits"));
        actionCredits_2 = new QAction(MainWindow);
        actionCredits_2->setObjectName(QString::fromUtf8("actionCredits_2"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(260, 280, 258, 224));
        verticalLayout_3 = new QVBoxLayout(widget);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        run = new QPushButton(widget);
        run->setObjectName(QString::fromUtf8("run"));

        verticalLayout_3->addWidget(run);

        prog = new QTextEdit(widget);
        prog->setObjectName(QString::fromUtf8("prog"));

        verticalLayout_3->addWidget(prog);

        clear = new QPushButton(widget);
        clear->setObjectName(QString::fromUtf8("clear"));

        verticalLayout_3->addWidget(clear);

        widget1 = new QWidget(centralwidget);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        widget1->setGeometry(QRect(50, 20, 258, 216));
        verticalLayout = new QVBoxLayout(widget1);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget1);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        output = new QTextBrowser(widget1);
        output->setObjectName(QString::fromUtf8("output"));

        verticalLayout->addWidget(output);

        widget2 = new QWidget(centralwidget);
        widget2->setObjectName(QString::fromUtf8("widget2"));
        widget2->setGeometry(QRect(500, 20, 258, 216));
        verticalLayout_2 = new QVBoxLayout(widget2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(widget2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_2->addWidget(label_2);

        input = new QTextEdit(widget2);
        input->setObjectName(QString::fromUtf8("input"));

        verticalLayout_2->addWidget(input);

        widget3 = new QWidget(centralwidget);
        widget3->setObjectName(QString::fromUtf8("widget3"));
        widget3->setGeometry(QRect(650, 356, 95, 104));
        verticalLayout_5 = new QVBoxLayout(widget3);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(widget3);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout_5->addWidget(label_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        bytes8 = new QRadioButton(widget3);
        bytes8->setObjectName(QString::fromUtf8("bytes8"));

        verticalLayout_4->addWidget(bytes8);

        bytes16 = new QRadioButton(widget3);
        bytes16->setObjectName(QString::fromUtf8("bytes16"));

        verticalLayout_4->addWidget(bytes16);

        bytes32 = new QRadioButton(widget3);
        bytes32->setObjectName(QString::fromUtf8("bytes32"));

        verticalLayout_4->addWidget(bytes32);


        verticalLayout_5->addLayout(verticalLayout_4);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionCredits->setText(QCoreApplication::translate("MainWindow", "Credits", nullptr));
        actionCredits_2->setText(QCoreApplication::translate("MainWindow", "Credits", nullptr));
        run->setText(QCoreApplication::translate("MainWindow", "Run", nullptr));
        clear->setText(QCoreApplication::translate("MainWindow", "Clear", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Output", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Input", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Cell size:", nullptr));
        bytes8->setText(QCoreApplication::translate("MainWindow", "8 bytes", nullptr));
        bytes16->setText(QCoreApplication::translate("MainWindow", "16 bytes", nullptr));
        bytes32->setText(QCoreApplication::translate("MainWindow", "32 bytes", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
