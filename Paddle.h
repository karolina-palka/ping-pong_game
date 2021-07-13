//---------------------------------------------------------------------------

#ifndef PaddleH
#define PaddleH

#include <vcl.h>
#pragma hdrstop
#include "Unit1.h"

class Paddle
{
 int y_paddle;
 TImage *paddle;
 TTimer* Timer2;
 public:
 __fastcall Paddle(int left=1, int top=1, AnsiString name="")
 {
      y_paddle = -50;
      paddle = new TImage(NULL);
      Timer2 = new TTimer(NULL);
      paddle->Parent = Form1;
      //Timer2->Parent = Form1;

      Timer2->Interval = 20;
      paddle->Picture->LoadFromFile("img/my_paddle1.bmp");

      paddle->Left = left;
      paddle->Top = top;
      paddle->Name = name;
      paddle->AutoSize = true;
 };
 __fastcall ~Paddle(){};
   void __fastcall MoveThePaddle(WORD &Key, WORD &Key1, WORD &Key2, TShape* background);
   void __fastcall Timer2Timer();
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
   int getHeight()
  {
       return paddle->Height;
  }
   int getLeft()
  {
       return paddle->Left;
  }
  void setTop(int newTop)
  {
      paddle->Top = newTop;
  }
};

#endif
