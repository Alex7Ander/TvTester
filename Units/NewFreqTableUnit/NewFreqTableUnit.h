//---------------------------------------------------------------------------

#ifndef NewFreqTableUnitH
#define NewFreqTableUnitH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <Grids.hpp>
#include <string.h>

#include "FreqTableClass.h"
//---------------------------------------------------------------------------
class TNewFreqTableForm : public TForm
{
__published:	// IDE-managed Components
        TLabel *FreqCountLabel;
        TEdit *FreqCountEdit;
        TStringGrid *FreqTableStringGrid;
        TButton *SaveButton;
        TLabel *NameLabel;
        TEdit *NameEdit;
        void __fastcall CancelButtonClick(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall FreqCountEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall SaveButtonClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TNewFreqTableForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TNewFreqTableForm *NewFreqTableForm;
//---------------------------------------------------------------------------
#endif
