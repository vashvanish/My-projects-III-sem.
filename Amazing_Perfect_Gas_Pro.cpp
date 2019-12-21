#include "TXLib.h"
#include <ctime>

const double dt = 0.1;
const int n = 15;
const int m = 15;

struct Ball
{
    double x = 0;
    double y = 0;
    double r = 0;
    double Vx = 0;
    double Vy = 0;
    double R = 0;
    double G = 0;
    double B = 0;
};

void drawBall(Ball ball)
    {
	for (float j = ball.r; j > 0; j--)
	{
		txSetColor(RGB(ball.R - (j / ball.r)*ball.R, ball.G - (j / ball.r)*ball.G, ball.B - (j / ball.r)*ball.B));
		txSetFillColor(RGB(ball.R - (j / ball.r)*ball.R, ball.G - (j / ball.r)*ball.G, ball.B - (j / ball.r)*ball.B));
		txCircle(ball.x, ball.y, j);
		txSetFillColor(RGB(0, 0, 0));
	}
    }

void moveBall(Ball* ball)
{
	(*ball).x += (*ball).Vx * dt;
	(*ball).y += (*ball).Vy * dt;
	if ((*ball).y > 580 || (*ball).y < 20)
		(*ball).Vy = -(*ball).Vy;
	if ((*ball).x > 780 || (*ball).x < 20)
		(*ball).Vx = -(*ball).Vx;
}

void ballsCollision(Ball* ball1, Ball* ball2)
{
	if ((((*ball2).x - (*ball1).x) * ((*ball2).x - (*ball1).x) + ((*ball2).y - (*ball1).y) * ((*ball2).y - (*ball1).y)) <= (((*ball2).r + (*ball1).r) * ((*ball2).r + (*ball1).r)))
	{
		(*ball1).Vx = -(*ball1).Vx;
		(*ball1).Vy = -(*ball1).Vy;
		(*ball2).Vx = -(*ball1).Vx;
		(*ball2).Vy = -(*ball2).Vy;
	}
}

int main()
{
    srand(time(NULL));
	txCreateWindow(800, 600);
	Ball *ball = new Ball [n * m];
	for (int i = 0; i < n; i++)
    {
        for(int j = 1; j < m; j++)
        {
            ball[i * n + (j - 1)].x = (j + 1) * 30;
            ball[i * n + (j - 1)].y = (i + 1) * 30;
            ball[i * n + (j - 1)].R = 0;
            ball[i * n + (j - 1)].G = 200;
            ball[i * n + (j - 1)].B = 180;
            ball[i * n + (j - 1)].r = 5;
            ball[i * n + (j - 1)].Vx = 10;
            ball[i * n + (j - 1)].Vy = 10;
        }
    }


	for (; ;)
	{
        txBegin();
		txClear();

		for(;;)
    {
        txBegin();
        txClear();
        for(int i = 0; i < n*m; i++)
        {

            drawBall(ball[i]);
            moveBall(&ball[i]);
            txSetFillColor(RGB(0,0,0));
            for(int j = 0; j < n*m; j++)
            {
                ballsCollision(&ball[i], &ball[j]);
            }
        }

		txSleep(dt);

		txEnd();
	}
	return 0;
}

}
