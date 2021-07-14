//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
#include <MPlayer.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TShape *background;
        TTimer *Timer1;
        TButton *newGame;
        TButton *newRound;
        TTimer *left_up;
        TTimer *left_down;
        TTimer *right_up;
        TTimer *right_down;
        TShape *vertical;
        TShape *horizontal;
        void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);

        void __fastcall Timer1Timer(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall newGameClick(TObject *Sender);
        void __fastcall newRoundClick(TObject *Sender);
        void __fastcall left_upTimer(TObject *Sender);
        void __fastcall left_downTimer(TObject *Sender);
        void __fastcall right_upTimer(TObject *Sender);
        void __fastcall right_downTimer(TObject *Sender);
        void __fastcall FormKeyUp(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall FormResize(TObject *Sender);
private:
        bool __fastcall isCollidedWithLeftWall();
        bool __fastcall isCollidedWithRightWall();
        bool __fastcall isBallCollidedWithCenterPaddle();
        bool __fastcall isCollidedWithPaddle();
        void __fastcall checkLeftRightWallCollision();
        void __fastcall changeBallReboundAngle();
	// User declarations
public:	
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
