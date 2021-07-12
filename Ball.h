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

      ball->Picture->LoadFromFile("img/my_ball.bmp");

      ball->Left = left;
      ball->Top = top;
      ball->Name = name;
      ball->AutoSize = true;
      ball->Transparent = true;
  };
  int getX_ball()
  {
      return x_ball;
  }
   int getY_ball()
  {
      return y_ball;
  }
   int getLeft()
  {
      return ball->Left;
  }
  int getWidth()
  {
      return ball->Width;
  }
   int getTop()
  {
      return ball->Top;
  }
   int getHeight()
  {
      return ball->Height;
  }
  void setTop(int newTop)
  {
     ball->Top = newTop;
  }
   void setLeft(int newLeft)
  {
     ball->Left = newLeft;
  }
  void setVisible(bool status)
  {
      ball->Visible = status;
  }
  void setY_ball(int newY_ball)
  {
      ball->y_ball = newY_ball;
  }
  void setx_ball(int newX_ball)
  {
      ball->x_ball = newX_ball;
  }
};










#endif
