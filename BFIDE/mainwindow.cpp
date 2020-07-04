#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <algorithm>
#include <QThread>
#include <QTimer>
#include <iostream>
#include <fstream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), pixmap(":/img/sandwatch.png")
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->bytes8->toggle();
    ui->sep_no->toggle();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::executeCode()
{
    line.resize(30000, 0);
    int pos = 0;
    int inputPos = 0;
    int brackets = 0;
    for(int i = 0; i < code.size(); i++)
    {
        if(code[i] == '+')
            line[pos]++;
        else if(code[i] == '-')
            line[pos]--;
        else if(code[i] == '>')
        {
            pos++;
            if(pos >= (int)line.size())
            {
                line.push_back(0);
            }
        }
        else if(code[i] == '<')
        {
            pos--;
            if(pos < 0)
            {
                output += "Invalid pointer position\n";
                return;
            }
        }
        else if(code[i] == '.')
        {
            output+=char(line[pos]);
            ui->output->setText(output);
            repaint();
        }
        else if(code[i] == ',')
        {
            line[pos] = input[inputPos].toLatin1();
            inputPos++;
            if(input[inputPos] == *separator)
                inputPos++;

        }
        else if(code[i] == '[')
        {
            if(line[pos] == 0)
            {
                brackets++;
                while(brackets && i < (int)code.size())
                {
                    i++;
                    if(code[i] == '[')
                        brackets++;
                    else if(code[i] == ']')
                        brackets--;
                }
                if(brackets)
                {
                    output += "Invalid cycle\n";
                    return;
                }
            }
        }
        else if(code[i] == ']')
        {
            if(line[pos] != 0)
            {
                brackets++;
                while(brackets && i >= 0)
                {
                    i--;
                    if(code[i] == '[')
                        brackets--;
                    else if(code[i] == ']')
                        brackets++;
                }
                if(brackets)
                {
                    output += "Invalid cycle\n";
                    return;
                }
                i--;
            }
        }
        if(line[pos] > maxValue)
        {
            line[pos] = 0;
        }
        else if(line[pos] < (-1)*maxValue)
        {
            line[pos] = 0;
        }
    }
}

void MainWindow::on_run_clicked()
{
    //show loading//
    ui->label_loading->setText("loading");
    ui->label_loadimg->setPixmap(pixmap);
    repaint();
    //clear line for programm//
    line.clear();
    //get user code && user input//
    code = ui->prog->toPlainText();
    input = ui->input->toPlainText() + " ";
    //run BF code//
    executeCode();
    //end loading//
    ui->label_loading->setText("executed");
    ui->label_loadimg->clear();
    //clear string for output//
    output = "";
}
void MainWindow::on_bytes16_clicked()
{
    maxValue = 65535;
}
void MainWindow::on_bytes32_clicked()
{
    maxValue = 4294967295;
}

void MainWindow::on_bytes8_clicked()
{
    maxValue = 255;
}

void MainWindow::on_clear_clicked()
{
     ui->prog->setText(" ");
}

void MainWindow::on_viewMemoryLine_clicked()
{
    window = new MemoryLine(this);
    window->show();
    QString list;
    for(int i = 0; i < (int)line.size(); i++)
    {
        list.push_back("#" + QString::number(i) + " " + QString::number((long long int)line[i]) + " " + (char)(line[i]) + "\n");
    }
    window->drawText(list);
}


void MainWindow::on_prog_textChanged()
{
    ui->label_loading->setText("text editing");
    QString progText = ui->prog->toPlainText();
}

void MainWindow::on_sep_no_clicked()
{
    separator = NULL;
}

void MainWindow::on_sep_space_clicked()
{
    *separator =  ' ';
}

void MainWindow::on_sep_nl_clicked()
{
    *separator = '\n';
}
