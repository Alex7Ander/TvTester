//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "NewFreqTableUnit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TNewFreqTableForm *NewFreqTableForm;
//---------------------------------------------------------------------------
__fastcall TNewFreqTableForm::TNewFreqTableForm(TComponent* Owner)
        : TForm(Owner)
{
  FreqTableStringGrid->ColWidths[0] = 50;
  FreqTableStringGrid->ColWidths[1] = 120;
  FreqTableStringGrid->Cells[0][0] = "№";
  FreqTableStringGrid->Cells[1][0] = "Частота, МГц";
  for (int i=0; i<FreqTableStringGrid->RowCount; i++) this->FreqTableStringGrid->Cells[0][i+1] = IntToStr(i+1);
}
//---------------------------------------------------------------------------
void __fastcall TNewFreqTableForm::FreqCountEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
  if (Key==VK_RETURN){
    try{
       int cFreq = StrToInt(this->FreqCountEdit->Text);
       this->FreqTableStringGrid->RowCount = cFreq+1;
       for (int i=0; i<cFreq; i++) this->FreqTableStringGrid->Cells[0][i+1] = IntToStr(i+1);
    }
    catch(...){
       MessageBox(NULL, LPCTSTR("Введенное Вами значение не является действительным числом"), LPCTSTR("Ошибка!"), MB_OK | MB_ICONERROR);
    }
  }
}
//---------------------------------------------------------------------------
void __fastcall TNewFreqTableForm::SaveButtonClick(TObject *Sender)
{
  int cFreq = this->FreqTableStringGrid->RowCount-1;
  double *Values = new double[cFreq];
  try{
    for (int i=0; i<cFreq; i++){
      Values[i]= StrToFloat(this->FreqTableStringGrid->Cells[1][i+1]);
    }
    String Name = this->NameEdit->Text;
    freqTable *newFreqTable = new freqTable(Name.c_str(), cFreq, Values);
    newFreqTable->sort();
    String MainFileName = GetCurrentDir()+"\\freqFiles\\"+Name+".dat";
    if(newFreqTable->save(MainFileName.c_str())==0){
       MessageBox(NULL, LPCTSTR("Успешное сохранение"), LPCTSTR("Успешно!"), MB_OK | MB_ICONASTERISK);
       this->Close();
    }
    else{
      MessageBox(NULL, LPCTSTR("Возникла ошибка при сохранении"), LPCTSTR("Ошибка!"), MB_OK | MB_ICONERROR);
    }
  }
  catch(...) {
     MessageBox(NULL, LPCTSTR("Вы ввели некорректное значение или не полностью заполнили таблицу"), LPCTSTR("Ошибка!"), MB_OK | MB_ICONERROR);
  }
  delete[] Values;
}
//---------------------------------------------------------------------------
void __fastcall TNewFreqTableForm::CancelButtonClick(TObject *Sender)
{
  this->Close();
}
//---------------------------------------------------------------------------
void __fastcall TNewFreqTableForm::FormClose(TObject *Sender,
      TCloseAction &Action)
{
  Action = caFree;        
}
//---------------------------------------------------------------------------
