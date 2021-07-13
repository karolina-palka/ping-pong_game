#ifndef BallH
#define BallH

#include <vcl.h>
#pragma hdrstop
#include "Unit1.h"

class Ball
{
  double x_ball, y_ball;
  TImage *ball;
  public:
  __fastcall Ball(int left=1, int top=1, AnsiString name="")
  {
      x_ball = -8.0;
      y_ball = -8.0;
      ball = new TImage(NULL);
      ball->Parent = Form1;

      ball->Picture->LoadFromFile("img/my_ball.bmp");

      ball->Left = left;
      ball->Top = top;
      ball->Name = name;
      ball->AutoSize = true;
      ball->Transparent = true;
  };
  double getX_ball()
  {
      return x_ball;
  }
   double getY_ball()
  {
      return y_ball;
  }
   double getLeft()
  {
      return ball->Left;
  }
  double getWidth()
  {
      return ball->Width;
  }
   double getTop()
  {
      return ball->Top;
  }
   double getHeight()
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
      y_ball = newY_ball;
  }
  void setX_ball(int newX_ball)
  {
      x_ball = newX_ball;
  }
  void updateBallPosition();
  bool isCollidedWithUpperWall(TShape* background);
  bool isCollidedWithDownWall(TShape* background);
};
#endif
