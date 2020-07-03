/********************************************************************************
** Form generated from reading UI file 'loading.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOADING_H
#define UI_LOADING_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_Loading
{
public:
    QLabel *loadgif;
    QLabel *label_loading;

    void setupUi(QDialog *Loading)
    {
        if (Loading->objectName().isEmpty())
            Loading->setObjectName(QString::fromUtf8("Loading"));
        Loading->resize(400, 300);
        loadgif = new QLabel(Loading);
        loadgif->setObjectName(QString::fromUtf8("loadgif"));
        loadgif->setGeometry(QRect(90, 120, 181, 111));
        label_loading = new QLabel(Loading);
        label_loading->setObjectName(QString::fromUtf8("label_loading"));
        label_loading->setGeometry(QRect(140, 30, 75, 16));

        retranslateUi(Loading);

        QMetaObject::connectSlotsByName(Loading);
    } // setupUi

    void retranslateUi(QDialog *Loading)
    {
        Loading->setWindowTitle(QCoreApplication::translate("Loading", "Dialog", nullptr));
        loadgif->setText(QString());
        label_loading->setText(QCoreApplication::translate("Loading", "loading", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Loading: public Ui_Loading {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOADING_H
