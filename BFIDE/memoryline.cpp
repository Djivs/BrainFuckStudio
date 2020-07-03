#include "memoryline.h"
#include "ui_memoryline.h"

MemoryLine::MemoryLine(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MemoryLine)
{
    ui->setupUi(this);
}

MemoryLine::~MemoryLine()
{
    delete ui;
}
void MemoryLine::drawText(QString output)
{
    ui->memoryOutput->setText(output);
}
