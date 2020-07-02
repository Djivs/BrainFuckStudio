#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <algorithm>
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->bytes8->toggle();
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::checkErrors()
{
    std::string codeCopy = code.toStdString();
    int pos = 0;
    int brackets = 0;
    for(int i = 0; i < (int)codeCopy.size(); i++)
    {
        if(codeCopy[i] == '>')
            pos++;
        else if(codeCopy[i] == '<')
            pos--;
        if(pos < 0)
        {
            output += "Invalid pointer position\n";
            return 1;
        }
        if(codeCopy[i] == '[')
        {
            codeCopy[i] = '#';
            brackets++;
            while(brackets && i < (int)codeCopy.size())
            {
                i++;
                if(codeCopy[i] == '[')
                    brackets++;
                else if(codeCopy[i] == ']')
                    brackets--;
            }

            if(brackets != 0)
            {
                output += "Cycle error\n";
                return 1;
            }
            else codeCopy[i] = '#';
        }
        if(codeCopy[i] == ']')
        {
            output += "Cycle error\n";
            return 1;
        }
    }


    return 0;
}

void MainWindow::executeCode()
{
    if(checkErrors())
    {
        line.clear();
        return;
    }
    line.resize(code.size(), 0);
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
            pos++;
        else if(code[i] == '<')
            pos--;
        else if(code[i] == '.')
            output+=char(line[pos]);
        else if(code[i] == ',')
        {
            line[pos] = input[inputPos].toLatin1();
            qDebug() << input[inputPos];
            inputPos+=2;
        }
        else if(code[i] == '[')
        {
            if(line[pos] == 0)
            {
                brackets++;
                while(brackets)
                {
                    i++;
                    if(code[i] == '[')
                        brackets++;
                    else if(code[i] == ']')
                        brackets--;
                }
            }
        }
        else if(code[i] == ']')
        {
            if(line[pos] != 0)
            {
                brackets++;
                while(brackets)
                {
                    i--;
                    if(code[i] == '[')
                        brackets--;
                    else if(code[i] == ']')
                        brackets++;
                }
                i--;
            }
        }
        if(line[pos] > maxValue)
        {
            line[pos] = 0;
        }
    }
    line.clear();
}

void MainWindow::on_run_clicked()
{
    code = ui->prog->toPlainText();
    input = ui->input->toPlainText();
    executeCode();
    ui->output->setText(output);
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
