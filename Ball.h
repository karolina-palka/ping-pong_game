#ifndef BallH
#define BallH

#include <vcl.h>
#pragma hdrstop
#include "Unit1.h"

class Ball
{
  int x_ball, y_ball;
  TImage *ball;
  public:
  __fastcall Ball(int left=1, int top=1, AnsiString name="")
  {
      x_ball = -8;
      y_ball = -8;
      ball = new TImage(NULL);
      ball->Parent = Form1;

      ball->Picture->LoadFromFile("img/my_paddle1.bmp");

      ball->Left = left;
      ball->Top = top;
      ball->Name = name;
      ball->AutoSize = true;
  };
};










#endif
