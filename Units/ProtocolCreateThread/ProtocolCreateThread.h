//---------------------------------------------------------------------------

#ifndef ProtocolCreateThreadH
#define ProtocolCreateThreadH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <windows.h>
#include "ProgressForm.h"
#include "ProtocolCreateUnit.h"
#include "ExcelUnit.h"
//---------------------------------------------------------------------------
class ProtocolCreateThread : public TThread
{            
private:
        String statusString;
        void __fastcall CreateProtocol();
        void __fastcall ChangeStatus();
        void __fastcall CreateFinishedEvent();
        String ProtocolPath;
protected:
        void __fastcall Execute();
public:
        __fastcall ProtocolCreateThread(bool CreateSuspended);
        void setProtocolPath(String Path){ProtocolPath = Path;}
};
//---------------------------------------------------------------------------
#endif
 