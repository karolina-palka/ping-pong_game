#include <vcl.h>
#pragma hdrstop

#include "Paddle.h"
//#include "Unit1.h"

void __fastcall Paddle:: MoveThePaddle(WORD &Key, WORD &Key1, WORD &Key2, TShape* background)
{
         //int y_paddle = paddle->y_paddle();
         paddle->Parent = Form1;
       if (Key == Key1 && getTop() > 15)
        {
             int y_paddle_new_Top = getTop();
             y_paddle_new_Top += y_paddle;
             setY_Top(y_paddle_new_Top);
        }
        if (Key == Key2 && getTop()  <= background->Height - getTop()+90)
        {
           int y_paddle_new_right = getTop();
           y_paddle_new_right = y_paddle_new_right- y_paddle;
           setY_Top(y_paddle_new_right);
        }
}
