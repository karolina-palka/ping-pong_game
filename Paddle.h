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
//#include "Unit1.h"
#include <vector>

class Paddle
{
 int y_paddle;
 public:
 Paddle(int y_paddle_new=30, int left=20, int top=130)
 {
      y_paddle = y_paddle_new;
      TImage *paddle = new TImage(NULL);
      paddle->Parent = Form1;

      paddle->Picture->LoadFromFile("img/my_paddle1.bmp");

      paddle->Left = left;
      paddle->Top = top;
      paddle->AutoSize = true;
 };
  //void MoveThePaddle(WORD &Key);

}


#endif
