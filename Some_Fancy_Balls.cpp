#include "TXLib.h"

void drawBall(float x, float y, float r, float R, float G, float B )
{
    int j = r;
    for(r; r > 0; r-- )
    {
        txSetColor(RGB (R - (r / j ) * R, G - (r / j ) * G, B - (r / j ) * B ) );
        txSetFillColor(RGB (R - (r / j ) * R, G - (r / j ) * G, B - (r / j ) * B ) );
        txCircle(x, y, r);
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
