#ifndef MEMORYLINE_H
#define MEMORYLINE_H

#include <QDialog>

namespace Ui {
class MemoryLine;
}

class MemoryLine : public QDialog
{
    Q_OBJECT

public:
    explicit MemoryLine(QWidget *parent = nullptr);
    void drawText(QString output);
    ~MemoryLine();

private:
    Ui::MemoryLine *ui;
};

#endif // MEMORYLINE_H
