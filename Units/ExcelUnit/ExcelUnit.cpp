//---------------------------------------------------------------------------
#pragma hdrstop
#include "ExcelUnit.h"
//---------------------------------------------------------------------------
excellFileWriter::excellFileWriter(String filePath)
{
  this->Path = filePath;
}
//---------------------------------------------------------------------------
excellFileWriter::excellFileWriter()
{
  this->Path = "";
}
//---------------------------------------------------------------------------
int excellFileWriter::InitExcell(String filePath)
{
  CoInitialize(NULL);
  this->Path = filePath;
  try{
     ExcellApp=Variant::CreateObject("Excel.Application");
  }
  catch (...){
     return 1; //"Невозможно открыть Microsoft Excel!"
  }

  try{
    if(this->Path.Length()!=0){
      this->Books = ExcellApp.OlePropertyGet("WorkBooks");
      this->Book = this->Books.OlePropertyGet("Open", this->Path.c_str(), false);
    }
    else{
      ExcellApp.OlePropertyGet("WorkBooks").OleProcedure("add");
      this->Books = ExcellApp.OlePropertyGet("WorkBooks");
    }
    Sheet=ExcellApp.OlePropertyGet("WorkSheets",1);
    return 0;
  }
  catch(...){
    return 2; //Ошибка открытия книги Microsoft Excel
  }
}
//******************************************************************************
int excellFileWriter::ShowExcell()
{
 try{
   ExcellApp.OlePropertySet("Visible",true);
   return 0;
 }
 catch(...){
   return 1;
 }
}
//******************************************************************************
int excellFileWriter::CloseExcell()
{
  try{
    ExcellApp.OleProcedure("Quit");
    return 0;
  }
  catch(...){
    return 1;
  }
}
//******************************************************************************
int excellFileWriter::SaveAs(String newPath)
{
  try{
    this->Books.OlePropertyGet("Item", 1).OleProcedure("SaveAs", newPath);
    return 0;
  }
  catch(...){

    return 1;
  }
}
//******************************************************************************
int excellFileWriter::SaveBook(int ItemIndex)
{
  try{
    this->Books.OlePropertyGet("Item", ItemIndex).OleProcedure("Save");
    return 0;
  }
  catch(...){
    return 1;
  }
}
//******************************************************************************

int excellFileWriter::InputString(int Row, int Column, String data)
{
  try{
    Variant  currentCell = Sheet.OlePropertyGet("Cells", Row,Column);
    currentCell.OlePropertySet("Value", data.c_str());
    return 0;
  }
  catch(...){
    return 1;
  }
}
//******************************************************************************
int excellFileWriter::InputRow(int Row, int StartColumn, int Size, String *data)
{
  try{
    for (int i=0; i<Size; i++){
      Variant  currentCell = Sheet.OlePropertyGet("Cells", Row, i+StartColumn);
      currentCell.OlePropertySet("Value", data[i].c_str());
    }
  return 0;
  }
  catch(...){
    return 1;
  }
}
//******************************************************************************
int excellFileWriter::InputColumn(int Column, int StartRow, int Size, String *data)
{
  try{
    for (int i=0; i<Size; i++){
      Variant  currentCell = Sheet.OlePropertyGet("Cells", StartRow+i, Column);
      currentCell.OlePropertySet("Value", data[i].c_str());
    }
  return 0;
  }
  catch(...){
    return 1;
  }
}
//******************************************************************************
int excellFileWriter::InputTable(int StartRow, int StartColumn, int SizeX, int SizeY, String **data)
{
  try{
        for (int i=0; i<SizeX; i++){
           for (int j=0; j<SizeY; j++){
              Variant  currentCell = Sheet.OlePropertyGet("Cells", StartRow+i, StartColumn+j);
              currentCell.OlePropertySet("Value", data[i][j].c_str());
           }
        }
  return 0;
  }
  catch(...){
     return 1;
  }
}
//******************************************************************************
int excellFileWriter::MakeBorder(int Row, int Column)
{
  try{
    Variant currentCell = this->Sheet.OlePropertyGet("Cells", Row, Column);
    for(int k=1; k<=4; k++)
      currentCell.OlePropertyGet("Borders").OlePropertyGet("Item", k).OlePropertySet("LineStyle", 1);
    return 1;
  }
  catch(...){
     return 1;
  }
}
//******************************************************************************
int excellFileWriter::MakeBorder(int StartRow, int StartColumn, int SizeX, int SizeY)
{
  try{
    for (int i=0; i<SizeX; i++){
      for (int j=0; j<SizeY; j++){
         Variant currentCell = this->Sheet.OlePropertyGet("Cells", StartRow+i, StartColumn+j);
         for(int k=1; k<=4; k++)
            currentCell.OlePropertyGet("Borders").OlePropertyGet("Item", k).OlePropertySet("LineStyle", 1);
      }
    }
    return 0;
  }
  catch(...){
    return 1;
  }
}
//******************************************************************************
int excellFileWriter::formulaExcel(int sRow, int sColumn, String formula)
{
   try {
      ExcellApp.OlePropertyGet("Cells", sRow, sColumn).OlePropertySet("Value", formula.c_str());
      return 0;
   }
   catch(...) {
      return 1;
   }
}
//******************************************************************************
#pragma package(smart_init)
