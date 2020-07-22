#include "textwindow.h"
#include "ui_textwindow.h"

TextWindow::TextWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TextWindow)
{
    ui->setupUi(this);
}

void TextWindow::drawText(QString text)
{
    ui->textBrowser->setText(text);
}
TextWindow::~TextWindow()
{
    delete ui;
}

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
