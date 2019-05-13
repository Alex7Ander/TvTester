//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "MainUnit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TMainForm *MainForm;
//---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent* Owner)
        : TForm(Owner)
{
  try{
    FreqTableComboBox->Items->LoadFromFile("list.dat");
  }
  catch(...){
    MessageBox(NULL, LPCTSTR("Ошибка чтения частотных таблиц: файл list.dat отсутствует или поврежден"), LPCTSTR("Ошибка!"), MB_OK | MB_ICONERROR);
  }
  if (FreqTableComboBox->Items->Count==0){
    MessageBox(NULL, LPCTSTR("Файл с частотными таблицами пуст"), LPCTSTR("Ошибка!"), MB_OK | MB_ICONERROR);
  }

  ResultsStringGrid->ColCount = 4;
  String titles[4]={"Частота, МГц", "P действ. dBuV", "P повер. dBuV", "dP"};
  for(int i=0; i<ResultsStringGrid->ColCount; i++){
    ResultsStringGrid->ColWidths[i] = ResultsStringGrid->Width/ResultsStringGrid->ColCount-10;
    ResultsStringGrid->Cells[i][0] = titles[i];
  }
  string connectionFilePath = "connectionInfo.dat";
  setConnectionInfo(connectionFilePath);

  verification = new Measurement(this->IpGenerator, this->portGenerator, this->IPPowerMetr, this->portPowerMeter);
}
//---------------------------------------------------------------------------
void TMainForm::setConnectionInfo(string ipGen, int portGen, string ipPM, int portPM)
{
  this->IpGenerator = ipGen;
  this->portGenerator = portGen;
  this->IPPowerMetr = ipPM;
  this->portPowerMeter = portPM;
  return;
}
void TMainForm::setConnectionInfo(string connectionFilePath)
{
  ifstream conInfoFile;
  conInfoFile.open(connectionFilePath.c_str());
  char buff[100];
  conInfoFile.getline(buff, 100);
  this->IpGenerator = buff;
  conInfoFile.getline(buff, 10);
  this->portGenerator = atoi(buff);
  conInfoFile.getline(buff, 100);
  this->IPPowerMetr = buff;
  conInfoFile.getline(buff, 10);
  this->portPowerMeter = atoi(buff);
  conInfoFile.close();
  return;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::StartButtonClick(TObject *Sender)
{
  double initPower = StrToFloat(this->PowerEdit->Text);
  verification->startMeasurement(initPower);
  int cFreq = verification->getCountOfFreq();
  for (int i=0; i<cFreq; i++){
     verification->nextStep(i);
     ResultForm->Show();
     double result;
     verification->takeResult(i, result);
  }
  verification->stopMeasurement();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::ConnectionOptionsButtonClick(TObject *Sender)
{
  Application->CreateForm(__classid(TConnectionOptionsForm), &ConnectionOptionsForm);
  ConnectionOptionsForm->ShowModal();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::SaveButtonClick(TObject *Sender)
{
  TSaveDialog *sD = new TSaveDialog(this);
  if (sD->Execute()){
     String protoFilePath = sD->FileName;
     verification->saveTxtFile(protoFilePath.c_str());
  }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::ProtocolButtonClick(TObject *Sender)
{
  Application->CreateForm(__classid(TProtocolCreateForm), &ProtocolCreateForm);
  ProtocolCreateForm->ShowModal();      
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::FreqTableComboBoxChange(TObject *Sender)
{
  if(this->FreqTableComboBox->ItemIndex==-1){
    MessageBox(NULL, LPCTSTR("Вы не выбрали частотную сетку"), LPCTSTR("Ошибка!"), MB_OK | MB_ICONERROR);
  }
  else{
    String freqFilePath = GetCurrentDir()+"\\freqFiles\\"+this->FreqTableComboBox->Text+".dat";
    verification->readFreqTable(freqFilePath.c_str());
    int freqCount = verification->getCountOfFreq();
    if (freqCount>0){
      this->ResultsStringGrid->RowCount = freqCount+1;
      for (int i=0; i<freqCount; i++){
        this->ResultsStringGrid->Cells[0][i+1] = verification->getFreq(i);
      }
    }
  }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::AddFreqTableButtonClick(TObject *Sender)
{
  Application->CreateForm(__classid(TNewFreqTableForm), &NewFreqTableForm);
  NewFreqTableForm->ShowModal();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::CancelButtonClick(TObject *Sender)
{
  verification->stopMeasurement();
  for (int i=0; i<this->ResultsStringGrid->RowCount; i++){
    for (int j=0; j<this->ResultsStringGrid->ColCount; j++){
      this->ResultsStringGrid->Cells[j][i+1]="";
    }
  }
  this->ResultsStringGrid->RowCount = 2;
  this->FreqTableComboBox->ItemIndex = -1;
}
//---------------------------------------------------------------------------
