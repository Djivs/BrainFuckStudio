#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vector>

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

private:
    QString code;
    QString input;
    QString output = "";
    std::vector<char> line;
    void executeCode();
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
