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

class CodeExecuter : public QObject
{
    Q_OBJECT
public:
    //constructor
    explicit CodeExecuter(QObject *parent = 0);
    //destructor
    ~CodeExecuter() {};
    //setters
    void setEndCode(bool t){endCode = t;};
    void setLine(std::vector<long long int> newLine) {line = newLine;};
    void setSeparator(char newSeparator) {separator = newSeparator;};
    void setCode(QString newCode) {code = newCode;};
    void setMaxValue(long long int newMaxValue) {maxValue = newMaxValue;};
    void setInput(QString newInput){input = newInput;};
    void setOutput(QString newOutput) {output = newOutput;};
    //getters
    QString getOutput() const {return output;};
    bool getEndCode() const {return endCode;};
    std::vector <long long int> getLine() const {return line;};
private slots:
    void runCode();
signals:
    void codeExecuted();
private:
    enum CMD {ADD, MOVE, SCAN, PRINT, GOTO};
    void solveCode();
    volatile bool endCode = 1;
    std::vector <long long int> line;
    std::vector <CMD> commands;
    std::vector <int> times;
    long long int maxValue = 255;
    char separator = ' ';
    QString code;
    QString output;
    QString input;
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void updateOut();

    void end_code_execution();

    void on_bytes16_clicked();

    void on_bytes32_clicked();

    void on_bytes8_clicked();

    void on_viewMemoryLine_clicked();

    void on_prog_textChanged();

    void on_sep_space_clicked();

    void on_sep_nl_clicked();

    void on_darkScheme_clicked();

    void on_lightScheme_clicked();

    void on_sep_no_clicked();

    void on_actionStart_Code_triggered();

    void on_actionEnd_Code_triggered();

    void on_actionClear_triggered();

signals:
    void startOperation();

private:
    QDateTime start;
    QDateTime finish;
    //window with memory view
    MemoryLine *window;
    //loaging gif
    QMovie dots_loading;
    //main window
    Ui::MainWindow *ui;
    //class for code running
    CodeExecuter *worker;
    //thread for class above
    QThread *thread;
    QTimer *timer;
};
#endif // MAINWINDOW_H
