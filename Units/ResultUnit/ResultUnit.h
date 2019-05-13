//---------------------------------------------------------------------------

#ifndef ResultUnitH
#define ResultUnitH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TResultForm : public TForm
{
__published:	// IDE-managed Components
        TGroupBox *ResultGroupBox;
        TLabel *InfoLabel4;
        TLabel *FreqLabel;
        TLabel *InfoLabel5;
        TEdit *ResultEdit;
        TButton *ContinueButton;
        void __fastcall ContinueButtonClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TResultForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TResultForm *ResultForm;
//---------------------------------------------------------------------------
#endif
