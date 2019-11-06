#include "TXLib.h"

void drawBall(float x, float y, float r, float R, float G, float B)
{
	for (float j = r; j > 0; j--)
	{
		txSetColor(RGB(R - (j / r)*R, G - (j / r)*G, B - (j / r)*B));
		txSetFillColor(RGB(R - (j / r)*R, G - (j / r)*G, B - (j / r)*B));
		txCircle(x, y, j);
		txSetFillColor(RGB(0, 0, 0));
	}
}


int main()
{
    txCreateWindow(800, 600);
    drawBall(300, 400, 100, 255, 0, 0);
    drawBall(560, 200, 70, 255, 0, 100);
    drawBall(170, 200, 50, 0, 255, 255);
    return 0;
}
