#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <algorithm>
#include <QThread>
#include <QTimer>
#include <iostream>
#include <fstream>

CodeExecuter::CodeExecuter(QObject *parent): QObject(parent)
{

}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), dots_loading(":/img/loading.gif")
    , ui(new Ui::MainWindow)
{
    //main window setup
    ui->setupUi(this);
    ui->bytes8->toggle();
    ui->sep_space->toggle();
    ui->darkScheme->toggle();


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


    //move worker to created thread and start it
    worker->moveToThread(thread);
    thread->start();
}

MainWindow::~MainWindow()
{
    delete ui;
}
void CodeExecuter::runCode()
{
    line.clear();
    line.resize(30000, 0);
    int pos = 0;
    int inputPos = 0;
    for(int i = 0; i < code.size(); i++)
    {
        switch(code[i].toLatin1())
        {
            case '+':
                line[pos]++;
                if(line[pos] > maxValue)
                {
                    line[pos] = 0;
                }
            break;
            case '-':
                line[pos]--;
                if(line[pos]< 0)
                {
                    line[pos] = maxValue;
                }
            break;
            case '>':
                pos++;
            break;
            case '<':
                if(pos)
                {
                    pos--;
                }
            break;
            case '.':
                output += (char)line[pos];
            break;
            case ',':
                while(inputPos < input.size() && input[inputPos] == separator)
                {
                    inputPos++;
                }
                if(inputPos < input.size())
                    line[pos] = (int)input[inputPos].toLatin1();
                inputPos++;
            break;
            case '[':
                if(!line[pos])
                {
                    int brackets = 1;
                    while(brackets && i < code.size())
                    {
                        i++;
                        switch(code[i].toLatin1())
                        {
                            case '[':
                                brackets++;
                            break;
                            case ']':
                                brackets--;
                            break;
                        }
                    }
                }
            break;
            case ']':
                if(line[pos])
                {
                    int brackets = 1;
                    while(brackets && i >= 0)
                    {
                        i--;
                        switch(code[i].toLatin1())
                        {
                            case '[':
                                brackets--;
                            break;
                            case ']':
                                brackets++;
                            break;
                        }
                    }
                }
            break;
        }
    }
    emit codeExecuted();
}
void MainWindow::updateOut()
{
    ui->output->setText(worker->getOutput());
    ui->output->repaint();
}

void MainWindow::end_code_execution()
{
    finish =  QDateTime::currentDateTime();
    int secs = start.msecsTo(finish)/10;
    //stop loading gif
    dots_loading.stop();
    //delete loading gif from the screen
    ui->label_loadimg->clear();
    //change status
    ui->label_loading->setText("executed in\n" + QString::number((float)secs/100.0) + 's');
    //show changes
    repaint();
    //enable buttons
    ui->sep_space->setEnabled(1);
    ui->sep_nl->setEnabled(1);
    ui->bytes8->setEnabled(1);
    ui->bytes16->setEnabled(1);
    ui->bytes32->setEnabled(1);
    //set output
    ui->output->setText(worker->getOutput());
    timer->stop();
    worker->setEndCode(1);

}
void MainWindow::on_bytes16_clicked()
{
    worker->setMaxValue(65535);
}
void MainWindow::on_bytes32_clicked()
{
    worker->setMaxValue(4294967295);
}

void MainWindow::on_bytes8_clicked()
{
     worker->setMaxValue(255);
}
void MainWindow::on_viewMemoryLine_clicked()
{
    window = new MemoryLine(this);
    window->show();

    QString list;
    for(int i = 0; i < (int)(worker->getLine()).size(); i++)
    {
        list.push_back("#" + QString::number(i) + " " + QString::number((long long int)(worker->getLine())[i]) + " " + (char)((worker->getLine())[i]) + "\n");
    }
    window->drawText(list);
}


void MainWindow::on_prog_textChanged()
{
    ui->label_loading->setText("text editing");
}

void MainWindow::on_sep_space_clicked()
{
    worker->setSeparator(' ');
}

void MainWindow::on_sep_nl_clicked()
{
     worker->setSeparator('\n');
}

void MainWindow::on_darkScheme_clicked()
{
     ui->centralwidget->setStyleSheet("color: white; background-color: rgb(46, 52, 54)");
     ui->menubar->setStyleSheet("color: white; background-color: rgb(46, 52, 54)");
}

void MainWindow::on_lightScheme_clicked()
{
     ui->centralwidget->setStyleSheet("color: black; background-color: white");
       ui->menubar->setStyleSheet("color: black; background-color: white");
}

void MainWindow::on_sep_no_clicked()
{
    worker->setSeparator((char)0);
}
void MainWindow::on_actionStart_Code_triggered()
{
    if(!(worker->getEndCode()))
        return;
    //show loading//
    ui->label_loading->setText("loading");
    ui->label_loadimg->setMovie(&dots_loading);
    dots_loading.start();
    repaint();
    //load code text to worker
    worker->setCode(ui->prog->toPlainText());
    //load input to worker
    worker->setInput(ui->input->toPlainText());
    //disable buttons
    ui->sep_space->setEnabled(0);
    ui->sep_nl->setEnabled(0);
    ui->bytes8->setEnabled(0);
    ui->bytes16->setEnabled(0);
    ui->bytes32->setEnabled(0);
    //run code
    worker->setOutput("");
    start =  QDateTime::currentDateTime();
    worker->setEndCode(0);
    emit startOperation();
    timer->start(1);
}

void MainWindow::on_actionEnd_Code_triggered()
{
     worker->setEndCode(1);
}

void MainWindow::on_actionClear_triggered()
{
    ui->prog->setText("");
}
