#ifndef EXPRESSIONHANDLER_H
#define EXPRESSIONHANDLER_H

#include "include/Lepton.h"
#include <QString>
#include <string>
#include <set>
#include "graycodehandler.h"

using std::string;
using std::vector;

using std::cout;
using std::endl;

vector <string> literals{"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"};



string getInvertedExpression(char variable)
{
    string var(1, variable);
    return "(1-" + var + ")";
}

unsigned int countVariable(QString expression)
{
    set <char> charSet;
    for (char c : expression.toStdString()){
        if (!ispunct(c) && !isdigit(c))
            charSet.insert(charSet.begin(), c);
    }
    set <char>::iterator it = charSet.end();
    it--;
    return ((*it) - 'A' + 1);
}

unsigned int countVariable(std::string expression)
{
    set <char> charSet;
    for (char c : expression){
        if (!ispunct(c) && !isdigit(c))
            charSet.insert(charSet.begin(), c);
    }
    set <char>::iterator it = charSet.end();
    it--;
    return ((*it) - 'A' + 1);
}

std::string parseExpression(std::string expr)
{
    std::string::iterator it = expr.begin();

    //Deals with the inverted part
    while (it != expr.end())
    {
        if ((*it) == '\''){
            expr.erase(it);
            it--;
            string inv_expr = getInvertedExpression((*it));
            expr.erase(it);
            expr.insert(it, inv_expr.begin(), inv_expr.end());
            it = expr.begin();
        } else {
            it++;
        }
    }

    cout << expr << endl;

    it = expr.begin();
    // inserts '*' where needed
    while (it != expr.end()){
        if (isalpha(*it) || (*it) == ')'){
            it++;
            if (isalpha(*it) || (*it) == '('){
                expr.insert(it, '*');
                it = expr.begin();
                it++;
            }
        } else {
            it++;
        }
    }
    return expr;
}

void parseExpression(QString expression)
{
    std::string expr = expression.toStdString();
    std::string::iterator it = expr.begin();

    //Deals with the inverted part
    while (it != expr.end())
    {
        if ((*it) == '\''){
            expr.erase(it);
            it--;
            string inv_expr = getInvertedExpression((*it));
            expr.erase(it);
            expr.insert(it, inv_expr.begin(), inv_expr.end());
            it = expr.begin();
        } else {
            it++;
        }
    }

    cout << expr << endl;

    it = expr.begin();
    // inserts '*' where needed
    while (it != expr.end()){
        if (isalpha(*it) || (*it) == ')'){
            it++;
            if (isalpha(*it) || (*it) == '('){
                expr.insert(it, '*');
                it = expr.begin();
                it++;
            }
        } else {
            it++;
        }
    }
    cout << expr << endl;
}

unsigned int evaluateExpression(map<string, double> variables, std::string expr)
{
    std::string parsedExpr = parseExpression(expr);
    cout << "parsed expr: " << parsedExpr << endl;
    double value = Lepton::Parser::parse(parsedExpr).evaluate(variables);
    if (value >= 1.0)
        return 1;
    return 0;
}

vector <int> getOnesPosition(std::string expression){
    map <string, double> vars;
    vector <int> _ones;
    int vc = countVariable(expression);
    vector <string> grayCodes = generateGrayCodeSequence(vc);

    // 100
    for (string graycode: grayCodes){
        for (int i = 0; i < graycode.size(); i++){
            std::string value(1, graycode[i]);
            vars[literals[i]] = atoi(value.c_str());
        }

        int exprValue = evaluateExpression(vars, expression);
        if (exprValue > 0){
            _ones.push_back(strBinaryToDecimal(graycode));
        }
    }

    for (int v : _ones){
        cout << "val : " << v << endl;
    }

    return _ones;
}

#endif // EXPRESSIONHANDLER_H
