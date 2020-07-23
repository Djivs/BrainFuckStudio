#ifndef CODEEXECUTER_H
#define CODEEXECUTER_H

#include <QString>
#include <QObject>
#include <vector>
#include <stdlib.h>
#include <QProgressDialog>


class CodeExecuter : public QObject
{
    Q_OBJECT
public:
    //constructor
    explicit CodeExecuter(QObject *parent = 0);

    //destructor
    ~CodeExecuter() {};

    //setters
    void setEndCode(bool t){endCode = t;};
    void setCode(QString newCode) {code = newCode;};
    void setMaxValue(unsigned int newMaxValue) {maxValue = newMaxValue;};
    void setInput(QString newInput){input = newInput;};
    void setOutput(QString newOutput) {output = newOutput;};

    //getters
    QString getOutput() const {return output;};
    bool getEndCode() const {return endCode;};
    QString getConvertedCCode() const {return convertedCCode;};
    int getCmdAmount() const {return cmdAmount;};
    int getIndex() const {return index;};

private slots:
    void convertToC();
    void runCode();
    void checkErrors();
signals:
    void codeConverted();
    void codeExecuted();
    void errorsChecked();
private:
    //QStrings for converted code
    QString convertedCCode;

    void parseCode();

    //var for code ending
    volatile bool endCode = 1;

    //array for GOTO command
    int openPos[1000000];

    //enum for commands
    enum CMD {NOT, ADD, MOV, GET, PUT, GOTO, ZERO};

    //main BF line
    long int line[30000];

    //cammands array
    CMD commands[1000000];

    //args for commands array
    int args[1000000];

    //maxValue for cell size changing
    long int maxValue = 255;

    //commands amount for qprogress dialog
    int cmdAmount = 0;

    //current index
    int index = 0;

    //code, input and output strings
    QString code;
    QString output;
    QString input;
};


#endif // CODEEXECUTER_H
