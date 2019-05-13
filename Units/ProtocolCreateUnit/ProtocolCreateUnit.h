//---------------------------------------------------------------------------

#ifndef ProtocolCreateUnitH
#define ProtocolCreateUnitH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>

#include "MeasurmentUnit.h"
#include "MainUnit.h"
#include "ProgressForm.h"
#include "ProtocolCreateThread.h"
//---------------------------------------------------------------------------
class TProtocolCreateForm : public TForm
{
__published:	// IDE-managed Components
        TLabel *TypeLabel;
        TLabel *SerialNumberLabel;
        TLabel *OwnerLabel;
        TEdit *TypeEdit;
        TEdit *SerNumberEdit;
        TEdit *OwnerEdit;
        TButton *CreateProtocolButton;
        void __fastcall CreateProtocolButtonClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TProtocolCreateForm(TComponent* Owner);
        verificationInfo *Info;
        HANDLE hFinishedEvent;
};
//---------------------------------------------------------------------------
extern PACKAGE TProtocolCreateForm *ProtocolCreateForm;
//---------------------------------------------------------------------------
#endif
