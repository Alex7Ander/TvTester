//---------------------------------------------------------------------------
#ifndef ConnectionOptionsUnitH
#define ConnectionOptionsUnitH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>

#include "MainUnit.h"
//---------------------------------------------------------------------------
class TConnectionOptionsForm : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label1;
        TEdit *IpGenEdit1;
        TLabel *Label2;
        TEdit *PortGeneratorEdit;
        TLabel *Label3;
        TLabel *Label4;
        TEdit *PortPowerrMeterEdit;
        TBitBtn *SaveOptionsButton;
        TBitBtn *CancelButton;
        TEdit *IpGenEdit2;
        TEdit *IpGenEdit3;
        TEdit *IpGenEdit4;
        TLabel *Label5;
        TLabel *Label6;
        TLabel *Label7;
        TEdit *IpPowerMeterEdit1;
        TEdit *IpPowerMeterEdit2;
        TEdit *IpPowerMeterEdit3;
        TEdit *IpPowerMeterEdit4;
        TLabel *Label8;
        TLabel *Label9;
        TLabel *Label10;
        void __fastcall SaveOptionsButtonClick(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall CancelButtonClick(TObject *Sender);
        void __fastcall FormShow(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TConnectionOptionsForm(TComponent* Owner);
        void TConnectionOptionsForm::setConnectionInfo(string connectionFilePath);
};
//---------------------------------------------------------------------------
extern PACKAGE TConnectionOptionsForm *ConnectionOptionsForm;
//---------------------------------------------------------------------------
#endif
