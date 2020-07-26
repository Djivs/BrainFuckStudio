#include "texttobf.h"
#include "ui_texttobf.h"

TextToBF::TextToBF(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TextToBF)
{
    ui->setupUi(this);
}

TextToBF::~TextToBF()
{
    delete ui;
}

//function to convert text to bf code
/*
 * we have only one cell. for each letter in user typed text, we increase/decrease cell value
 * depending on current letter ascii code
 * then, we print current cell value
*/
void TextToBF::on_convert_button_clicked()
{
    //get user typed text
    QString in = ui->textEdit->toPlainText();
    QString out = "";

    //cellValue at first is 0
    int cellValue = 0;

    //check all typed letters
    for(int i = 0; i < in.size(); i++)
    {
        //make current cell value equal to current letter ascii code
        if(cellValue < in[i].toLatin1())
        {
            for(int j = cellValue; j < in[i].toLatin1(); j++)
                out += '+';
        }
        else if(cellValue != in[i].toLatin1())
        {
            for(int j = in[i].toLatin1(); j < cellValue; j++)
                out += '-';
        }
        cellValue = in[i].toLatin1();

        //print cell value
        out += '.';

    }

    //make output code looks like square
    for(int i = 59; i < out.size(); i+=60)
        out.insert(i, '\n');

    //print out
    ui->textBrowser->setText(out);
}

//function to load converted code to file
void TextToBF::on_load_file_button_clicked()
{
    //choose file using qfiledialog
        QString filename = QFileDialog::getOpenFileName(this, tr("Open File"), tr("Text files (*.txt *.b *.bf)"));

        //open choosen file and write here
        QFile file(filename);
        if (file.open(QIODevice::WriteOnly))
        {
            file.write(ui->textBrowser->toPlainText().toLatin1());
            file.close();
        }
}
