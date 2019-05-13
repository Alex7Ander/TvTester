//---------------------------------------------------------------------------

#ifndef ProgressFormH
#define ProgressFormH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TProgressShowForm : public TForm
{
__published:	// IDE-managed Components
        TLabel *MainLabel;
        TProgressBar *ProgressBar1;
        TTimer *Timer1;
        TLabel *StatusLabel;
        void __fastcall Timer1Timer(TObject *Sender);
        void __fastcall FormShow(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
public:		// User declarations
        __fastcall TProgressShowForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TProgressShowForm *ProgressShowForm;
//---------------------------------------------------------------------------
#endif
