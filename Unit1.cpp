//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Paddle.h"
#include "Ball.h"
#include "Scoreboard.h"
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
    paddle_left = new Paddle(20, 110, "paddle_left");
    paddle_right = new Paddle(976, 110, "paddle_right");
    ball = new Ball(500, 300, "ball");
    scoreboard = new Scoreboard;

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
    char winner;
    //int bounceNumber=0;
    ball->isCollidedWithDownWall(background);
    ball->isCollidedWithUpperWall(background);

     if (ball->getLeft() - ball->getWidth()<= paddle_left->getLeft() - paddle_left->getWidth() -15)
    {
        Timer1->Enabled=false;
        ball->setVisible(false);
        winner = 'r';
        int r_score = scoreboard->getR_playerScore();
        r_score++;
        scoreboard->setR_playerScore(r_score);
        scoreboard->setPointsForPlayer(winner);
        scoreboard->setPoints();
        scoreboard->setBounceTotal(bounceNumber);
        newRound->Visible = true;
        newGame->Top = 240;
        newGame->Visible = true;
    }
    else if (ball->getLeft() + ball->getWidth()>= paddle_right->getLeft() + paddle_right->getWidth() +15)
    {
       Timer1->Enabled=false;
       ball->setVisible(false);
       winner = 'l';
       int l_score = scoreboard->getL_playerScore();
       l_score++;
       scoreboard->setL_playerScore(l_score);
       scoreboard->setPointsForPlayer(winner);
       scoreboard->setPoints();
       scoreboard->setBounceTotal(bounceNumber);
       newRound->Visible=true;
       newGame->Top = 240;
       newGame->Visible = true;
    }
     //- ball->getHeight()/2)
     //-5
     //paddle_left->getWidth()
    else if (((ball->getLeft() - ball->getWidth() <= paddle_left->getLeft()-5)
    &&(ball->getTop() <=  paddle_left->getTop() + paddle_left->getHeight() + 5)
     && (ball->getTop() >= paddle_left->getTop()- ball->getHeight()/2) )
     ||
     ((ball->getLeft() + ball->getWidth() >= paddle_right->getLeft()- 5)
     &&(ball->getTop() <=  paddle_right->getTop() + paddle_right->getHeight()+ 5)
     && (ball->getTop() >= paddle_right->getTop()- ball->getHeight()/2 )))
    {
       int x_ball = -ball->getX_ball();
       int x_ball_new = ball->getLeft();
       x_ball_new += x_ball;
       ball->setLeft(x_ball_new);
       ball->setX_ball(x_ball);
       bounceNumber++;
       
       if (((ball->getTop() >= paddle_right->getHeight()/2 -40) &&
       (ball->getTop() <= paddle_right->getHeight()/2 +40)
       || ((ball->getTop() >= paddle_left->getHeight()/2 -40) &&
       (ball->getTop() <= paddle_left->getHeight()/2 +40))))
       {
           if ( Timer1->Interval >= 5)
           {
              Timer1->Interval = Timer1->Interval - 5;
              x_ball = x_ball*1.5;
              ball->setX_ball(x_ball);
           }
       }
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{
    Application->MessageBox("Welcome to the Ping-pong game!\n"
			"The left player controls by pressing the A and Z keys.\n"
			"The left player controls by pressing the up and down arrow keys.\n"
			"Have a nice game!\n",  "Ping-pong", MB_OK);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::newGameClick(TObject *Sender)
{
   newGame->Visible=false;
   newRound->Visible=false;
   scoreboard->isTLabelVisible(scoreboard->getPoints(), false);
   scoreboard->isTLabelVisible(scoreboard->getPointsForPlayer(), false);
   scoreboard->isTLabelVisible(scoreboard->getBounceTotal(), false);
   ball->setLeft(500);
   ball->setTop(300);
   ball->setVisible(true);
   scoreboard->setL_playerScore(0);
   scoreboard->setR_playerScore(0);
   bounceNumber=0;
   Timer1->Interval = 50;
   Timer1->Enabled=true;

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
   //Timer1->Interval = 50;

   //
   Timer1->Interval = 50;
   Timer1->Enabled=true;
   //Timer1->Interval = Timer1->Interval - 30;
}
//---------------------------------------------------------------------------

