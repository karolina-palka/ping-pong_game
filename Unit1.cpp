//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Paddle.h"
#include "Ball.h"
#include "Scoreboard.h"
#include <math>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
Paddle *paddle_left;
Paddle *paddle_right;
Ball *ball;
Scoreboard *scoreboard;
int bounceNumber=0;

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
    paddle_left = NULL;
    paddle_right = NULL;
    ball = NULL;
    scoreboard = NULL;
    paddle_left = new Paddle(20, 140, "paddle_left");
    paddle_right = new Paddle(976, 140, "paddle_right");
    ball = new Ball(500, 300, "ball");
    scoreboard = new Scoreboard;

}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormKeyDown(TObject *Sender, WORD &Key,
     TShiftState Shift)
{
    if (Key == VK_UP )right_up->Enabled = true;
    if (Key == VK_DOWN) right_down->Enabled = true;
    if (Key == 0x41) left_up->Enabled = true;
    if (Key == 0x5A) left_down->Enabled = true;

}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormKeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
    if (Key == VK_UP )right_up->Enabled = false;
    if (Key == VK_DOWN )right_down->Enabled = false;
    if (Key == 0x41) left_up->Enabled =false;
    if (Key == 0x5A) left_down->Enabled = false;
}

//---------------------------------------------------------------------------

bool __fastcall TForm1:: isCollidedWithLeftWall()
{                  
   bool status = false;
   if(ball->getLeft()<= paddle_left->getLeft() - paddle_left->getWidth() -5)
   status = true;
   return status;
}

bool __fastcall TForm1:: isCollidedWithRightWall()
{
   bool status = false;
   if (ball->getLeft() + ball->getWidth()>= paddle_right->getLeft() + paddle_right->getWidth() +15)
   status = true;
   return status;
}
void __fastcall TForm1:: ballWallCollision()
{
    char winner;
    if (isCollidedWithLeftWall() || isCollidedWithRightWall())
     {
        Timer1->Enabled=false;
        ball->setVisible(false);
        if (isCollidedWithLeftWall())
        {
            winner = 'r';
            int r_score = scoreboard->getR_playerScore();
            r_score++;
            scoreboard->setR_playerScore(r_score);
        }
        else
        {
            winner = 'l';
            int l_score = scoreboard->getL_playerScore();
            l_score++;
            scoreboard->setL_playerScore(l_score);
        }
        scoreboard->setPointsForPlayer(winner);
        scoreboard->setPoints();
        scoreboard->setBounceTotal(bounceNumber);
        newRound->Visible = true;
        newGame->Top = 260;
        newGame->Visible = true;
    }
}
bool __fastcall TForm1:: isCollidedWithPaddle()
{
    bool status = false;
    if (((ball->getLeft() - paddle_left->getWidth() <= paddle_left->getLeft())
    &&(ball->getTop() <=  paddle_left->getTop() + paddle_left->getHeight())
     && (ball->getTop() >= paddle_left->getTop()- ball->getHeight()/2) )
     ||
     ((ball->getLeft() + ball->getWidth() >= paddle_right->getLeft())
     &&(ball->getTop() <=  paddle_right->getTop() + paddle_right->getHeight())
     && (ball->getTop() >= paddle_right->getTop()- ball->getHeight()/2 ) ))
     status = true;
     return status;
}

bool __fastcall TForm1:: isBallCollidedWithCentrePaddle()
{
   bool status = false;
   if (((ball->getTop() >= paddle_right->getHeight()/2 -(ball->getHeight() + ball->getHeight()/2)) &&
       (ball->getTop()  <= paddle_right->getHeight()/2 + (ball->getHeight() + ball->getHeight()/2))
       || ((ball->getTop() >= paddle_left->getHeight()/2 -(ball->getHeight() + ball->getHeight()/2)) &&
       (ball->getTop() <= paddle_left->getHeight()/2 +(ball->getHeight() + ball->getHeight()/2)))))
        {
           status = true;
        }
   return status;
}

void __fastcall TForm1:: changeBallReboundAngle()
{
    double y_ball_new = 0;
    double x_ball = ball->getX_ball();
    double y_ball = ball->getY_ball();

    double vectorLenSq = x_ball*x_ball + y_ball*y_ball;
    double x_ball_new = 1.1*x_ball;
    double y_ballSq = (vectorLenSq - x_ball_new*x_ball_new);

    if (y_ballSq <0)
    {
        y_ballSq = -y_ballSq;
    }
    else if ( y_ballSq ==0)
    {
        x_ball_new = 0.9*x_ball;
        y_ballSq = ((x_ball*x_ball + y_ball*y_ball) - x_ball_new*x_ball_new);
    }
    y_ball_new = sqrt(y_ballSq);
    ball->setX_ball(x_ball_new);
    ball->setY_ball(y_ball_new);
}

