//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
USEFORM("MainUnit.cpp", MainForm);
USEFORM("Units\ResultUnit\ResultUnit.cpp", ResultForm);
USEFORM("Units\ConnectionOptions\ConnectionOptionsUnit.cpp", ConnectionOptionsForm);
USEFORM("Units\ProgressUnit\ProgressForm.cpp", ProgressShowForm);
USEFORM("Units\NewFreqTableUnit\NewFreqTableUnit.cpp", NewFreqTableForm);
USEFORM("Units\ProtocolCreateUnit\ProtocolCreateUnit.cpp", ProtocolCreateForm);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
        try
        {
                 Application->Initialize();
                 Application->CreateForm(__classid(TMainForm), &MainForm);
                 Application->CreateForm(__classid(TResultForm), &ResultForm);
                 Application->Run();
        }
        catch (Exception &exception)
        {
                 Application->ShowException(&exception);
        }
        catch (...)
        {
                 try
                 {
                         throw Exception("");
                 }
                 catch (Exception &exception)
                 {
                         Application->ShowException(&exception);
                 }
        }
        return 0;
}
//---------------------------------------------------------------------------
