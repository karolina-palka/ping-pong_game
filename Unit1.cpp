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

     if (ball->getLeft() - ball->getWidth()<= paddle_left->getLeft() - paddle_left->getWidth() -5)

    {
        Timer1->Enabled=false;
        ball->setVisible(false);
        winner = 'r';
        int r_score = scoreboard->getR_playerScore();
        r_score++;
        scoreboard->setR_playerScore(r_score);
        scoreboard->setPointsForPlayerVisible(winner);
        scoreboard->setPointsVisible(winner);
        scoreboard->setBounceTotalVisible(bounceNumber);
        scoreboard->setNextRoundVisible();
        //scoreboard->nextRoundClick(Form1, Timer1);
    }
    else if (ball->getLeft() + ball->getWidth()>= paddle_right->getLeft() + paddle_left->getWidth() +5)
    {
       Timer1->Enabled=false;
       ball->setVisible(false);
       winner = 'l';
       int l_score = scoreboard->getL_playerScore();
       l_score++;
       scoreboard->setL_playerScore(l_score);
       scoreboard->setPointsForPlayerVisible(winner);
       scoreboard->setPointsVisible(winner);
       scoreboard->setBounceTotalVisible(bounceNumber);
       scoreboard->setNextRoundVisible();
       //scoreboard->nextRoundClick(Form1, Timer1);
    }

    else if (((ball->getLeft() - ball->getWidth() <= paddle_left->getLeft()-5)
    &&(ball->getTop() <=  paddle_left->getTop() + paddle_left->getHeight() + 5)
     && (ball->getTop() > paddle_left->getTop()- ball->getHeight()/2) )
     ||
     ((ball->getLeft() + ball->getWidth() >= paddle_right->getLeft()+5)
     &&(ball->getTop() <=  paddle_right->getTop() + paddle_right->getHeight()+ 5)
     && (ball->getTop() > paddle_right->getTop()- ball->getHeight()/2) ))
    {
       int x_ball = -ball->getX_ball();
       int x_ball_new = ball->getLeft();
       x_ball_new += x_ball;
       ball->setLeft(x_ball_new);
       ball->setX_ball(x_ball);
       bounceNumber++;
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

void __fastcall TForm1::Button1Click(TObject *Sender)
{
   Button1->Visible=false;
   Timer1->Enabled=true;
}
//---------------------------------------------------------------------------
//void __fastcall TForm1:: nextRoundClick(TObject *Sender)
//{
   //Button1->Visible=false;
   //Scoreboard->nextRoundClick(MainMenu);
   //Timer1->Enabled=true;
//}