void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
    char winner;
    ball->isCollidedWithDownWall(background);
    ball->isCollidedWithUpperWall(background);

    ballWallCollision();
    if (isCollidedWithPaddle())
    {
       double x_ball = -ball->getX_ball();
       double x_ball_new = ball->getLeft();
       x_ball_new += x_ball;
       ball->setLeft(x_ball_new);
       ball->setX_ball(x_ball);
       bounceNumber++;

       if (isBallCollidedWithCentrePaddle())
       {
           if ( Timer1->Interval >= 5)
           {
                Timer1->Interval = Timer1->Interval - 5;
                changeBallReboundAngle();
           }
        }
     }
     else if (isCollidedWithLeftWall()) {}
     else if (isCollidedWithRightWall()) {}

}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{
    Application->MessageBox("Welcome to the Ping-pong game!\n"
			"The left player controls by pressing the A and Z keys.\n"
			"The right player controls by pressing the up and down arrow keys.\n"
			"Have a nice game!\n",  "Ping-pong", MB_OK);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::newGameClick(TObject *Sender)
{
   if(newRound->Visible==true)
   {
        if (Application->MessageBox(
        "Are you sure you want to start again?\n", "Confirm", MB_YESNO)==IDYES)
        {
           newRound->Visible=false;
           newGame->Visible=false;
           scoreboard->isTLabelVisible(scoreboard->getPoints(), false);
           scoreboard->isTLabelVisible(scoreboard->getPointsForPlayer(), false);
           scoreboard->isTLabelVisible(scoreboard->getBounceTotal(), false);
           ball->setLeft(500);
           ball->setTop(300);
           ball->setVisible(true);
           scoreboard->setL_playerScore(0);
           scoreboard->setR_playerScore(0);

           bounceNumber = 0;
           Timer1->Interval = 50;
           ball->setX_ball(-8);
           ball->setY_ball(-8);
           Timer1->Enabled=true;
        }
   }
   else
   {
       newGame->Visible=false;
       int bounceNumber = 0;
       Timer1->Interval = 50;
       Timer1->Enabled=true;
   }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::newRoundClick(TObject *Sender)
{
   newGame->Visible=false;
   newRound->Visible=false;
   scoreboard->isTLabelVisible(scoreboard->getPoints(), false);
   scoreboard->isTLabelVisible(scoreboard->getPointsForPlayer(), false);
   scoreboard->isTLabelVisible(scoreboard->getBounceTotal(), false);
   ball->setLeft(500);
   ball->setTop(300);
   ball->setVisible(true);
   bounceNumber = 0;
   Timer1->Enabled=true;
   Timer1->Interval = 50;
   ball->setX_ball(-8);
   ball->setY_ball(-8);

}
//---------------------------------------------------------------------------

void __fastcall TForm1::left_upTimer(TObject *Sender)
{
   if (paddle_left->getTop() > 0)
   {
      int y_paddle = paddle_left->getY_paddle();
      int y_paddle_new_Top = paddle_left->getTop() + y_paddle;
      paddle_left->setTop(y_paddle_new_Top);
   }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::left_downTimer(TObject *Sender)
{
   if (paddle_left->getTop() +paddle_left->getHeight() < background->Height )
   {
      int y_paddle = paddle_left->getY_paddle();
      int y_paddle_new_Top = paddle_left->getTop() - y_paddle;
      paddle_left->setTop(y_paddle_new_Top);
   }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::right_upTimer(TObject *Sender)
{
   if (paddle_right->getTop() > 0)
   {
      int y_paddle = paddle_right->getY_paddle();
      int y_paddle_new_Top = paddle_right->getTop() + y_paddle;
      paddle_right->setTop(y_paddle_new_Top);
   }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::right_downTimer(TObject *Sender)
{
   if (paddle_right->getTop() + paddle_right->getHeight() < background->Height )
   {
      int y_paddle = paddle_right->getY_paddle();
      int y_paddle_new_Top = paddle_right->getTop() - y_paddle;
      paddle_right->setTop(y_paddle_new_Top);
   }
}
//---------------------------------------------------------------------------



