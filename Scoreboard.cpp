#include <vcl.h>
#pragma hdrstop

#include "Scoreboard.h"

void Scoreboard:: createTLabel(TLabel *tlabel, int top)
{
      tlabel->Layout = tlCenter;
      tlabel->AutoSize = false;
      tlabel->Visible = false;
      tlabel->Align = alNone;

      tlabel->Left = 266;
      tlabel->Top = top;
      tlabel->Width = 500;
      tlabel->Height = 43;
      tlabel->Enabled = true;
      tlabel->Alignment = taCenter;
      tlabel->Name = "pointsForPlayer";
      tlabel->Caption = "point for the" ;
      tlabel->Font->Size=23;
      tlabel->Font->Name = "MS UI Gothic";
}
void Scoreboard:: isTLabelVisible(TLabel* tlabel, bool status)
{
    tlabel->Visible = status;
}

void Scoreboard:: setPointsForPlayer(char winner)
{
   isTLabelVisible(pointsForPlayer, true);
   AnsiString pointLabel = "Points for the ";
   if (winner == 'r')
   {
      pointsForPlayer->Caption = pointLabel + "right player" + " >";
   }
   else
   {
      pointsForPlayer->Caption = "< " + pointLabel + "left player";
   }
}
void Scoreboard:: setPoints()
{
   isTLabelVisible(points, true);

   AnsiString r_score_str = IntToStr(getR_playerScore());
   AnsiString l_score_str = IntToStr(getL_playerScore());
   points->Caption = l_score_str + " : " + r_score_str;
}
void Scoreboard:: setBounceTotal(int bounceNumber)
{
   isTLabelVisible(bounceTotal, true);
   AnsiString score = IntToStr(bounceNumber);
   bounceTotal->Caption = "Total bounces: " +score;
   //bounceTotal->Visible = false;
}

