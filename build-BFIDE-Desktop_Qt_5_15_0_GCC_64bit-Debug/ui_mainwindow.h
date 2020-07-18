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
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionStart_Code;
    QAction *actionEnd_Code;
    QAction *actionClear;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_8;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QTextBrowser *output;
    QSplitter *splitter;
    QWidget *widget;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_4;
    QTextEdit *prog;
    QWidget *widget1;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_2;
    QTextEdit *input;
    QHBoxLayout *horizontalLayout_2;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_4;
    QRadioButton *bytes8;
    QRadioButton *bytes16;
    QRadioButton *bytes32;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_3;
    QRadioButton *sep_no;
    QRadioButton *sep_space;
    QRadioButton *sep_nl;
    QPushButton *viewMemoryLine;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_loadimg;
    QLabel *label_status;
    QLabel *label_loading;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_2;
    QRadioButton *darkScheme;
    QRadioButton *lightScheme;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuEdit_Code;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1146, 789);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color:rgb(46, 52, 54)"));
        actionStart_Code = new QAction(MainWindow);
        actionStart_Code->setObjectName(QString::fromUtf8("actionStart_Code"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/img/green_start.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionStart_Code->setIcon(icon);
        actionEnd_Code = new QAction(MainWindow);
        actionEnd_Code->setObjectName(QString::fromUtf8("actionEnd_Code"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/img/red_stop.jpeg"), QSize(), QIcon::Normal, QIcon::Off);
        actionEnd_Code->setIcon(icon1);
        actionClear = new QAction(MainWindow);
        actionClear->setObjectName(QString::fromUtf8("actionClear"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setStyleSheet(QString::fromUtf8("color: white"));
        verticalLayout_8 = new QVBoxLayout(centralwidget);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setFamily(QString::fromUtf8("DejaVu Sans"));
        font.setPointSize(15);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8(""));

        verticalLayout->addWidget(label);

        output = new QTextBrowser(centralwidget);
        output->setObjectName(QString::fromUtf8("output"));
        output->setStyleSheet(QString::fromUtf8(""));
        output->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        output->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);

        verticalLayout->addWidget(output);


        verticalLayout_8->addLayout(verticalLayout);

        splitter = new QSplitter(centralwidget);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        widget = new QWidget(splitter);
        widget->setObjectName(QString::fromUtf8("widget"));
        verticalLayout_7 = new QVBoxLayout(widget);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font);
        label_4->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_7->addWidget(label_4);

        prog = new QTextEdit(widget);
        prog->setObjectName(QString::fromUtf8("prog"));
        prog->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_7->addWidget(prog);

        splitter->addWidget(widget);
        widget1 = new QWidget(splitter);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        verticalLayout_6 = new QVBoxLayout(widget1);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(widget1);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);
        label_2->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_6->addWidget(label_2);

        input = new QTextEdit(widget1);
        input->setObjectName(QString::fromUtf8("input"));
        input->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_6->addWidget(input);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        groupBox = new QGroupBox(widget1);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout_4 = new QVBoxLayout(groupBox);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        bytes8 = new QRadioButton(groupBox);
        bytes8->setObjectName(QString::fromUtf8("bytes8"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("DejaVu Serif"));
        font1.setPointSize(11);
        font1.setBold(true);
        font1.setWeight(75);
        bytes8->setFont(font1);
        bytes8->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_4->addWidget(bytes8);

        bytes16 = new QRadioButton(groupBox);
        bytes16->setObjectName(QString::fromUtf8("bytes16"));
        bytes16->setFont(font1);
        bytes16->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_4->addWidget(bytes16);

        bytes32 = new QRadioButton(groupBox);
        bytes32->setObjectName(QString::fromUtf8("bytes32"));
        bytes32->setFont(font1);
        bytes32->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_4->addWidget(bytes32);


        horizontalLayout_2->addWidget(groupBox);

        groupBox_2 = new QGroupBox(widget1);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        verticalLayout_3 = new QVBoxLayout(groupBox_2);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        sep_no = new QRadioButton(groupBox_2);
        sep_no->setObjectName(QString::fromUtf8("sep_no"));

        verticalLayout_3->addWidget(sep_no);

        sep_space = new QRadioButton(groupBox_2);
        sep_space->setObjectName(QString::fromUtf8("sep_space"));
        sep_space->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_3->addWidget(sep_space);

        sep_nl = new QRadioButton(groupBox_2);
        sep_nl->setObjectName(QString::fromUtf8("sep_nl"));
        sep_nl->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_3->addWidget(sep_nl);


        horizontalLayout_2->addWidget(groupBox_2);


        verticalLayout_6->addLayout(horizontalLayout_2);

        viewMemoryLine = new QPushButton(widget1);
        viewMemoryLine->setObjectName(QString::fromUtf8("viewMemoryLine"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("DejaVu Serif"));
        font2.setBold(true);
        font2.setWeight(75);
        viewMemoryLine->setFont(font2);
        viewMemoryLine->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_6->addWidget(viewMemoryLine);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        label_loadimg = new QLabel(widget1);
        label_loadimg->setObjectName(QString::fromUtf8("label_loadimg"));

        verticalLayout_5->addWidget(label_loadimg);

        label_status = new QLabel(widget1);
        label_status->setObjectName(QString::fromUtf8("label_status"));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Dyuthi"));
        font3.setPointSize(15);
        label_status->setFont(font3);
        label_status->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_5->addWidget(label_status);

        label_loading = new QLabel(widget1);
        label_loading->setObjectName(QString::fromUtf8("label_loading"));
        QFont font4;
        font4.setFamily(QString::fromUtf8("FreeMono"));
        font4.setBold(false);
        font4.setItalic(false);
        font4.setWeight(50);
        label_loading->setFont(font4);
        label_loading->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_5->addWidget(label_loading);


        horizontalLayout->addLayout(verticalLayout_5);

        groupBox_3 = new QGroupBox(widget1);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        verticalLayout_2 = new QVBoxLayout(groupBox_3);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        darkScheme = new QRadioButton(groupBox_3);
        darkScheme->setObjectName(QString::fromUtf8("darkScheme"));

        verticalLayout_2->addWidget(darkScheme);

        lightScheme = new QRadioButton(groupBox_3);
        lightScheme->setObjectName(QString::fromUtf8("lightScheme"));

        verticalLayout_2->addWidget(lightScheme);


        horizontalLayout->addWidget(groupBox_3);


        verticalLayout_6->addLayout(horizontalLayout);

        splitter->addWidget(widget1);

        verticalLayout_8->addWidget(splitter);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1146, 21));
        menubar->setStyleSheet(QString::fromUtf8("color: white; background-color: rgb(46, 52, 54)"));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuEdit_Code = new QMenu(menubar);
        menuEdit_Code->setObjectName(QString::fromUtf8("menuEdit_Code"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuEdit_Code->menuAction());
        menuFile->addAction(actionStart_Code);
        menuFile->addAction(actionEnd_Code);
        menuEdit_Code->addAction(actionClear);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionStart_Code->setText(QCoreApplication::translate("MainWindow", "Start Code", nullptr));
#if QT_CONFIG(shortcut)
        actionStart_Code->setShortcut(QCoreApplication::translate("MainWindow", "F5", nullptr));
#endif // QT_CONFIG(shortcut)
        actionEnd_Code->setText(QCoreApplication::translate("MainWindow", "End Code", nullptr));
        actionClear->setText(QCoreApplication::translate("MainWindow", "Clear", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Output", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Edit code:", nullptr));
        prog->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Consolas'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Input", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "Cell Size", nullptr));
        bytes8->setText(QCoreApplication::translate("MainWindow", "8 bytes", nullptr));
        bytes16->setText(QCoreApplication::translate("MainWindow", "16 bytes", nullptr));
        bytes32->setText(QCoreApplication::translate("MainWindow", "32 bytes", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "Input Separator:", nullptr));
        sep_no->setText(QCoreApplication::translate("MainWindow", "No", nullptr));
        sep_space->setText(QCoreApplication::translate("MainWindow", "Space", nullptr));
        sep_nl->setText(QCoreApplication::translate("MainWindow", "New line", nullptr));
        viewMemoryLine->setText(QCoreApplication::translate("MainWindow", "View memory line", nullptr));
        label_loadimg->setText(QString());
        label_status->setText(QCoreApplication::translate("MainWindow", "Status:", nullptr));
        label_loading->setText(QCoreApplication::translate("MainWindow", "text editing", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("MainWindow", "Color Scheme", nullptr));
        darkScheme->setText(QCoreApplication::translate("MainWindow", "Dark", nullptr));
        lightScheme->setText(QCoreApplication::translate("MainWindow", "Light", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "Execute", nullptr));
        menuEdit_Code->setTitle(QCoreApplication::translate("MainWindow", "Edit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
