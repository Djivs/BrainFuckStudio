/*
 * Written by Djivs, 2020
 * https://github.com/Djivs
 */
//default main.cpp, did not change it
#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
