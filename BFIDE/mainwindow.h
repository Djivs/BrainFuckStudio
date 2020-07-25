/*
 * Written by Djivs, 2020
 * https://github.com/Djivs
 */
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPixmap>
#include <QMovie>
#include <algorithm>
#include <QThread>
#include <QTimer>
#include <QFontDialog>
#include <QFileDialog>
#include <QFile>
#include <QInputDialog>
#include "textwindow.h"
#include "codeexecuter.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    //constructor
    MainWindow(QWidget *parent = nullptr);
    //destructor
    ~MainWindow();

private slots:
    //function to update output while code is running
    void updateOut();



    //functions to end code exec/ errors check/ code convert
    void end_code_execution();

    void end_errors_checking();

    void end_code_converting();



    // start/end code execution
    void on_actionStart_Code_triggered();

    void on_actionEnd_Code_triggered();



    //save code to buffer/load code from bffer
    void on_actionSave_triggered();

    void on_actionLoad_triggered();



    //load example code
    void on_actionbeer_bf_triggered();

    void on_actioncellsize_bf_triggered();

    void on_actionhello_bf_triggered();

    void on_actionmandelbrot_tiny_bf_triggered();

    void on_actionmandelbrot_bf_triggered();

    void on_actionpidigits_bf_triggered();



    //choose color scheme
    void on_actionDark_triggered();

    void on_actionLight_triggered();



    //choose cell size
    void on_action8_byte_triggered();

    void on_action16_byte_triggered();

    void on_action32_byte_triggered();



    //open window with BF memory representation
    void on_actionView_memory_triggered();



    //ctart errors checking
    void on_actionCheck_Errors_triggered();



    //checng output/input/code editor/system font
    void on_actionOutput_triggered();

    void on_actionInput_triggered();

    void on_actionCode_buffer_triggered();

    void on_actionSystem_triggered();



    //save to/ load from file
    void on_actionSave_to_file_triggered();

    void on_actionLoad_from_file_triggered();



    //convert BF code to C
    void on_actionto_C_triggered();



    void on_actionOutput_uodate_frequency_triggered();



    void on_input_textChanged();



    void on_actionClear_input_triggered();

    void on_actionClear_code_triggered();

    void on_actionClear_output_triggered();

signals:
    //start code executing
    void startOperation();

    void startErrorsChecking();
    void startConvertToC();

private:
    //dates to calculate code execution time
    QDateTime start;
    QDateTime finish;

    //window for memory view/ code converting rusults
    TextWindow *textWindow;

    //loaging gif
    QMovie dots_loading;

    //main window
    Ui::MainWindow *ui;

    //class for code running
    CodeExecuter *worker;

    //thread for class above
    QThread *thread;

    //timer for output update
    QTimer *timer;

    //var for output update
    int outFreq = 10;
};
#endif // MAINWINDOW_H
