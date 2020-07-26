/********************************************************************************
** Form generated from reading UI file 'textwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEXTWINDOW_H
#define UI_TEXTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_TextWindow
{
public:
    QVBoxLayout *verticalLayout;
    QTextBrowser *textBrowser;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *load_file_button;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *TextWindow)
    {
        if (TextWindow->objectName().isEmpty())
            TextWindow->setObjectName(QString::fromUtf8("TextWindow"));
        TextWindow->resize(500, 346);
        verticalLayout = new QVBoxLayout(TextWindow);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        textBrowser = new QTextBrowser(TextWindow);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));

        verticalLayout->addWidget(textBrowser);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        load_file_button = new QPushButton(TextWindow);
        load_file_button->setObjectName(QString::fromUtf8("load_file_button"));
        load_file_button->setMouseTracking(false);
        load_file_button->setFlat(false);

        horizontalLayout->addWidget(load_file_button);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(TextWindow);

        load_file_button->setDefault(false);


        QMetaObject::connectSlotsByName(TextWindow);
    } // setupUi

    void retranslateUi(QDialog *TextWindow)
    {
        TextWindow->setWindowTitle(QCoreApplication::translate("TextWindow", "Dialog", nullptr));
        load_file_button->setText(QCoreApplication::translate("TextWindow", "Load to file", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TextWindow: public Ui_TextWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEXTWINDOW_H
