#ifndef EXPRESSIONHANDLER_H
#define EXPRESSIONHANDLER_H

#include "include/Lepton.h"
#include <QString>
#include <string>

using std::string;
using std::vector;

using std::cout;
using std::endl;


string getInvertedExpression(char variable)
{
    string var(1, variable);
    return "(1-" + var + ")";
}

std::string parseExpression(std::string expr)
{
    std::string::iterator it = expr.begin();

    //Deals with the inverted part
    while (it != expr.end())
    {
        if ((*it) == '\''){
            (*it) = '\0';
            it--;
            string inv_expr = getInvertedExpression((*it));
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
            (*it) = '\0';
            it--;
            string inv_expr = getInvertedExpression((*it));
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

#endif // EXPRESSIONHANDLER_H
