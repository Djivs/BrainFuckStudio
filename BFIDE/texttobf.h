#ifndef TEXTTOBF_H
#define TEXTTOBF_H

#include <QDialog>
#include <QFile>
#include <QFileDialog>

namespace Ui {
class TextToBF;
}

class TextToBF : public QDialog
{
    Q_OBJECT

public:
    explicit TextToBF(QWidget *parent = nullptr);
    ~TextToBF();

private slots:
    void on_convert_button_clicked();

    void on_load_file_button_clicked();

private:
    Ui::TextToBF *ui;
};

#endif // TEXTTOBF_H
