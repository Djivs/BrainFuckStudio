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
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::executeCode()
{
    line.resize(code.size(), 0);
    unsigned int pos = 0;
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
    }
}

void MainWindow::on_run_clicked()
{
    code = ui->prog->toPlainText();
    input = ui->input->toPlainText();
    executeCode();
    ui->output->setText(output);
    output = "";
}
