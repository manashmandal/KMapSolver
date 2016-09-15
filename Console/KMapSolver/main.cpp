#include "filterkmapresults.h"
#include "operation.h"
#include "karnaughmap.h"
#include "graycodehandler.h"
#include "include/Lepton.h"
#include "expressionhandler.h"
#include <QString>

int main ()
{
    KarnaughMap k;
    vector <int> on{0, 2, 13, 9, 15, 11};
//    vector <int> dcare {6, 12, 13};
    k.setType(4);
    k.setResultType(true);
    k.setOnesPosition(on);
//    k.setDontCarePosition(dcare);

    cout << k.getResult() << endl;


////    Kmap k1;
//    KarnaughMap k;
//    vector <int> on1{0, 1, 7, 6};
////    on1.push_back(0);
////    on1.push_back(1);
////    on1.push_back(2);
//    vector <int> dc;
////    dc.push_back(3);
//    k.setType(3);
//    k.setResultType(true);
//    k.setOnesPosition(on1);
//    cout << endl;
//    cout << k.getResult() << endl;
////    vector<string> gc = generateGrayCodeSequence(3);
//    std::string expr = "AB+C'D'+EF";

//    std::map<string, double> variables;

//    variables["A"] = 1;
//    variables["B"] = 1;
//    variables["C"] = 0;
//    variables["D"] = 0;
//    variables["E"] = 1;
//    variables["F"] = 1;

//    cout << evaluateExpression(variables, expr) << endl;

//    cout << countVariable(expr) << endl;

    std::string expresso = "A'B'C+ABC'+B'C'";
    getOnesPosition(expresso);

}//end main
