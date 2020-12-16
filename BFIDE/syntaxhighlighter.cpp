#include "syntaxhighlighter.h"

SyntaxHighlighter::SyntaxHighlighter(QTextDocument *parent) :
    QSyntaxHighlighter(parent)
{
    // TODO: export into config
    levelColor.push_back(QTextCharFormat());
    levelColor.push_back(QTextCharFormat());
    levelColor.push_back(QTextCharFormat());
    levelColor.push_back(QTextCharFormat());
    levelColor.push_back(QTextCharFormat());
    levelColor.push_back(QTextCharFormat());
    levelColor[0].setForeground(Qt::darkCyan);
    levelColor[1].setForeground(Qt::darkGreen);
    levelColor[2].setForeground(Qt::darkRed);
    levelColor[3].setForeground(Qt::darkYellow);
    levelColor[4].setForeground(Qt::magenta);
    levelColor[5].setForeground(Qt::green);

    for (auto& tcf : levelColor) {
        tcf.setFontWeight(99);
    }
    comment.setForeground(Qt::gray);

    error.setForeground(Qt::red);
    error.setFontItalic(true);
    error.setFontWeight(99);
}


void SyntaxHighlighter::highlightBlock(const QString &text)
{
    struct FormatState {
        QTextCharFormat* currentFormat;
        int startIndex = 0;
        int length = 0;
        SyntaxHighlighter* sh;

        FormatState(SyntaxHighlighter* sh) : currentFormat{ &sh->comment }, sh{ sh } {}

        void upateFormat(int len, QTextCharFormat* format) {
            Q_UNUSED(len);

            if (format == currentFormat) {
                length++;
            }
            else {
                sh->setFormat(startIndex, length, *currentFormat);
                currentFormat = format;
                startIndex += length;
                length = 1;
            }
        }

        void finish() {
            sh->setFormat(startIndex, length, *currentFormat);
        }
    };

    const int INVALID_LEVEL = -2;
    int level = previousBlockState();

    // if uninitialized set to zero
    if (level == -1) level = 0;
    FormatState fs(this);
    for (int i = 0; i < text.length(); i++) {
        auto& c = text[i];
        if (c == '[' && level >= 0) {
            level++;
        }
        if (isBfChar(c)) {
            if (level < 0 || (level == 0 && c == ']')) {
                fs.upateFormat(1, &error);
                level = INVALID_LEVEL;
            }
            else {
                fs.upateFormat(1, &levelColor[level % levelColor.size()]);
            }
        }
        else {
            fs.upateFormat(1, &comment);
        }
        if (c == ']' && level != INVALID_LEVEL) {
            level--;
        }
    }
    fs.finish();
    setCurrentBlockState(level);
}


bool SyntaxHighlighter::isBfChar(const QChar& c)
{
    switch (c.unicode()) {
    case '+':
    case '-':
    case '<':
    case '>':
    case ',':
    case '.':
    case '[':
    case ']':
        return true;
    default:
        return false;
    }
}
