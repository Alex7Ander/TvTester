//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "ProgressForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TProgressShowForm *ProgressShowForm;
//---------------------------------------------------------------------------
__fastcall TProgressShowForm::TProgressShowForm(TComponent* Owner)
        : TForm(Owner)
{
  ProgressShowForm->FormStyle=fsStayOnTop;
}
//---------------------------------------------------------------------------
void __fastcall TProgressShowForm::Timer1Timer(TObject *Sender)
{
  this->ProgressBar1->Position += 10;
  if (this->ProgressBar1->Position==100)
    this->ProgressBar1->Position = 0;
}
//---------------------------------------------------------------------------
void __fastcall TProgressShowForm::FormShow(TObject *Sender)
{
  this->Timer1->Enabled = true;        
}
//---------------------------------------------------------------------------
void __fastcall TProgressShowForm::FormClose(TObject *Sender,
      TCloseAction &Action)
{
  Action = caFree;        
}
//---------------------------------------------------------------------------
