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

      createTLabel(pointsForPlayer, 40, 266, 500);
      createTLabel(points, 100, 430, 150 );
      createTLabel(bounceTotal, 160, 266, 500);

      r_score=0;
      l_score=0;

  };
  __fastcall ~Scoreboard(){};
  void isTLabelVisible(TLabel* tlabel, bool status);
  void setPoints();
  void setPointsForPlayer(char winner);
  void setBounceTotal(int bounceNumber);
  void createTLabel(TLabel *tlabel, int top, int left, int width);
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
  TLabel* getPoints()
  {
      return points;
  }
  TLabel* getPointsForPlayer()
  {
      return pointsForPlayer;
  }
  TLabel* getBounceTotal()
  {
      return bounceTotal;
  }
  void setBounceTotalLeft(int newLeft)
  {
      bounceTotal->Left = newLeft;
  }
  int getBounceTotalTop()
  {
      return bounceTotal->Top;
  }
   void setBounceTotalTop(int newTop)
  {
      bounceTotal->Top = newTop;
  }
  void setPointsForPlayerTop(int newTop)
  {
      pointsForPlayer->Top = newTop;
  }
  void setPointsForPlayerLeft(int newLeft)
  {
      pointsForPlayer->Left = newLeft;
  }
   void setPointsLeft(int newLeft)
  {
      points->Left = newLeft;
  }
    void setPointsTop(int newTop)
  {
      points->Top = newTop;
  }
  int getPointsWidth()
  {
      return points->Width;
  }
  int getPointsForPlayerWidth()
  {
      return pointsForPlayer->Width;
  }
  int getBounceTotalWidth()
  {
      return bounceTotal->Width;
  }
};
#endif
