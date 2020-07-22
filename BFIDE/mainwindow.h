#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vector>
#include <QPixmap>
#include <QMovie>
#include <algorithm>
#include <QThread>
#include <QTimer>
#include <QFontDialog>
#include <QFileDialog>
#include <QFile>
#include "textwindow.h"
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
    void setLine(std::vector<long int> newLine) {line = newLine;};
    void setCode(QString newCode) {code = newCode;};
    void setMaxValue(unsigned int newMaxValue) {maxValue = newMaxValue;};
    void setInput(QString newInput){input = newInput;};
    void setOutput(QString newOutput) {output = newOutput;};
    //getters
    QString getOutput() const {return output;};
    bool getEndCode() const {return endCode;};
    std::vector <long int> getLine() const {return line;};
    QString getConvertedCCode() const {return convertedCCode;};
private slots:
    void convertToC();
    void runCode();
    void checkErrors();
signals:
    void codeConverted();
    void codeExecuted();
    void errorsChecked();
private:
    QString convertedCCode;
    void parseCode();
    volatile bool endCode = 1;
    std::vector <long int> line;
    std::vector <int> openPos;
    enum CMD {NOT, ADD, MOV, GET, PUT, GOTO, ZERO};
    std::vector <CMD> commands;
    std::vector <int> args;
    long int maxValue = 255;
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

    void end_errors_checking();

    void end_code_converting();

    void on_prog_textChanged();

    void on_actionStart_Code_triggered();

    void on_actionEnd_Code_triggered();

    void on_actionClear_triggered();

    void on_actionSave_triggered();

    void on_actionLoad_triggered();

    void on_actionbeer_bf_triggered();

    void on_actioncellsize_bf_triggered();

    void on_actionhello_bf_triggered();

    void on_actionmandelbrot_tiny_bf_triggered();

    void on_actionmandelbrot_bf_triggered();

    void on_actionpidigits_bf_triggered();

    void on_actionDark_triggered();

    void on_actionLight_triggered();

    void on_action8_byte_triggered();

    void on_action16_byte_triggered();

    void on_action32_byte_triggered();

    void on_actionView_memory_triggered();

    void on_actionCheck_Errors_triggered();

    void on_actionOutput_triggered();

    void on_actionInput_triggered();

    void on_actionCode_buffer_triggered();

    void on_actionSystem_triggered();

    void on_actionSave_to_file_triggered();

    void on_actionLoad_from_file_triggered();

    void on_actionto_C_triggered();

signals:
    void startOperation();
    void startErrorsChecking();
    void startConvertToC();

private:
    QDateTime start;
    QDateTime finish;
    //window with memory view
    TextWindow *textWindow;
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
