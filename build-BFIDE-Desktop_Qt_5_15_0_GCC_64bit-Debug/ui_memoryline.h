/********************************************************************************
** Form generated from reading UI file 'memoryline.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MEMORYLINE_H
#define UI_MEMORYLINE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_MemoryLine
{
public:
    QTextBrowser *memoryOutput;

    void setupUi(QDialog *MemoryLine)
    {
        if (MemoryLine->objectName().isEmpty())
            MemoryLine->setObjectName(QString::fromUtf8("MemoryLine"));
        MemoryLine->resize(400, 378);
        memoryOutput = new QTextBrowser(MemoryLine);
        memoryOutput->setObjectName(QString::fromUtf8("memoryOutput"));
        memoryOutput->setGeometry(QRect(10, 10, 371, 351));

        retranslateUi(MemoryLine);

        QMetaObject::connectSlotsByName(MemoryLine);
    } // setupUi

    void retranslateUi(QDialog *MemoryLine)
    {
        MemoryLine->setWindowTitle(QCoreApplication::translate("MemoryLine", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MemoryLine: public Ui_MemoryLine {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MEMORYLINE_H
