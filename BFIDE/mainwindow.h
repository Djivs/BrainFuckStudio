#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vector>
#include <QPixmap>
#include <QMovie>
#include "memoryline.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_run_clicked();

    void on_bytes16_clicked();

    void on_bytes32_clicked();

    void on_bytes8_clicked();
    void on_clear_clicked();

    void on_viewMemoryLine_clicked();

    void on_prog_textChanged();

    void on_sep_no_clicked();

    void on_sep_space_clicked();

    void on_sep_nl_clicked();

private:

    char *separator = new char;

    void executeCode();
    MemoryLine *window;
    QPixmap pixmap;


    QString code;
    QString input;
    QString output = "";
    std::vector <long long int> line;
    long long int maxValue = 255;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
