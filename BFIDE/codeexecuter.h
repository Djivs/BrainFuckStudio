/*
 * Written by Djivs, 2020
 * https://github.com/Djivs
 */


/*
 * Class for code execution, errors detecting and code converting
 * Main functions are in private slots
 * You can see functions descriptions in .cpp file
 */

#ifndef CODEEXECUTER_H
#define CODEEXECUTER_H

#include <QString>
#include <QObject>
#include <algorithm>
class CodeExecuter : public QObject
{
    Q_OBJECT
public:
    //constructor
    explicit CodeExecuter(QObject *parent = 0);

    //destructor
    ~CodeExecuter() {};

    /*setters
     * named by variables names, so i think I don't need
     * to comment every function
     */
    void setEndCode(bool t){endCode = t;};
    void setCode(QString newCode) {code = newCode;};
    void setMaxValue(unsigned int newMaxValue) {maxValue = newMaxValue;};
    void setInput(QString newInput){input = newInput;};
    void setOutput(QString newOutput) {output = newOutput;};

    /*getters
     * named by variables names, so i think I don't need
     * to comment every function
     */
    QString getOutput() const {return output;};
    bool getEndCode() const {return endCode;};
    QString getConvertedCCode() const {return convertedCCode;};
    QString getInput() const {return input;};
    /*function to get line - array that used in BF programm
     * returns vector because it is easier
     */
    std::vector <long int> getLine() const
    {
        //initialize buffer vector
        std::vector <long int> res;
        //copy line values here
        copy(line, line+30000, inserter(res, res.begin()));
        //return that vector
        return res;
    };

private slots:
    //main codeexecuter.h functions
    void convertToC();
    void runCode();
    void checkErrors();
signals:
    //signals to end main functions
    void codeConverted();
    void codeExecuted();
    void errorsChecked();
private:
    //QStrings for converted code
    QString convertedCCode;

    //function to parse code
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

    //code, input and output strings
    QString code;
    QString output;
    QString input;
};


#endif // CODEEXECUTER_H
