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
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QTextEdit *input;
    QPushButton *viewMemoryLine;
    QPushButton *run;
    QPushButton *clear;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_3;
    QRadioButton *bytes8;
    QRadioButton *bytes16;
    QRadioButton *bytes32;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QTextBrowser *output;
    QWidget *layoutWidget3;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_4;
    QTextEdit *prog;
    QLabel *label_loading;
    QLabel *label_status;
    QLabel *label_loadimg;
    QWidget *layoutWidget4;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_5;
    QRadioButton *sep_no;
    QRadioButton *sep_space;
    QRadioButton *sep_nl;
    QWidget *widget;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_6;
    QRadioButton *darkScheme;
    QRadioButton *lightScheme;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1146, 789);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color:rgb(46, 52, 54)"));
        actionCredits = new QAction(MainWindow);
        actionCredits->setObjectName(QString::fromUtf8("actionCredits"));
        actionCredits_2 = new QAction(MainWindow);
        actionCredits_2->setObjectName(QString::fromUtf8("actionCredits_2"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setStyleSheet(QString::fromUtf8("color: white"));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(850, 20, 258, 231));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QFont font;
        font.setFamily(QString::fromUtf8("DejaVu Sans"));
        font.setPointSize(15);
        font.setBold(true);
        font.setWeight(75);
        label_2->setFont(font);
        label_2->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_2->addWidget(label_2);

        input = new QTextEdit(layoutWidget);
        input->setObjectName(QString::fromUtf8("input"));
        input->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_2->addWidget(input);

        viewMemoryLine = new QPushButton(centralwidget);
        viewMemoryLine->setObjectName(QString::fromUtf8("viewMemoryLine"));
        viewMemoryLine->setGeometry(QRect(840, 440, 261, 41));
        QFont font1;
        font1.setFamily(QString::fromUtf8("DejaVu Serif"));
        font1.setBold(true);
        font1.setWeight(75);
        viewMemoryLine->setFont(font1);
        viewMemoryLine->setStyleSheet(QString::fromUtf8(""));
        run = new QPushButton(centralwidget);
        run->setObjectName(QString::fromUtf8("run"));
        run->setGeometry(QRect(850, 260, 241, 24));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Samyak Tamil"));
        font2.setBold(true);
        font2.setWeight(75);
        run->setFont(font2);
        run->setStyleSheet(QString::fromUtf8("color: rgb(78, 154, 6)"));
        clear = new QPushButton(centralwidget);
        clear->setObjectName(QString::fromUtf8("clear"));
        clear->setGeometry(QRect(20, 710, 256, 24));
        clear->setFont(font1);
        clear->setStyleSheet(QString::fromUtf8("color: rgb(204, 0, 0)"));
        layoutWidget1 = new QWidget(centralwidget);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(850, 310, 98, 114));
        layoutWidget1->setFont(font1);
        verticalLayout_4 = new QVBoxLayout(layoutWidget1);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(layoutWidget1);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font1);
        label_3->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_4->addWidget(label_3);

        bytes8 = new QRadioButton(layoutWidget1);
        bytes8->setObjectName(QString::fromUtf8("bytes8"));
        bytes8->setFont(font1);
        bytes8->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_4->addWidget(bytes8);

        bytes16 = new QRadioButton(layoutWidget1);
        bytes16->setObjectName(QString::fromUtf8("bytes16"));
        bytes16->setFont(font1);
        bytes16->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_4->addWidget(bytes16);

        bytes32 = new QRadioButton(layoutWidget1);
        bytes32->setObjectName(QString::fromUtf8("bytes32"));
        bytes32->setFont(font1);
        bytes32->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_4->addWidget(bytes32);

        layoutWidget2 = new QWidget(centralwidget);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(21, 17, 781, 216));
        verticalLayout = new QVBoxLayout(layoutWidget2);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8(""));

        verticalLayout->addWidget(label);

        output = new QTextBrowser(layoutWidget2);
        output->setObjectName(QString::fromUtf8("output"));
        output->setStyleSheet(QString::fromUtf8(""));
        output->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        output->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);

        verticalLayout->addWidget(output);

        layoutWidget3 = new QWidget(centralwidget);
        layoutWidget3->setObjectName(QString::fromUtf8("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(20, 250, 781, 441));
        verticalLayout_3 = new QVBoxLayout(layoutWidget3);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(layoutWidget3);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font);
        label_4->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_3->addWidget(label_4);

        prog = new QTextEdit(layoutWidget3);
        prog->setObjectName(QString::fromUtf8("prog"));
        prog->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_3->addWidget(prog);

        label_loading = new QLabel(centralwidget);
        label_loading->setObjectName(QString::fromUtf8("label_loading"));
        label_loading->setGeometry(QRect(840, 540, 111, 21));
        QFont font3;
        font3.setFamily(QString::fromUtf8("FreeMono"));
        font3.setBold(false);
        font3.setItalic(false);
        font3.setWeight(50);
        label_loading->setFont(font3);
        label_loading->setStyleSheet(QString::fromUtf8(""));
        label_status = new QLabel(centralwidget);
        label_status->setObjectName(QString::fromUtf8("label_status"));
        label_status->setGeometry(QRect(850, 520, 75, 16));
        QFont font4;
        font4.setFamily(QString::fromUtf8("Dyuthi"));
        font4.setPointSize(15);
        label_status->setFont(font4);
        label_status->setStyleSheet(QString::fromUtf8(""));
        label_loadimg = new QLabel(centralwidget);
        label_loadimg->setObjectName(QString::fromUtf8("label_loadimg"));
        label_loadimg->setGeometry(QRect(910, 510, 32, 32));
        layoutWidget4 = new QWidget(centralwidget);
        layoutWidget4->setObjectName(QString::fromUtf8("layoutWidget4"));
        layoutWidget4->setGeometry(QRect(980, 310, 134, 102));
        verticalLayout_5 = new QVBoxLayout(layoutWidget4);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(layoutWidget4);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_5->addWidget(label_5);

        sep_no = new QRadioButton(layoutWidget4);
        sep_no->setObjectName(QString::fromUtf8("sep_no"));

        verticalLayout_5->addWidget(sep_no);

        sep_space = new QRadioButton(layoutWidget4);
        sep_space->setObjectName(QString::fromUtf8("sep_space"));
        sep_space->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_5->addWidget(sep_space);

        sep_nl = new QRadioButton(layoutWidget4);
        sep_nl->setObjectName(QString::fromUtf8("sep_nl"));
        sep_nl->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_5->addWidget(sep_nl);

        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(990, 500, 118, 74));
        verticalLayout_6 = new QVBoxLayout(widget);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        label_6 = new QLabel(widget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        verticalLayout_6->addWidget(label_6);

        darkScheme = new QRadioButton(widget);
        darkScheme->setObjectName(QString::fromUtf8("darkScheme"));

        verticalLayout_6->addWidget(darkScheme);

        lightScheme = new QRadioButton(widget);
        lightScheme->setObjectName(QString::fromUtf8("lightScheme"));

        verticalLayout_6->addWidget(lightScheme);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1146, 21));
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
        label_2->setText(QCoreApplication::translate("MainWindow", "Input", nullptr));
        viewMemoryLine->setText(QCoreApplication::translate("MainWindow", "View memory line", nullptr));
        run->setText(QCoreApplication::translate("MainWindow", "Run", nullptr));
        clear->setText(QCoreApplication::translate("MainWindow", "Clear", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Cell size:", nullptr));
        bytes8->setText(QCoreApplication::translate("MainWindow", "8 bytes", nullptr));
        bytes16->setText(QCoreApplication::translate("MainWindow", "16 bytes", nullptr));
        bytes32->setText(QCoreApplication::translate("MainWindow", "32 bytes", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Output", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Edit code:", nullptr));
        prog->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Consolas'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        label_loading->setText(QCoreApplication::translate("MainWindow", "text editing", nullptr));
        label_status->setText(QCoreApplication::translate("MainWindow", "Status:", nullptr));
        label_loadimg->setText(QString());
        label_5->setText(QCoreApplication::translate("MainWindow", "Input separator:", nullptr));
        sep_no->setText(QCoreApplication::translate("MainWindow", "No", nullptr));
        sep_space->setText(QCoreApplication::translate("MainWindow", "Space", nullptr));
        sep_nl->setText(QCoreApplication::translate("MainWindow", "New line", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Color scheme:", nullptr));
        darkScheme->setText(QCoreApplication::translate("MainWindow", "Dark", nullptr));
        lightScheme->setText(QCoreApplication::translate("MainWindow", "Light", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
