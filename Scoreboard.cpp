#include <vcl.h>
#pragma hdrstop

#include "Scoreboard.h"

void Scoreboard:: createTLabel(TLabel *tlabel, int top)
{
      tlabel->Layout = tlCenter;
      tlabel->AutoSize = false;
      tlabel->Visible = false;
      tlabel->Align = alNone;

      tlabel->Left = 324;
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
void Scoreboard:: createTButton(TButton *tbutton, int top)
{
    //tbutton->Layout = tlCenter;
    //->AutoSize = false;
    tbutton->Visible = false;
    tbutton->Align = alNone;

    tbutton->Left = 324;
    tbutton->Top = top;
    tbutton->Width = 500;
    tbutton->Height = 43;
    tbutton->Enabled = true;
    //tbutton->Alignment = taCenter;
    tbutton->Name = "pointsForPlayer";
    tbutton->Caption = "point for the" ;
    tbutton->Font->Size=23;
    tbutton->Font->Name = "MS UI Gothic";
}

void Scoreboard:: setPointsForPlayerVisible(char winner, bool status)
{
   pointsForPlayer->Visible=status;
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
void Scoreboard:: isPointsVisible(char winner, bool status)
{
   points->Visible=status;
   if (winner == 'r')
   {
      AnsiString score = IntToStr(r_score);
      points->Caption = "0 : " + score;
   }
   else
   {
      AnsiString score = IntToStr(l_score);
      points->Caption =  "1 : " + score;
   }
}
void Scoreboard:: isBounceTotalVisible(int bounceNumber, bool status)
{
   bounceTotal->Visible=status;
   AnsiString score = IntToStr(bounceNumber);
   bounceTotal->Caption = "Total bounces: " +score;
}
void Scoreboard:: setNextRoundVisible(bool status)
{
   nextRound->Visible = status;
   nextRound->Font->Color = clGreen;
   nextRound->Caption = "Next round >";
}

void __fastcall Scoreboard:: nextRoundClick(TObject *Sender, TTimer* Timer1)
{
   //nextRound->Visible=false;
   //Timer1->Parent = Form1;
   Timer1->Enabled=true;

}