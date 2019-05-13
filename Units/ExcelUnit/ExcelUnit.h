//---------------------------------------------------------------------------
#ifndef ExcelUnitH
#define ExcelUnitH
#include <windows.h>
#include <ComObj.hpp>
//---------------------------------------------------------------------------
class excellFileWriter
{
private:
        Variant ExcellApp;
        Variant Books;
        Variant Book;
        Variant Sheet;
        String Path;

public:
        excellFileWriter(String filePath);
        excellFileWriter();
        
        String getFilePath(){return Path;}

        int InitExcell(String filePath);
        int ShowExcell();

        int InputString(int Row, int Column, String data);
        int InputRow(int Row, int StartColumn, int Size, String *data);
        int InputColumn(int Column, int StartRow, int Size, String *data);
        int InputTable(int StartColumn, int StartRow, int SizeX, int SizeY, String **data);
        int formulaExcel(int sRow, int sColumn, String formula);

        int MakeBorder(int StartRow, int StartColumn, int SizeX, int SizeY);
        int MakeBorder(int Row, int Column);

        int SaveAs(String newPath);
        int SaveBook(int ItemIndex);
        int CloseExcell();
};
#endif
