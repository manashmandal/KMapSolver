#ifndef GRAYCODEHANDLER_H
#define GRAYCODEHANDLER_H

#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::cout;
using std::endl;

typedef unsigned int _ui;

vector<string> generateGrayCodeSequence(int n, bool debug=false)
{
    // 'arr' will store all generated codes
    vector<string> arr;

    // base case
    if (n <= 0)
        return arr;

    // start with one-bit pattern
    arr.push_back("0");
    arr.push_back("1");

    // Every iteration of this loop generates 2*i codes from previously
    // generated i codes.
    int i, j;
    for (i = 2; i < (1<<n); i = i<<1)
    {
        // Enter the prviously generated codes again in arr[] in reverse
        // order. Nor arr[] has double number of codes.
        for (j = i-1 ; j >= 0 ; j--)
            arr.push_back(arr[j]);

        // append 0 to the first half
        for (j = 0 ; j < i ; j++)
            arr[j] = "0" + arr[j];

        // append 1 to the second half
        for (j = i ; j < 2*i ; j++)
            arr[j] = "1" + arr[j];
    }

    // print contents of arr[]
    if (debug)
        for (i = 0 ; i < arr.size() ; i++ )
            cout << arr[i] << endl;

    return arr;
}

vector <_ui> getDecimalGrayCodeSequence(int n)
{
    vector <string> seq = generateGrayCodeSequence(n);
    vector <_ui> decimalSeq;
    char *end;

    for (string s : seq){
        decimalSeq.push_back(strtoull(s.c_str(), &end, 2));
    }

    return decimalSeq;
}

_ui strBinaryToDecimal(string s)
{
    char *end;
    return strtoull(s.c_str(), &end, 2);
}

#endif // GRAYCODEHANDLER_H
