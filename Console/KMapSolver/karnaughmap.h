#ifndef KARNAUGHMAP_H
#define KARNAUGHMAP_H

#include "filterkmapresults.h"
#include "operation.h"

class KarnaughMap : public FilterKmapTerms, public SOPtoPOS
{
private:
    int temp;
    int temp1;
    int temp2;
    int temp3;

    char tempChar;
    vector <char> result;
    vector < vector<char> > filterResults;
    std::string res;

public:
    void clear()
    {
        tempChar = NULL;
        result.clear();
        filterResults.clear();
        ones.clear();
        dCare.clear();
    }

    // Number of variables
    void setType(int t)
    {
        type = t;
    }

    // SOP or POS [True for SOP, false for POS]
    void setResultType(bool s)
    {
        SOP = s;
    }

    // Getting position of ones
    void setOnesPosition(vector <int> onesPosition)
    {
        ones = onesPosition;
    }

    // Getting position of don't cares
    void setDontCarePosition(vector <int> dontCarePosition)
    {
        dCare = dontCarePosition;
    }

    std::string getResult(void)
    {
        result = minimize(ones, dCare); //Solving by minimizing

        if( result.size() != 1 ||   //not full or empty maps
            ( result[0] != 48 && result[0] != 49 ) )
        {
            filterResults.clear();
            filterResults =  filter(result,ones); //filter result from unessential terms

                for(int temp = 0; temp < filterResults.size(); temp++)
                {
                    if(filterResults.size() > 1){
                        res += "\n" + std::to_string(temp + 1) + " - ";
                    }

                    if(SOP == false) convSopToPos(filterResults[temp]);

                    for(int temp1 = 0; temp1 < filterResults[temp].size(); temp1++){
                        res += filterResults[temp][temp1];
                    }
                }

        }
        else{
            res += result[0] + "\n";
        }
        return res;
    }
};

#endif // KARNAUGHMAP_H
