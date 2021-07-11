//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Paddle.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
Paddle *paddle_left;
Paddle *paddle_right;
//Paddle paddle_left(30, 20, 130);
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
    paddle_left = NULL;
    paddle_right = NULL;
    paddle_left = new Paddle(20, 130, "paddle_left");
    paddle_right = new Paddle(976, 130, "paddle_right");

}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormKeyDown(TObject *Sender, WORD &Key,
     TShiftState Shift)
{
 //   paddle_left.MoveThePaddle(WORD &Key);
}
//---------------------------------------------------------------------------
