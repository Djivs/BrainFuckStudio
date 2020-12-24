/*
 * Copyright 2020 Djivs
 * https://github.com/Djivs
 */
// default main.cpp, did not change it
#include <QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
