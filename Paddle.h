//---------------------------------------------------------------------------

#ifndef PaddleH
#define PaddleH

#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>

#include <vcl.h>
#pragma hdrstop
#include "Unit1.h"

class Paddle
{
 int y_paddle;
 TImage *paddle;
 public:
 __fastcall Paddle(int left=1, int top=1, AnsiString name="")
 {
      y_paddle = -30;
      paddle = new TImage(NULL);
      paddle->Parent = *Form1;

      paddle->Picture->LoadFromFile("img/my_paddle1.bmp");

      paddle->Left = left;
      paddle->Top = top;
      paddle->Name = name;
      paddle->AutoSize = true;
 };
 __fastcall ~Paddle(){};
   void __fastcall MoveThePaddle(WORD &Key, WORD &Key1, WORD &Key2, TShape* background);
  int getY_paddle()
  {
       return y_paddle;
  }
  void setY_Top(int newY_Top)
  {
     paddle->Top = newY_Top;
  }
  int getTop()
  {
       return paddle->Top;
  }
  int getWidth()
  {
       return paddle->Width;
  }

};

#endif
