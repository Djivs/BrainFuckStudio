/*
 * Written by Djivs, 2020
 * https://github.com/Djivs
 */
#include "textwindow.h"
#include "ui_textwindow.h"

//constructor
TextWindow::TextWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TextWindow)
{
    ui->setupUi(this);
}

//func to set text from aother class
void TextWindow::drawText(QString text)
{
    ui->textBrowser->setText(text);
}

//destructor
TextWindow::~TextWindow()
{
    delete ui;
}

//load text to file
//trivial
void TextWindow::on_load_file_button_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this, tr("Open File"), tr("Text files (*.txt *.b *.bf)"));
    QFile file(filename);
    if (file.open(QIODevice::WriteOnly))
    {
        file.write(ui->textBrowser->toPlainText().toLatin1());
        file.close();
    }
}
