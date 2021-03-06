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
 public:
 __fastcall Paddle(int left=1, int top=1, AnsiString name="")
 {
      y_paddle = -20;
      paddle = new TImage(NULL);
      paddle->Parent = Form1;
  
      paddle->Picture->Bitmap->Handle=LoadBitmap(HInstance,"paddle3");
     
      paddle->Left = left;
      paddle->Top = top;
      paddle->Name = name;
      paddle->AutoSize = true;
      paddle->Transparent=true;
 };
 __fastcall ~Paddle(){};
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
  void setLeft(int newLeft)
  {
      paddle->Left = newLeft;
  }
};

#endif
