//---------------------------------------------------------------------------
#ifndef FreqTableClassH
#define FreqTableClassH
//---------------------------------------------------------------------------
#endif
#include <fstream.h>
class freqTable
{
private:
        int countOfValues;
        double *freqValue;
        string name;

public:
        freqTable(string Name, int CountOfValues, double *values);
        ~freqTable();
        void sort();
        int save(string mainFileName);
};