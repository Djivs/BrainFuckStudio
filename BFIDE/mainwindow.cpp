#include "mainwindow.h"
#include "ui_mainwindow.h"
//main window constructor
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), dots_loading(":/res/img/loading.gif")
    , ui(new Ui::MainWindow)
{
    //main window setup
    ui->setupUi(this);


    //create thread for code executing
    thread = new QThread(this);
    connect(this, SIGNAL(destroyed()), thread, SLOT(quit()));


    //create code executer object
    worker = new CodeExecuter();
    timer = new QTimer;


    //connect signals
    connect(worker, SIGNAL(codeExecuted()), this, SLOT(end_code_execution()));
    connect(this, SIGNAL(startOperation()), worker, SLOT(runCode()));
    connect(timer, SIGNAL(timeout()), this, SLOT(updateOut()));
    connect(this, SIGNAL(startErrorsChecking()), worker, SLOT(checkErrors()));
    connect(worker, SIGNAL(errorsChecked()), this, SLOT(end_errors_checking()));
    connect(this, SIGNAL(startConvertToC()), worker, SLOT(convertToC()));
    connect(worker, SIGNAL(codeConverted()), this, SLOT(end_code_converting()));

    //move worker to created thread and start it
    worker->moveToThread(thread);
    thread->start();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::end_errors_checking()
{
    //stop loading gif
    dots_loading.stop();
    //delete loading gif from the screen
    ui->label_loadimg->clear();
    ui->statusbar->showMessage("errors checked");
    ui->output->setText(worker->getOutput());
}

//function to dynamicly update code while code execution
void MainWindow::updateOut()
{
    ui->output->setText(worker->getOutput());
    ui->output->repaint();
}
//function to end code execution
void MainWindow::end_code_execution()
{
    finish =  QDateTime::currentDateTime();
    int secs = start.msecsTo(finish)/10;
    //stop loading gif
    dots_loading.stop();
    //delete loading gif from the screen
    ui->label_loadimg->clear();
    //change status
    ui->statusbar->showMessage("executed in\n" + QString::number((float)secs/100.0) + 's');
    //set output
    ui->output->setText(worker->getOutput());
    timer->stop();
    worker->setEndCode(1);
    repaint();

}

void MainWindow::on_prog_textChanged()
{
    if(ui->statusbar->currentMessage() != "loading")
        ui->statusbar->showMessage("text editing");
}
//function to start code executing
void MainWindow::on_actionStart_Code_triggered()
{
    if(!(worker->getEndCode()))
        return;
    //show loading//
    ui->statusbar->showMessage("loading");
    ui->label_loadimg->setMovie(&dots_loading);
    dots_loading.start();
    repaint();
    //load code text to worker
    worker->setCode(ui->prog->toPlainText());
    //load input to worker
    worker->setInput(ui->input->toPlainText());
    //run code
    worker->setOutput("");
    worker->setEndCode(0);
    emit startOperation();
    timer->start(10);
    start =  QDateTime::currentDateTime();
}

//function to stop code executing
void MainWindow::on_actionEnd_Code_triggered()
{
     worker->setEndCode(1);
}

//function to clear types text
void MainWindow::on_actionClear_triggered()
{
    ui->prog->setText("");
}

//function to save typed text to input.txt file
void MainWindow::on_actionSave_triggered()
{
    QFile file("txt/input.txt");
    if (file.open(QIODevice::WriteOnly))
    {
        file.write(ui->prog->toPlainText().toLatin1());
        file.close();
    }
}
//function to load text from input.txt file
void MainWindow::on_actionLoad_triggered()
{
    QFile file("txt/input.txt");
    if (file.open(QIODevice::ReadOnly))
    {
        ui->prog->setText(file.readAll());
        file.close();
    }
}

/*
 *
 * Functions to load example programms
 *
 */

void MainWindow::on_actionbeer_bf_triggered()
{
    QFile file("txt/examples/beer.bf");
    if (file.open(QIODevice::ReadOnly))
    {
        ui->prog->setText(file.readAll());
        file.close();
    }
}

void MainWindow::on_actioncellsize_bf_triggered()
{
    QFile file("txt/examples/cellsize.bf");
    if (file.open(QIODevice::ReadOnly))
    {
        ui->prog->setText(file.readAll());
        file.close();
    }
}

void MainWindow::on_actionhello_bf_triggered()
{
    QFile file("txt/examples/hello.bf");
    if (file.open(QIODevice::ReadOnly))
    {
        ui->prog->setText(file.readAll());
        file.close();
    }
}

void MainWindow::on_actionmandelbrot_tiny_bf_triggered()
{
    QFile file("txt/examples/mandelbrot-tiny.bf");
    if (file.open(QIODevice::ReadOnly))
    {
        ui->prog->setText(file.readAll());
        file.close();
    }
}

void MainWindow::on_actionmandelbrot_bf_triggered()
{
    QFile file("txt/examples/mandelbrot.bf");
    if (file.open(QIODevice::ReadOnly))
    {
        ui->prog->setText(file.readAll());
        file.close();
    }
}

void MainWindow::on_actionpidigits_bf_triggered()
{
    //create QFile
    QFile file("txt/examples/pidigits.bf");
    if (file.open(QIODevice::ReadOnly))
    {
        ui->prog->setText(file.readAll());
        file.close();
    }
}

void MainWindow::on_actionDark_triggered()
{
    ui->actionLight->setChecked(0);
    ui->centralwidget->setStyleSheet("color: white; background-color: rgb(46, 52, 54)");
    ui->menubar->setStyleSheet("color: white; background-color: rgb(46, 52, 54)");
    ui->statusbar->setStyleSheet("color: white; background-color: rgb(46, 52, 54)");
    ui->toolBar->setStyleSheet("color: white; background-color: rgb(46, 52, 54)");
}

void MainWindow::on_actionLight_triggered()
{
    ui->actionDark->setChecked(0);
    ui->centralwidget->setStyleSheet("color: black; background-color: AliceBlue");
    ui->menubar->setStyleSheet("color: black; background-color: AliceBlue");
    ui->statusbar->setStyleSheet("color: black; background-color: AliceBlue");
    ui->toolBar->setStyleSheet("color: black; background-color: AliceBlue");
}

void MainWindow::on_action8_byte_triggered()
{
    ui->action16_byte->setChecked(0);
    ui->action32_byte->setChecked(0);
    worker->setMaxValue(255);
}

void MainWindow::on_action16_byte_triggered()
{
    ui->action8_byte->setChecked(0);
    ui->action32_byte->setChecked(0);
    worker->setMaxValue(65535);
}

void MainWindow::on_action32_byte_triggered()
{
    ui->action16_byte->setChecked(0);
    ui->action8_byte->setChecked(0);
    worker->setMaxValue(4294967295);
}

void MainWindow::on_actionView_memory_triggered()
{
    textWindow = new TextWindow(this);
    textWindow->show();

    QString list;
    for(int i = 0; i < (int)(worker->getLine()).size(); i++)
    {
        list += "#" + QString::number(i) + " " + QString::number((long int)(worker->getLine())[i]) + " " + (char)((worker->getLine())[i]) + "\n";
    }
    textWindow->drawText(list);
}

void MainWindow::on_actionCheck_Errors_triggered()
{
    //show loading//
    ui->statusbar->showMessage("loading");
    ui->label_loadimg->setMovie(&dots_loading);
    dots_loading.start();
    repaint();
    //load code text to worker
    worker->setCode(ui->prog->toPlainText());
    //run code
    worker->setOutput("");
    emit startErrorsChecking();
}

void MainWindow::on_actionOutput_triggered()
{
    bool ok;
    QFont font = QFontDialog::getFont(&ok, QFont(), this);
    if(ok)
    {
        ui->output->setFont(font);
    }
}

void MainWindow::on_actionInput_triggered()
{
    bool ok;
    QFont font = QFontDialog::getFont(&ok, QFont(), this);
    if(ok)
    {
        ui->input->setFont(font);
    }
}


void MainWindow::on_actionCode_buffer_triggered()
{
    bool ok;
    QFont font = QFontDialog::getFont(&ok, QFont(), this);
    if(ok)
    {
        ui->prog->setFont(font);
    }
}

void MainWindow::on_actionSystem_triggered()
{
    bool ok;
    QFont font = QFontDialog::getFont(&ok, QFont(), this);
    if(ok)
    {
        ui->label_input->setFont(font);
        ui->label_output->setFont(font);
        ui->label_edit_code->setFont(font);
        ui->menubar->setFont(font);
        ui->statusbar->setFont(font);
    }
}

void MainWindow::on_actionSave_to_file_triggered()
{
    QString filename = QFileDialog::getOpenFileName(this, tr("Open File"), tr("Text files (*.txt *.b *.bf)"));
    QFile file(filename);
    if (file.open(QIODevice::WriteOnly))
    {
        file.write(ui->prog->toPlainText().toLatin1());
        file.close();
    }
}

void MainWindow::on_actionLoad_from_file_triggered()
{
    QString filename = QFileDialog::getOpenFileName(this, tr("Open File"), tr("Text files (*.txt *.b *.bf)"));
    QFile file(filename);
    if (file.open(QIODevice::ReadOnly))
    {
        ui->prog->setText(file.readAll());
        file.close();
    }
}

void MainWindow::on_actionto_C_triggered()
{
    worker->setCode(ui->prog->toPlainText());
    emit startConvertToC();
}

void MainWindow::end_code_converting()
{
    textWindow = new TextWindow(this);
    textWindow->show();
    textWindow->drawText(worker->getConvertedCCode());
}
