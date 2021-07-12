//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Paddle.h"
#include "Ball.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
Paddle *paddle_left;
Paddle *paddle_right;
Ball *ball;

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
    paddle_left = NULL;
    paddle_right = NULL;
    ball = NULL;
    paddle_left = new Paddle(20, 130, "paddle_left");
    paddle_right = new Paddle(976, 180, "paddle_right");
    ball = new Ball(700, 300, "ball");

}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormKeyDown(TObject *Sender, WORD &Key,
     TShiftState Shift)
{
    paddle_left->MoveThePaddle(Key, 0x41, 0x5A, background);
    paddle_right->MoveThePaddle(Key, VK_UP, VK_DOWN, background);

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer1Timer(TObject *Sender)
{

    ball->isCollidedWithDownWall(background);
    ball->isCollidedWithUpperWall(background);

     if (ball->getLeft() - ball->getWidth()<= paddle_left->getLeft() - paddle_left->getWidth() )
    {
        Timer1->Enabled=false;
        ball->setVisible(false);
    }

    else if (((ball->getLeft() - ball->getWidth() <= paddle_left->getLeft()-5)
    &&(ball->getTop()  <=  paddle_left->getTop() + paddle_left->getHeight() + 5)
     && (ball->getTop() > paddle_left->getTop()- ball->getHeight()/2) )
     ||
     ((ball->getLeft() + ball->getWidth() >= paddle_right->getLeft()+5)
    &&(ball->getTop()  <=  paddle_right->getTop() + paddle_right->getHeight()+ 5)
     && (ball->getTop() > paddle_right->getTop()- ball->getHeight()/2) ))
    {

       int x_ball = -ball->getX_ball();
       int x_ball_new = ball->getLeft();
       x_ball_new += x_ball;
       ball->setLeft(x_ball_new);
       ball->setX_ball(x_ball);
    }

}
//---------------------------------------------------------------------------

