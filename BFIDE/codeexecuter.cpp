/*
 * Written by Djivs, 2020
 * https://github.com/Djivs
 */
#include "codeexecuter.h"

//code executer constructor
CodeExecuter::CodeExecuter(QObject *parent): QObject(parent)
{
    //empty constructor...
}

//function to check errors in code
void CodeExecuter::checkErrors()
{
    //you can't initialize vars with same name
    //in switch statement, so i moved declaration here

    int brackets;
    //check every code symbol

    for(int i = 0; i < code.size(); i++)
    {
        //check if code[i] is bracket
        //.toLatin1() used for switch statement

        switch(code[i].toLatin1())
        {
            case '[':
                //stres current bracckets amount

                brackets = 1;
                //search for closing brackets for found bracket
                //until we didn't go out of code string range

                while(brackets && i < code.size())
                {
                    //look for next symbol

                    i++;
                    //switch if it is brackets

                    switch (code[i].toLatin1())
                    {
                        case '[':
                            brackets++;
                        break;
                        case ']':
                            brackets--;
                        break;
                    }
                }
                //if i == code.size(), then brackets are not 0,
                //then there is no closing bracket for current bracket

                if(i == code.size())
                {
                    //make error

                    output = "wrong brackets";
                    emit errorsChecked();
                    return;
                }
            break;
            case ']':
            //same as case '[', just going from right to left

            brackets = 1;
                while(brackets && i > 0)
                {
                    i--;
                    switch (code[i].toLatin1())
                    {
                        case '[':
                            brackets--;
                        break;
                        case ']':
                            brackets++;
                        break;
                    }
                }
                if(i == -1)
                {
                    output = "wrong brackets";
                    emit errorsChecked();
                    return;
                }
                --brackets;
            break;
        }
    }
    //if we are here, errors was not detected
    //(after error detecting function ends)

    output = "No errors detected";
    emit errorsChecked();
}

//function to parse code
//See algorithm in ALGS.md
void CodeExecuter::parseCode()
{
    //clear arrays for commands, args and GOTO search
    memset(commands, 0, sizeof(CMD)*1000000);
    memset(args, 0, sizeof(int)*1000000);
    memset(openPos, 0, sizeof(int)*1000000);
    //var for searching GOTO
    int posJ = 0;
    //commands iterator
    int j = 0;

    //check every code symbol
    for(int i = 0; i < code.size(); i++)
    {
        switch(code[i].toLatin1())
        {
            case '+':
                switch(commands[j])
                {
                    //if current command is ADD, just increase argument
                    //for current commands
                    case ADD:
                        ++args[j];
                    break;
                    //else, make new command ADD
                    default:
                        ++j;
                        commands[j] = ADD;
                        args[j] = 1;
                    break;
                }
            break;
            case '-':
                //same as case '+', but with -
                switch(commands[j])
                {
                    case ADD:
                        --args[j];
                    break;
                    default:
                        ++j;
                        commands[j] = ADD;
                        args[j] = -1;
                    break;
                }
            break;
            case '.':
                //same as case '+', but command is PUT
                switch(commands[j])
                {
                    case PUT:
                        ++args[j];
                    break;
                    default:
                        ++j;
                        commands[j] = PUT;
                        args[j] = 1;
                    break;
                }
            break;
            case ',':
                //same as case '+', but command is GET
                switch(commands[j])
                {
                    case GET:
                        ++args[j];
                    break;
                    default:
                        ++j;
                        commands[j] = GET;
                        args[j] = 1;
                    break;
                }
            break;
            case '>':
                //same as case '+', but command is MOV
                switch(commands[j])
                {
                    case MOV:
                        ++args[j];
                    break;
                    default:
                        ++j;
                        commands[j] = MOV;
                        args[j] = 1;
                    break;
                }
            break;
            case '<':
                //same as case '+',but with -, and command is MOV
                switch(commands[j])
                {
                    case MOV:
                        --args[j];
                    break;
                    default:
                        ++j;
                        commands[j] = MOV;
                        args[j] = -1;
                    break;
                }

            break;
            case '[':
                //if it is just zeroing current slot, mark that and go next
                if((code[i+1] == '-' || code[i+1] == '+') && code[i+2] == ']')
                {
                    ++j;
                    commands[j] = ZERO;
                    args[j] = 1;
                    i+=2;
                }
                //else, save index of that command in special array(and move posJ)
                //and add new GOTO command
                else
                {
                    ++j;
                    commands[j] = GOTO;
                    args[j] = 0;
                    openPos[posJ] = j;
                    ++posJ;
                }
            break;
            case ']':
                //go to special array, find last value(last value == last [)
                //and changs aruments of GOTO commands to
                //amount of commands between them
                //+ move posJ--, because we found 1 opening bracket
                ++j;
                args[openPos[posJ-1]] = j - openPos[posJ-1];
                commands[j] = GOTO;
                args[j] = openPos[posJ-1] - j;
                --posJ;
            break;
        }
    }
}

