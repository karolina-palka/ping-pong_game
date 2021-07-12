#include <vcl.h>
#pragma hdrstop

#include "Ball.h"

void Ball:: updateBallPosition()
{
    x_ball = getX_ball();
    int x_ball_new = getLeft();
    x_ball_new += x_ball;
    setLeft(x_ball_new);
    y_ball = getY_ball();
    int y_ball_new = getTop();
    y_ball_new += y_ball;
    setTop(y_ball_new);
    setX_ball(x_ball);
    setY_ball(y_ball);
}

bool Ball:: isCollidedWithDownWall(TShape* background)
{
    updateBallPosition();

    if (getTop() + getWidth() +5  >= background->Height)
    {
       y_ball = -y_ball;
       int y_ball_new = getTop() + y_ball;
       setTop(y_ball_new);
       setY_ball(y_ball);
    }
}
bool Ball:: isCollidedWithUpperWall(TShape* background)
{
   updateBallPosition();

   if (getTop() <= background->Top)
    {
       y_ball = -y_ball;
       int y_ball_new = getTop() + y_ball;
       setTop(y_ball_new);
       setY_ball(y_ball);
    }


}