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
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionStart_Code;
    QAction *actionEnd_Code;
    QAction *actionSave;
    QAction *actionLoad;
    QAction *actionbeer_bf;
    QAction *actioncellsize_bf;
    QAction *actionhello_bf;
    QAction *actionmandelbrot_tiny_bf;
    QAction *actionmandelbrot_bf;
    QAction *actionpidigits_bf;
    QAction *actionDark;
    QAction *actionLight;
    QAction *action8_byte;
    QAction *action16_byte;
    QAction *action32_byte;
    QAction *actionView_memory;
    QAction *actionCheck_Errors;
    QAction *actionOutput;
    QAction *actionInput;
    QAction *actionCode_buffer;
    QAction *actionSystem;
    QAction *actionLoad_from_file;
    QAction *actionSave_to_file;
    QAction *actionto_C;
    QAction *actiontext_to_code;
    QAction *actionOutput_uodate_frequency;
    QAction *actionClear_output;
    QAction *actionClear_code;
    QAction *actionClear_input;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_4;
    QSplitter *splitter_2;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label_output;
    QTextBrowser *output;
    QSplitter *splitter;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label_edit_code;
    QLabel *label_loadimg;
    QSpacerItem *horizontalSpacer;
    QTextEdit *prog;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_input;
    QTextEdit *input;
    QMenuBar *menubar;
    QMenu *menuEdit_Code;
    QMenu *menuLoad_Example;
    QMenu *menuClear;
    QMenu *menuStyle;
    QMenu *menuColor_scheme;
    QMenu *menuText_settings;
    QMenu *menuInterpreter;
    QMenu *menuCell_Size;
    QMenu *menuConvert;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1146, 789);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/res/img/logo.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setStyleSheet(QString::fromUtf8("color: white; background-color: rgb(46, 52, 54)"));
        actionStart_Code = new QAction(MainWindow);
        actionStart_Code->setObjectName(QString::fromUtf8("actionStart_Code"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/res/img/green_start.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionStart_Code->setIcon(icon1);
        actionEnd_Code = new QAction(MainWindow);
        actionEnd_Code->setObjectName(QString::fromUtf8("actionEnd_Code"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/res/img/red_stop.jpeg"), QSize(), QIcon::Normal, QIcon::Off);
        actionEnd_Code->setIcon(icon2);
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        actionLoad = new QAction(MainWindow);
        actionLoad->setObjectName(QString::fromUtf8("actionLoad"));
        actionbeer_bf = new QAction(MainWindow);
        actionbeer_bf->setObjectName(QString::fromUtf8("actionbeer_bf"));
        actioncellsize_bf = new QAction(MainWindow);
        actioncellsize_bf->setObjectName(QString::fromUtf8("actioncellsize_bf"));
        actionhello_bf = new QAction(MainWindow);
        actionhello_bf->setObjectName(QString::fromUtf8("actionhello_bf"));
        actionmandelbrot_tiny_bf = new QAction(MainWindow);
        actionmandelbrot_tiny_bf->setObjectName(QString::fromUtf8("actionmandelbrot_tiny_bf"));
        actionmandelbrot_bf = new QAction(MainWindow);
        actionmandelbrot_bf->setObjectName(QString::fromUtf8("actionmandelbrot_bf"));
        actionpidigits_bf = new QAction(MainWindow);
        actionpidigits_bf->setObjectName(QString::fromUtf8("actionpidigits_bf"));
        actionDark = new QAction(MainWindow);
        actionDark->setObjectName(QString::fromUtf8("actionDark"));
        actionDark->setCheckable(true);
        actionLight = new QAction(MainWindow);
        actionLight->setObjectName(QString::fromUtf8("actionLight"));
        actionLight->setCheckable(true);
        action8_byte = new QAction(MainWindow);
        action8_byte->setObjectName(QString::fromUtf8("action8_byte"));
        action8_byte->setCheckable(true);
        action16_byte = new QAction(MainWindow);
        action16_byte->setObjectName(QString::fromUtf8("action16_byte"));
        action16_byte->setCheckable(true);
        action32_byte = new QAction(MainWindow);
        action32_byte->setObjectName(QString::fromUtf8("action32_byte"));
        action32_byte->setCheckable(true);
        actionView_memory = new QAction(MainWindow);
        actionView_memory->setObjectName(QString::fromUtf8("actionView_memory"));
        actionCheck_Errors = new QAction(MainWindow);
        actionCheck_Errors->setObjectName(QString::fromUtf8("actionCheck_Errors"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/res/img/errors.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCheck_Errors->setIcon(icon3);
        actionOutput = new QAction(MainWindow);
        actionOutput->setObjectName(QString::fromUtf8("actionOutput"));
        actionInput = new QAction(MainWindow);
        actionInput->setObjectName(QString::fromUtf8("actionInput"));
        actionCode_buffer = new QAction(MainWindow);
        actionCode_buffer->setObjectName(QString::fromUtf8("actionCode_buffer"));
        actionSystem = new QAction(MainWindow);
        actionSystem->setObjectName(QString::fromUtf8("actionSystem"));
        actionLoad_from_file = new QAction(MainWindow);
        actionLoad_from_file->setObjectName(QString::fromUtf8("actionLoad_from_file"));
        actionSave_to_file = new QAction(MainWindow);
        actionSave_to_file->setObjectName(QString::fromUtf8("actionSave_to_file"));
        actionto_C = new QAction(MainWindow);
        actionto_C->setObjectName(QString::fromUtf8("actionto_C"));
        actiontext_to_code = new QAction(MainWindow);
        actiontext_to_code->setObjectName(QString::fromUtf8("actiontext_to_code"));
        actionOutput_uodate_frequency = new QAction(MainWindow);
        actionOutput_uodate_frequency->setObjectName(QString::fromUtf8("actionOutput_uodate_frequency"));
        actionClear_output = new QAction(MainWindow);
        actionClear_output->setObjectName(QString::fromUtf8("actionClear_output"));
        actionClear_code = new QAction(MainWindow);
        actionClear_code->setObjectName(QString::fromUtf8("actionClear_code"));
        actionClear_input = new QAction(MainWindow);
        actionClear_input->setObjectName(QString::fromUtf8("actionClear_input"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setStyleSheet(QString::fromUtf8("color: white"));
        verticalLayout_4 = new QVBoxLayout(centralwidget);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        splitter_2 = new QSplitter(centralwidget);
        splitter_2->setObjectName(QString::fromUtf8("splitter_2"));
        splitter_2->setOrientation(Qt::Vertical);
        layoutWidget = new QWidget(splitter_2);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_output = new QLabel(layoutWidget);
        label_output->setObjectName(QString::fromUtf8("label_output"));
        QFont font;
        font.setFamily(QString::fromUtf8("DejaVu Sans"));
        font.setPointSize(15);
        font.setBold(true);
        font.setWeight(75);
        label_output->setFont(font);
        label_output->setStyleSheet(QString::fromUtf8(""));

        verticalLayout->addWidget(label_output);

        output = new QTextBrowser(layoutWidget);
        output->setObjectName(QString::fromUtf8("output"));
        QFont font1;
        font1.setPointSize(11);
        output->setFont(font1);
        output->setStyleSheet(QString::fromUtf8(""));
        output->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        output->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);

        verticalLayout->addWidget(output);

        splitter_2->addWidget(layoutWidget);
        splitter = new QSplitter(splitter_2);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        layoutWidget1 = new QWidget(splitter);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        verticalLayout_2 = new QVBoxLayout(layoutWidget1);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_edit_code = new QLabel(layoutWidget1);
        label_edit_code->setObjectName(QString::fromUtf8("label_edit_code"));
        label_edit_code->setFont(font);
        label_edit_code->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout->addWidget(label_edit_code);

        label_loadimg = new QLabel(layoutWidget1);
        label_loadimg->setObjectName(QString::fromUtf8("label_loadimg"));

        horizontalLayout->addWidget(label_loadimg);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout_2->addLayout(horizontalLayout);

        prog = new QTextEdit(layoutWidget1);
        prog->setObjectName(QString::fromUtf8("prog"));
        prog->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_2->addWidget(prog);

        splitter->addWidget(layoutWidget1);
        layoutWidget2 = new QWidget(splitter);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        verticalLayout_3 = new QVBoxLayout(layoutWidget2);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_input = new QLabel(layoutWidget2);
        label_input->setObjectName(QString::fromUtf8("label_input"));
        label_input->setFont(font);
        label_input->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_3->addWidget(label_input);

        input = new QTextEdit(layoutWidget2);
        input->setObjectName(QString::fromUtf8("input"));
        input->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_3->addWidget(input);

        splitter->addWidget(layoutWidget2);
        splitter_2->addWidget(splitter);

        verticalLayout_4->addWidget(splitter_2);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1146, 21));
        menubar->setStyleSheet(QString::fromUtf8("color: white; background-color: rgb(46, 52, 54)"));
        menuEdit_Code = new QMenu(menubar);
        menuEdit_Code->setObjectName(QString::fromUtf8("menuEdit_Code"));
        menuLoad_Example = new QMenu(menuEdit_Code);
        menuLoad_Example->setObjectName(QString::fromUtf8("menuLoad_Example"));
        menuClear = new QMenu(menuEdit_Code);
        menuClear->setObjectName(QString::fromUtf8("menuClear"));
        menuStyle = new QMenu(menubar);
        menuStyle->setObjectName(QString::fromUtf8("menuStyle"));
        menuColor_scheme = new QMenu(menuStyle);
        menuColor_scheme->setObjectName(QString::fromUtf8("menuColor_scheme"));
        menuText_settings = new QMenu(menuStyle);
        menuText_settings->setObjectName(QString::fromUtf8("menuText_settings"));
        menuInterpreter = new QMenu(menubar);
        menuInterpreter->setObjectName(QString::fromUtf8("menuInterpreter"));
        menuCell_Size = new QMenu(menuInterpreter);
        menuCell_Size->setObjectName(QString::fromUtf8("menuCell_Size"));
        menuConvert = new QMenu(menubar);
        menuConvert->setObjectName(QString::fromUtf8("menuConvert"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        menubar->addAction(menuEdit_Code->menuAction());
        menubar->addAction(menuStyle->menuAction());
        menubar->addAction(menuInterpreter->menuAction());
        menubar->addAction(menuConvert->menuAction());
        menuEdit_Code->addSeparator();
        menuEdit_Code->addAction(menuClear->menuAction());
        menuEdit_Code->addSeparator();
        menuEdit_Code->addAction(actionSave);
        menuEdit_Code->addSeparator();
        menuEdit_Code->addAction(actionLoad);
        menuEdit_Code->addSeparator();
        menuEdit_Code->addAction(menuLoad_Example->menuAction());
        menuEdit_Code->addSeparator();
        menuEdit_Code->addAction(actionLoad_from_file);
        menuEdit_Code->addSeparator();
        menuEdit_Code->addAction(actionSave_to_file);
        menuLoad_Example->addSeparator();
        menuLoad_Example->addAction(actionbeer_bf);
        menuLoad_Example->addSeparator();
        menuLoad_Example->addAction(actioncellsize_bf);
        menuLoad_Example->addSeparator();
        menuLoad_Example->addAction(actionhello_bf);
        menuLoad_Example->addSeparator();
        menuLoad_Example->addAction(actionmandelbrot_tiny_bf);
        menuLoad_Example->addSeparator();
        menuLoad_Example->addAction(actionmandelbrot_bf);
        menuLoad_Example->addSeparator();
        menuLoad_Example->addAction(actionpidigits_bf);
        menuClear->addAction(actionClear_output);
        menuClear->addAction(actionClear_code);
        menuClear->addAction(actionClear_input);
        menuStyle->addSeparator();
        menuStyle->addSeparator();
        menuStyle->addAction(menuColor_scheme->menuAction());
        menuStyle->addSeparator();
        menuStyle->addAction(menuText_settings->menuAction());
        menuStyle->addAction(actionOutput_uodate_frequency);
        menuColor_scheme->addAction(actionDark);
        menuColor_scheme->addAction(actionLight);
        menuText_settings->addSeparator();
        menuText_settings->addAction(actionOutput);
        menuText_settings->addSeparator();
        menuText_settings->addAction(actionInput);
        menuText_settings->addSeparator();
        menuText_settings->addAction(actionCode_buffer);
        menuText_settings->addSeparator();
        menuText_settings->addAction(actionSystem);
        menuInterpreter->addSeparator();
        menuInterpreter->addAction(menuCell_Size->menuAction());
        menuInterpreter->addSeparator();
        menuInterpreter->addAction(actionView_memory);
        menuCell_Size->addAction(action8_byte);
        menuCell_Size->addAction(action16_byte);
        menuCell_Size->addAction(action32_byte);
        menuConvert->addAction(actionto_C);
        menuConvert->addAction(actiontext_to_code);
        toolBar->addAction(actionStart_Code);
        toolBar->addAction(actionEnd_Code);
        toolBar->addAction(actionCheck_Errors);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "BrainFuckStudio v2.2", nullptr));
        actionStart_Code->setText(QCoreApplication::translate("MainWindow", "Start Code", nullptr));
#if QT_CONFIG(shortcut)
        actionStart_Code->setShortcut(QCoreApplication::translate("MainWindow", "F5", nullptr));
#endif // QT_CONFIG(shortcut)
        actionEnd_Code->setText(QCoreApplication::translate("MainWindow", "End Code", nullptr));
        actionSave->setText(QCoreApplication::translate("MainWindow", "Save to buffer", nullptr));
#if QT_CONFIG(shortcut)
        actionSave->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+S", nullptr));
#endif // QT_CONFIG(shortcut)
        actionLoad->setText(QCoreApplication::translate("MainWindow", "Load from buffer", nullptr));
        actionbeer_bf->setText(QCoreApplication::translate("MainWindow", "beer.bf", nullptr));
        actioncellsize_bf->setText(QCoreApplication::translate("MainWindow", "cellsize.bf", nullptr));
        actionhello_bf->setText(QCoreApplication::translate("MainWindow", "hello.bf", nullptr));
        actionmandelbrot_tiny_bf->setText(QCoreApplication::translate("MainWindow", "mandelbrot-tiny.bf", nullptr));
        actionmandelbrot_bf->setText(QCoreApplication::translate("MainWindow", "mandelbrot.bf", nullptr));
        actionpidigits_bf->setText(QCoreApplication::translate("MainWindow", "pidigits.bf", nullptr));
        actionDark->setText(QCoreApplication::translate("MainWindow", "Dark", nullptr));
        actionLight->setText(QCoreApplication::translate("MainWindow", "Light", nullptr));
        action8_byte->setText(QCoreApplication::translate("MainWindow", "8 bit", nullptr));
        action16_byte->setText(QCoreApplication::translate("MainWindow", "16 bit", nullptr));
        action32_byte->setText(QCoreApplication::translate("MainWindow", "32 bit", nullptr));
        actionView_memory->setText(QCoreApplication::translate("MainWindow", "View memory", nullptr));
        actionCheck_Errors->setText(QCoreApplication::translate("MainWindow", "Check Errors", nullptr));
        actionOutput->setText(QCoreApplication::translate("MainWindow", "Output", nullptr));
        actionInput->setText(QCoreApplication::translate("MainWindow", "Input", nullptr));
        actionCode_buffer->setText(QCoreApplication::translate("MainWindow", "Code buffer", nullptr));
        actionSystem->setText(QCoreApplication::translate("MainWindow", "System", nullptr));
        actionLoad_from_file->setText(QCoreApplication::translate("MainWindow", "Load from file", nullptr));
        actionSave_to_file->setText(QCoreApplication::translate("MainWindow", "Save to file", nullptr));
        actionto_C->setText(QCoreApplication::translate("MainWindow", "code to C", nullptr));
        actiontext_to_code->setText(QCoreApplication::translate("MainWindow", "text to code", nullptr));
        actionOutput_uodate_frequency->setText(QCoreApplication::translate("MainWindow", "Output update frequency", nullptr));
        actionClear_output->setText(QCoreApplication::translate("MainWindow", "Clear output", nullptr));
        actionClear_code->setText(QCoreApplication::translate("MainWindow", "Clear code", nullptr));
        actionClear_input->setText(QCoreApplication::translate("MainWindow", "Clear input", nullptr));
        label_output->setText(QCoreApplication::translate("MainWindow", "Output", nullptr));
        label_edit_code->setText(QCoreApplication::translate("MainWindow", "Edit code:", nullptr));
        label_loadimg->setText(QString());
        prog->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Consolas'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        label_input->setText(QCoreApplication::translate("MainWindow", "Input", nullptr));
        menuEdit_Code->setTitle(QCoreApplication::translate("MainWindow", "Edit", nullptr));
        menuLoad_Example->setTitle(QCoreApplication::translate("MainWindow", "Load Example", nullptr));
        menuClear->setTitle(QCoreApplication::translate("MainWindow", "Clear", nullptr));
        menuStyle->setTitle(QCoreApplication::translate("MainWindow", "View", nullptr));
        menuColor_scheme->setTitle(QCoreApplication::translate("MainWindow", "Color scheme", nullptr));
        menuText_settings->setTitle(QCoreApplication::translate("MainWindow", "Text settings", nullptr));
        menuInterpreter->setTitle(QCoreApplication::translate("MainWindow", "Interpreter", nullptr));
        menuCell_Size->setTitle(QCoreApplication::translate("MainWindow", "Cell Size", nullptr));
        menuConvert->setTitle(QCoreApplication::translate("MainWindow", "Convert", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
