#ifndef EXPRESSIONEVALUATION_H
#define EXPRESSIONEVALUATION_H

#include "includes.h"

unsigned int evaluateExpression(map<string, double> variables, std::string expr)
{
    std::string parsedExpr = parseExpression(expr);
    cout << "parsed expr: " << parsedExpr << endl;
    double value = Lepton::Parser::parse(parsedExpr).evaluate(variables);
    cout << "value: " << value << endl;
//    double value = 1.0;
    if (value >= 1.0)
        return 1;
    return 0;
}

#endif // EXPRESSIONEVALUATION_H
