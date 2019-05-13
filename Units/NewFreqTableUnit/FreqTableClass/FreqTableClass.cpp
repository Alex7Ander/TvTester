//---------------------------------------------------------------------------
#pragma hdrstop
#include "FreqTableClass.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
freqTable::freqTable(string Name, int CountOfValues, double *values)
{
  this->name = Name;
  this->countOfValues = CountOfValues;
  this->freqValue = new double[CountOfValues];
  for (int i=0; i<CountOfValues; i++){
    this->freqValue[i] = values[i];
  }
}
//---------------------------------------------------------------------------
freqTable::~freqTable()
{
  delete[] this->freqValue;
}
//---------------------------------------------------------------------------
void freqTable::sort()
{
  //
}
//---------------------------------------------------------------------------
int freqTable::save(string mainFileName)
{
  try{
    ofstream mainFile;
    mainFile.open(mainFileName.c_str());
    for (int i=0; i<this->countOfValues; i++){
       mainFile << this->freqValue[i];
       if (i<this->countOfValues-1) mainFile << std::endl;
    }
    mainFile.close();
    ofstream listFile;
    listFile.open("list.dat",std::ios_base::app);
    listFile<< std::endl;
    listFile << this->name.c_str();
    listFile.close();
    return 0;
  }catch(...){return 1;}
}
//---------------------------------------------------------------------------
