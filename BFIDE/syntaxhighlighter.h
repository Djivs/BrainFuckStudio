#ifndef SYNTAXHIGHLIGHTER_H
#define SYNTAXHIGHLIGHTER_H

#include <QSyntaxHighlighter>

#include <vector>

class SyntaxHighlighter :
        public QSyntaxHighlighter {
    Q_OBJECT

 public:
    explicit SyntaxHighlighter(QTextDocument *parent = 0);

 protected:
    void highlightBlock(const QString &text) override;

 private:
    /*struct HighlightingRule
    {
        QRegularExpression pattern;
        QTextCharFormat format;
    };
    QVector<HighlightingRule> highlightingRules;

    QRegularExpression commentStartExpression;
    QRegularExpression commentEndExpression;*/

    /**
     * @brief color per loop level
     */
    std::vector<QTextCharFormat> levelColor;
    QTextCharFormat comment;
    QTextCharFormat error;

    bool isBfChar(const QChar& c);
};

#endif  // SYNTAXHIGHLIGHTER_H
