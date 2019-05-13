//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "ConnectionOptionsUnit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TConnectionOptionsForm *ConnectionOptionsForm;
//---------------------------------------------------------------------------
__fastcall TConnectionOptionsForm::TConnectionOptionsForm(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TConnectionOptionsForm::SaveOptionsButtonClick(
      TObject *Sender)
{
  try{
    int tInt = StrToInt(this->IpGenEdit1->Text);
    tInt = StrToInt(this->IpGenEdit2->Text);
    tInt = StrToInt(this->IpGenEdit3->Text);
    tInt = StrToInt(this->IpGenEdit4->Text);
    tInt = StrToInt(this->IpPowerMeterEdit1->Text);
    tInt = StrToInt(this->IpPowerMeterEdit2->Text);
    tInt = StrToInt(this->IpPowerMeterEdit3->Text);
    tInt = StrToInt(this->IpPowerMeterEdit4->Text);
    int portGen = StrToInt(this->PortGeneratorEdit->Text);
    int portPM = StrToInt(this->PortPowerrMeterEdit->Text);
    String GenIP = this->IpGenEdit1->Text+"."+
                   this->IpGenEdit2->Text+"."+
                   this->IpGenEdit3->Text+"."+this->IpGenEdit4->Text;
    String PMIp  = this->IpPowerMeterEdit1->Text+"."+
                   this->IpPowerMeterEdit2->Text+"."+
                   this->IpPowerMeterEdit3->Text+"."+this->IpPowerMeterEdit4->Text;
    MainForm->setConnectionInfo(GenIP.c_str(), portGen, PMIp.c_str(), portPM);

    ofstream conInfoFile;
    conInfoFile.open("connectionInfo.dat");
    conInfoFile << GenIP.c_str() << endl;
    conInfoFile << portGen << endl;
    conInfoFile << PMIp.c_str() << endl;
    conInfoFile << portPM << endl;
    conInfoFile.close();
  }
  catch(...){
    MessageBox(NULL, LPCTSTR("Вы ввели значение ip или порта в неправильном формате"), LPCTSTR("Ошибка!"), MB_OK | MB_ICONERROR);
  }
}
//---------------------------------------------------------------------------
void __fastcall TConnectionOptionsForm::CancelButtonClick(TObject *Sender)
{
  this->Close();
}
//---------------------------------------------------------------------------
void __fastcall TConnectionOptionsForm::FormClose(TObject *Sender,
      TCloseAction &Action)
{
  Action = caFree;
}
//---------------------------------------------------------------------------
void TConnectionOptionsForm::setConnectionInfo(string connectionFilePath)
{
  ifstream conInfoFile;
  String IPs[2];
  conInfoFile.open(connectionFilePath.c_str());
  char buff[100];
  conInfoFile.getline(buff, 100);
  IPs[0] = buff;
  conInfoFile.getline(buff, 10);
  this->PortGeneratorEdit->Text = IntToStr(atoi(buff));
  conInfoFile.getline(buff, 100);
  IPs[1] = buff;
  conInfoFile.getline(buff, 10);
  this->PortPowerrMeterEdit->Text = IntToStr(atoi(buff));
  conInfoFile.close();

  String tStr;
  for (int i=0; i<4; i++){
    tStr = IPs[0];
    for (int j=0; j<i; j++){
      tStr = tStr.Delete(1, tStr.Pos("."));
    }
    tStr = tStr.Delete(tStr.Pos("."), tStr.Length());
    switch(i){
      case 0: this->IpGenEdit1->Text = tStr; break;
      case 1: this->IpGenEdit2->Text = tStr; break;
      case 2: this->IpGenEdit3->Text = tStr; break;
      case 3: this->IpGenEdit4->Text = tStr; break;
    }
  }

  for (int i=0; i<4; i++){
    tStr = IPs[1];
    for (int j=0; j<i; j++){
      tStr = tStr.Delete(1, tStr.Pos("."));
    }
    tStr = tStr.Delete(tStr.Pos("."), tStr.Length());
    switch(i){
      case 0: this->IpPowerMeterEdit1->Text = tStr; break;
      case 1: this->IpPowerMeterEdit2->Text = tStr; break;
      case 2: this->IpPowerMeterEdit3->Text = tStr; break;
      case 3: this->IpPowerMeterEdit4->Text = tStr; break;
    }
  }

  return;
}
//---------------------------------------------------------------------------
void __fastcall TConnectionOptionsForm::FormShow(TObject *Sender)
{
  string connectionFilePath = "connectionInfo.dat";
  setConnectionInfo(connectionFilePath);
}
//---------------------------------------------------------------------------