//function to run code
void CodeExecuter::runCode()
{
    parseCode();
    //clear line
    memset(line, 0, sizeof(long int)*30000);
    //pointer position
    int pos = 0;
    //position in input string
    //to control wich symbol from input string
    //we need to use
    int inputPos = 0;
    //while code exec is not ending, do cycle
    //cycle ends when current command becomes NOT(0),
    //because default case works
    for(int i =  1; !endCode; i++)
    {
        switch(commands[i])
        {
            case ADD:
                line[pos] += args[i];
                //because user can choose cell size
                //and cells are unsigned:
                if(line[pos] < 0)
                    line[pos] += maxValue+1;
                else if(line[pos] > maxValue)
                    line[pos] -= maxValue+1;
            break;
            case MOV:
                pos += args[i];
                //if pos<0, end(negative array element)
                if(pos < 0)
                {
                    output = "negative pointer pos";
                    emit codeExecuted();
                    return;
                }
            break;
            case GET:
                //allows dynamic input
                if(inputPos < input.size())
                {
                    line[pos] = input[inputPos].toLatin1();
                    ++inputPos;
                }
                else
                    --i;
            break;
            case PUT:
                //obviously
                for(int j = 0; j < args[i]; j++)
                    output += line[pos];
            break;
            case GOTO:
                //if it is opening bracket and current cell is 0
                //or if it is closing bracket and cyrrent cell is not 0
                if((line[pos] && args[i] < 0) || (!line[pos] && args[i] > 0))
                    i += args[i];
            break;
            case ZERO:
                line[pos] = 0;
            break;
            default:
                emit codeExecuted();
                return;
            break;

        }
    }
    emit codeExecuted();
}
//function to convert BF code to C code
void CodeExecuter::convertToC()
{
    //beginning is simple. just add header file,strt main func and etc
    convertedCCode = "#include <stdio.h>\n";
    convertedCCode += "int main() {\n";
    //controls tabs amount
    //for code formatting
    int tabs = 1;
    switch(maxValue)
    {
        case 255:
            convertedCCode += "    unsigned char arr[30000] = {0};\n    unsigned char *ptr = arr;\n";
        break;
        case 65535:
            convertedCCode += "    unsigned short int arr[30000] = {0};\n    unsigned short int *ptr = arr;\n";
        break;
        default:
            convertedCCode += "    unsigned int arr[30000] = {0};\n    unsigned int *ptr = arr;\n";
        break;
    }
    //to reduce code amount
    parseCode();
    //go through all commands
    for(int i = 1; commands[i] != NOT; i++)
    {
        //add tabs
        for(int i = 0; i < tabs; i++)
            convertedCCode += "    ";
        switch(commands[i])
        {
            //obvious
            case ADD:
                convertedCCode += "*ptr += " + QString::number(args[i]) + ";\n";
            break;
            //obvious
            case MOV:
                convertedCCode += "ptr += " + QString::number(args[i]) + ";\n";
            break;
            case PUT:
                //to print symbol multiple times
                for(int j = 0; j < args[i];j++)
                {
                    //for first time, we already printed tabs
                    //so we print tabs only if j != 0
                    if(j)
                    {
                        for(int l = 0; l < tabs; l++)
                            convertedCCode += "    ";
                    }
                    convertedCCode += "putchar(*ptr);\n";
                }
            break;
            case GET:
                //same as PUT
                for(int j = 0; j < args[i]; j++)
                {
                    if(j)
                    {
                        for(int l = 0; l < tabs; l++)
                            convertedCCode += "    ";
                    }
                    convertedCCode += "*ptr=getchar();\n";
                }
            break;
            case GOTO:
                //also simle
                if(args[i] < 0)
                {
                    convertedCCode += "}\n";
                    tabs--;
                }
                else {
                    tabs++;
                    convertedCCode += "while(*ptr) {\n";
                }
            break;
            case ZERO:
                //...
                convertedCCode += "*ptr = 0;\n";
            break;
            default:
                break;
        }
    }
    //print code end
    convertedCCode += "    return 0;\n";
    convertedCCode += "}";
    //end converting
    emit codeConverted();
}

