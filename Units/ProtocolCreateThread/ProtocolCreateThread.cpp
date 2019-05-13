//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "ProtocolCreateThread.h"
#pragma package(smart_init)
__fastcall ProtocolCreateThread::ProtocolCreateThread(bool CreateSuspended)
        : TThread(CreateSuspended)
{
statusString = "";
}
//---------------------------------------------------------------------------
void __fastcall ProtocolCreateThread::Execute()
{
  CreateProtocol();
}
//---------------------------------------------------------------------------
void __fastcall ProtocolCreateThread::CreateProtocol()
{
//***
  statusString = "Начало формирования протокола";
  this->Synchronize(&ChangeStatus);
  String protocolFrom = GetCurrentDir()+"\\freqFiles\\PRT.xlsx";
  //***
  statusString = "Копирование файла";
  this->Synchronize(&ChangeStatus);
  ProtocolPath+=".xlsx";
  int res = CopyFile((LPCTSTR)protocolFrom.c_str(), (LPCTSTR)ProtocolPath.c_str(), false);
  //***
  excellFileWriter *eWriter = new excellFileWriter();
  statusString = "Инициализация";
  this->Synchronize(&ChangeStatus);
  eWriter->InitExcell(ProtocolPath);

  statusString = "Заполнение заголовка файла";
  this->Synchronize(&ChangeStatus);
  eWriter->InputString(3, 3, ProtocolCreateForm->Info->deviceType.c_str()); //Средство измерения
  eWriter->InputString(5, 4, ProtocolCreateForm->Info->deviceSerialNumber.c_str()); //Серийный номер
  String resString = "и на основании результатов периодической поверки признано ";
  eWriter->InputString(12, 4, resString);

  statusString = "Заполнение таблиц";
  this->Synchronize(&ChangeStatus);
  int currentString = 21;
  /*
  for (int d=0; d<FormResults->verificatedDevice->getCountOfElements(); d++)
  {
     statusString = "Заполнение таблиц для " + FormResults->verificatedDevice->includedElement[d].getTypeOfElement()+" серийный номер: "+FormResults->verificatedDevice->includedElement[d].getSerialNumber();
     this->Synchronize(&ChangeStatus);
     FormResults->verElementsComboBox->ItemIndex = d;
     FormResults->verElementsComboBoxChange(FormResults->verElementsComboBox);
     String str = FormResults->verificatedDevice->includedElement[d].getTypeOfElement()+" серийный номер: "+FormResults->verificatedDevice->includedElement[d].getSerialNumber();
     eWriter->InputString(currentString, 1, str); currentString++;
     String sParametrs[4]={"S11","S12","S21","S22"};
     //s11
     eWriter->InputString(currentString, 1, sParametrs[0]);
     currentString++;
     for (int i=0; i<FormResults->TableResults->RowCount; i++){
          for (int j=0; j<12; j++){
             if (j<11)
               str = FormResults->TableResults->Cells[j][i];
             else
               str="=(1+C"+IntToStr(currentString)+")/(1-C"+IntToStr(currentString)+")";
             eWriter->InputString(currentString, 1+j, str);
             eWriter->MakeBorder(currentString, 1+j);
          }
          if (i==0){
            eWriter->InputString(currentString, 12, "КСВН");
            eWriter->MakeBorder(currentString, 12);
          }
          currentString++;
     }
     //s12
     eWriter->InputString(currentString, 1, sParametrs[1]);
     currentString++;
     for (int i=0; i<FormResults->TableResults->RowCount; i++){
       for (int j=0; j<11; j++){
          if (j==0)
            str = FormResults->TableResults->Cells[j][i];
          else
            str = FormResults->TableResults->Cells[j+10][i];
          eWriter->InputString(currentString, 1+j, str);
          eWriter->MakeBorder(currentString, 1+j);
       }
       currentString++;
     }
     //s21
     eWriter->InputString(currentString, 1, sParametrs[2]);
     currentString++;
     for (int i=0; i<FormResults->TableResults->RowCount; i++){
       for (int j=0; j<11; j++){
          if (j==0)
            str = FormResults->TableResults->Cells[j][i];
          else
            str = FormResults->TableResults->Cells[j+20][i];
          eWriter->InputString(currentString, 1+j, str);
          eWriter->MakeBorder(currentString, 1+j);
       }
       currentString++;
     }
     //s22
     eWriter->InputString(currentString, 1, sParametrs[3]);
     currentString++;
     for (int i=0; i<FormResults->TableResults->RowCount; i++){
       for (int j=0; j<12; j++){
          if (j==0)
            str = FormResults->TableResults->Cells[j][i];
          else if (j>0 && j<11)
            str = FormResults->TableResults->Cells[j+30][i];
          else
            str="=(1+C"+IntToStr(currentString)+")/(1-C"+IntToStr(currentString)+")";  //Расчет КСВН
          eWriter->InputString(currentString, 1+j, str);
          eWriter->MakeBorder(currentString, 1+j);
       }
       if (i==0){
         eWriter->InputString(currentString, 12, "КСВН");
         eWriter->MakeBorder(currentString, 12);
       }
       currentString++;
     }
  }
  statusString = "Завершение формирования протокола";
  this->Synchronize(&ChangeStatus);
  eWriter->SaveBook(1);
  eWriter->ShowExcell();
  statusString = "Конец";
  this->Synchronize(&ChangeStatus);
  SetEvent(ProtocolCreateForm->hFinishedEvent);
  */
return;
}
//----------------------------------------------------------------------------
void __fastcall ProtocolCreateThread::ChangeStatus()
{
/*
  ProgressShowForm->StatusLabel->Caption = this->statusString;
  if (this->statusString == "Конец")  ProgressShowForm->Close();     */
  return;
}
//----------------------------------------------------------------------------
void __fastcall ProtocolCreateThread::CreateFinishedEvent()
{

}

