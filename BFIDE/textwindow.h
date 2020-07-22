#ifndef TEXTWINDOW_H
#define TEXTWINDOW_H

#include <QDialog>
#include <QFile>
#include <QFileDialog>

namespace Ui {
class TextWindow;
}

class TextWindow : public QDialog
{
    Q_OBJECT

public:
    void drawText(QString text);
    explicit TextWindow(QWidget *parent = nullptr);
    ~TextWindow();

private slots:
    void on_load_file_button_clicked();

private:
    Ui::TextWindow *ui;
};

#endif // TEXTWINDOW_H
