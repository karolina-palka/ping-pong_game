#ifndef ScoreboardH
#define ScoreboardH

#include <vcl.h>
#pragma hdrstop
#include "Unit1.h"

class Scoreboard
{
  TLabel *pointsForPlayer;
  TLabel *points;
  TLabel *bounceTotal;
  TButton *nextRound;
  TButton *newGame;
  int r_score, l_score;
  public:
  __fastcall Scoreboard()
  {
      pointsForPlayer = new TLabel(NULL);
      pointsForPlayer->Parent = Form1;
      points = new TLabel(NULL);
      points->Parent = Form1;
      bounceTotal = new TLabel(NULL);
      bounceTotal->Parent = Form1;

      nextRound = new TButton(this);
      nextRound->Parent = Form1;
      newGame = new TButton(this);
      newGame->Parent = Form1;

      createTLabel(pointsForPlayer, 40);
      createTLabel(points, 90);
      createTLabel(bounceTotal, 150);
      createTButton(nextRound, 200);

      r_score=0;
      l_score=0;

  };
  void isPointsVisible(char winner, bool status);
  void isPointsForPlayerVisible(char winner,  bool status);
  void isBounceTotalVisible(int bounceNumber,  bool status);
  void createTLabel(TLabel *tlabel, int top);
  void createTButton(TButton *tbutton, int top);
  void setNextRoundVisible();
  void setR_playerScore(int newRscore)
  {
      r_score= newRscore;
  }
   void setL_playerScore(int newLscore)
  {
      l_score=newLscore;
  }
  int getR_playerScore()
  {
     return r_score;
  }
  int getL_playerScore()
  {
     return l_score;
  }
  void __fastcall nextRoundClick(TObject *Sender, TTimer* Timer);
};
#endif
