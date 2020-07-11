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
    ui->setupUi(this);
    ui->bytes8->toggle();
    ui->sep_space->toggle();

    thread = new QThread(this);
    connect(this, SIGNAL(destroyed()), thread, SLOT(quit()));

    qRegisterMetaType<std::vector<long long int>>("std::vector<long long int>");

    worker = new CodeExecuter();
    connect(worker, SIGNAL(codeExecuted()), this, SLOT(end_code_execution()));
    connect(this, SIGNAL(startOperation()), worker, SLOT(runCode()));
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
    line.resize(1, 0);
    int pos = 0;
    int inputPos = 0;
    for(int i = 0; i < code.size(); i++)
    {
        if(code[i] == '+')
        {
            line[pos]++;
        }
        else if(code[i] == '-')
        {
            line[pos]--;
        }
        else if(code[i] == '<')
        {
            pos--;
        }
        else if(code[i] == '>')
        {
            pos++;
            if(pos == static_cast<int>(line.size()))
            {
                line.push_back(0);
            }
        }
        else if(code[i] == '.')
        {
            output += char(line[pos]);
        }
        else if(code[i] == ',')
        {
            while(input[inputPos] == separator && inputPos < input.size())
            {
                inputPos++;
            }
            if(inputPos < input.size())
                line[pos] = (int)input[inputPos].toLatin1();
        }





        if(code[i] == '[')
        {
            int brackets = 1;


        }
    }
    emit codeExecuted();
}


void MainWindow::end_code_execution()
{
    //stop loading gif
    dots_loading.stop();
    //delete loading gif from the screen
    ui->label_loadimg->clear();
    //change status
    ui->label_loading->setText("executed");
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
}



void MainWindow::on_run_clicked()
{
    //show loading//
    ui->label_loading->setText("loading");
    ui->label_loadimg->setMovie(&dots_loading);
    dots_loading.start();
    repaint();
    //load code text to worker
    worker->setCode(ui->prog->toPlainText());
    //load input to worker
    worker->setInput(ui->input->toPlainText());
    //refresh output
    worker->setOutput(" ");
    //disable buttons
    ui->sep_space->setEnabled(0);
    ui->sep_nl->setEnabled(0);
    ui->bytes8->setEnabled(0);
    ui->bytes16->setEnabled(0);
    ui->bytes32->setEnabled(0);
    //run code
    emit startOperation();
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

void MainWindow::on_clear_clicked()
{
     ui->prog->setText("");
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
