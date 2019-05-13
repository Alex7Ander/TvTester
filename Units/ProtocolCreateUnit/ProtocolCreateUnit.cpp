//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ProtocolCreateUnit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TProtocolCreateForm *ProtocolCreateForm;
//---------------------------------------------------------------------------
__fastcall TProtocolCreateForm::TProtocolCreateForm(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TProtocolCreateForm::CreateProtocolButtonClick(
      TObject *Sender)
{
  Info = new verificationInfo();
  Info->deviceType = this->TypeEdit->Text.c_str();
  Info->deviceSerialNumber = this->SerNumberEdit->Text.c_str();
  Info->deviceOwner = this->OwnerEdit->Text.c_str();
  String protocolPath;
  TSaveDialog *sD = new TSaveDialog(this);
  if (sD->Execute()){
    protocolPath = sD->FileName;
    MainForm->verification->createProtocol(protocolPath.c_str(), Info);
    Application->CreateForm(__classid(TProgressShowForm), &ProgressShowForm);
    ProtocolCreateThread *pcThread = new ProtocolCreateThread(true);
    pcThread->setProtocolPath(protocolPath);
    pcThread->Resume();
    ProgressShowForm->ShowModal();
    DWORD dwRes = WaitForSingleObject(this->hFinishedEvent, INFINITE);
    if (dwRes!=WAIT_OBJECT_0){
       //
    }
    CloseHandle(this->hFinishedEvent);
  }
}
//---------------------------------------------------------------------------
