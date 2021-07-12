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
  public:
  __fastcall Scoreboard()
  {
      pointsForPlayer = new TLabel(NULL);
      pointsForPlayer->Parent = Form1;
      points = new TLabel(NULL);
      points->Parent = Form1;
  
      createTLabel(pointsForPlayer, 40);
      createTLabel(points, 90);

  };
  void setPointsVisible(char winner);
  void setPointsForPlayerVisible(char winner);
  void createTLabel(TLabel *tlabel, int top);
};
#endif
