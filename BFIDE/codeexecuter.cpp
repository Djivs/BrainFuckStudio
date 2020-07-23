#include "codeexecuter.h"

//code executer constructor
CodeExecuter::CodeExecuter(QObject *parent): QObject(parent)
{

}

//function to check errors in code
void CodeExecuter::checkErrors()
{
    int brackets = 0;
    for(int i = 0; i < code.size(); i++)
    {
        switch(code[i].toLatin1())
        {
            case '[':
                ++brackets;
            break;
            case ']':
                --brackets;
            break;
        }
    }
    if(brackets)
    {
        output = "Wrong brackets sequence";
    }
    else
    {
        output = "No errors detected";
    }
    emit errorsChecked();
}

//function to parse code
void CodeExecuter::parseCode()
{
    cmdAmount = 0;
    memset(commands, 0, sizeof(CMD)*1000000);
    memset(args, 0, sizeof(int)*1000000);
    memset(openPos, 0, sizeof(int)*1000000);
    int posJ = 0;
    int j = 0;
    for(int i = 0; i < code.size(); i++)
    {
        ++cmdAmount;
        switch(code[i].toLatin1())
        {
            case '+':
                switch(commands[j])
                {
                    case ADD:
                        args[j]++;
                    break;
                    default:
                        j++;
                        commands[j] = ADD;
                        args[j] = 1;
                    break;
                }
            break;
            case '-':
                switch(commands[j])
                {
                    case ADD:
                        args[j]--;
                    break;
                    default:
                        j++;
                        commands[j] = ADD;
                        args[j] = -1;
                    break;
                }
            break;
            case '.':
                switch(commands[j])
                {
                    case PUT:
                        args[j]++;
                    break;
                    default:
                        j++;
                        commands[j] = PUT;
                        args[j] = 1;
                    break;
                }
            break;
            case ',':
                switch(commands[j])
                {
                    case GET:
                        args[j]++;
                    break;
                    default:
                        j++;
                        commands[j] = GET;
                        args[j] = 1;
                    break;
                }
            break;
            case '>':
                switch(commands[j])
                {
                    case MOV:
                        args[j]++;
                    break;
                    default:
                        j++;
                        commands[j] = MOV;
                        args[j] = 1;
                    break;
                }
            break;
            case '<':
                switch(commands[j])
                {
                    case MOV:
                        args[j]--;
                    break;
                    default:
                        j++;
                        commands[j] = MOV;
                        args[j] = -1;
                    break;
                }

            break;
            case '[':
                if((code[i+1] == '-' || code[i+1] == '+') && code[i+2] == ']')
                {
                    j++;
                    commands[j] = ZERO;
                    args[j] = 1;
                    i+=2;
                }
                else
                {
                    j++;
                    commands[j] = GOTO;
                    args[j] = 0;
                    openPos[posJ] = j;
                    posJ++;
                }
            break;
            case ']':
                j++;
                args[openPos[posJ-1]] = j - openPos[posJ-1];
                commands[j] = GOTO;
                args[j] = openPos[posJ-1] - j;
                posJ--;
            break;
        }
    }
}

//function to run code
void CodeExecuter::runCode()
{
    index = 0;
    parseCode();
    memset(line, 0, sizeof(long int)*30000);
    int pos = 0;
    int inputPos = 0;
    for(int i =  1; !endCode; i++)
    {
        index = i;
        switch(commands[i])
        {
            case ADD:
                line[pos] += args[i];
                if(line[pos] < 0)
                    line[pos] += maxValue+1;
                else if(line[pos] > maxValue)
                    line[pos] -= maxValue+1;
            break;
            case MOV:
                pos += args[i];
                if(pos < 0)
                {
                    output += "\nRuntime error: negative pointer position\n";
                     emit codeExecuted();
                    return;
                }
            break;
            case GET:
                if(inputPos < input.size())
                    line[pos] = input[inputPos].toLatin1();
                inputPos++;
            break;
            case PUT:
                for(int j = 0; j < args[i]; j++)
                    output += line[pos];
            break;
            case GOTO:
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
    convertedCCode = "#include <stdio.h>\n";
    convertedCCode += "int main() {\n";
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
    parseCode();
    for(int i = 1; commands[i] != NOT; i++)
    {
        for(int i = 0; i < tabs; i++)
            convertedCCode += "    ";
        switch(commands[i])
        {
            case ADD:
                convertedCCode += "*ptr += " + QString::number(args[i]) + ";\n";
            break;
            case MOV:
                convertedCCode += "ptr += " + QString::number(args[i]) + ";\n";
            break;
            case PUT:
                for(int j = 0; j < args[i];j++)
                {
                    if(j)
                    {
                        for(int l = 0; l < tabs; l++)
                            convertedCCode += "    ";
                    }
                    convertedCCode += "putchar(*ptr);\n";
                }
            break;
            case GET:
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
                convertedCCode += "*ptr = 0;\n";
            break;
            default:
                break;
        }
    }
    convertedCCode += "    return 0;\n";
    convertedCCode += "}";
    emit codeConverted();
}

