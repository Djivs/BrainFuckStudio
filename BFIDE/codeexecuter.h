#ifndef CODEEXECUTER_H
#define CODEEXECUTER_H

#include <QString>
#include <QObject>
#include <vector>


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
    void setLine(std::vector<long int> newLine) {line = newLine;};
    void setCode(QString newCode) {code = newCode;};
    void setMaxValue(unsigned int newMaxValue) {maxValue = newMaxValue;};
    void setInput(QString newInput){input = newInput;};
    void setOutput(QString newOutput) {output = newOutput;};
    //getters
    QString getOutput() const {return output;};
    bool getEndCode() const {return endCode;};
    std::vector <long int> getLine() const {return line;};
    QString getConvertedCCode() const {return convertedCCode;};
private slots:
    void convertToC();
    void runCode();
    void checkErrors();
signals:
    void codeConverted();
    void codeExecuted();
    void errorsChecked();
private:
    QString convertedCCode;
    void parseCode();
    volatile bool endCode = 1;
    std::vector <long int> line;
    std::vector <int> openPos;
    enum CMD {NOT, ADD, MOV, GET, PUT, GOTO, ZERO};
    std::vector <CMD> commands;
    std::vector <int> args;
    long int maxValue = 255;
    QString code;
    QString output;
    QString input;
};


#endif // CODEEXECUTER_H
