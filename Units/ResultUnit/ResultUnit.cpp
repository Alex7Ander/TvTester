//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "ResultUnit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TResultForm *ResultForm;
//---------------------------------------------------------------------------
__fastcall TResultForm::TResultForm(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TResultForm::ContinueButtonClick(TObject *Sender)
{
  this->Close();        
}
//---------------------------------------------------------------------------
