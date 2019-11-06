#include "TXLib.h"

const float dt = 0.1;

void drawBall(float x, float y, float r, float R, float G, float B )
{
    int j = r;
    for(r; r > 0; r-- )
    {
        txSetColor(RGB(R - (r/j)*R, G - (r/j)*G, B - (r/j)*B));
        txSetFillColor(RGB(R - (r/j)*R, G - (r/j)*G, B - (r/j)*B));
        txCircle(x, y, r);
        txSetFillColor(RGB(0, 0, 0));
    }
}

void moveBall(float *x, float *y, float *Vx, float *Vy)
    {
        *x += *Vx * dt;
        *y += *Vy * dt;
        if (*y > 580 || *y < 20)
        *Vy = -*Vy;
        if (*x > 780 || *x < 20)
        *Vx = -*Vx;
    }


int main()
{
    txCreateWindow(800, 600);

    float x_1 = 300;
    float y_1 = 400;
    float r_1 = 25;

    float x_2 = 560;
    float y_2 = 200;
    float r_2 = 25;

    float x_3 = 170;
    float y_3 = 200;
    float r_3 = 25;


    float Vx_1 = 5;
    float Vy_1 = 8;

    float Vx_2 = 10;
    float Vy_2 = 3;

    float Vx_3 = 7;
    float Vy_3 = 5;

    for(; ;)
{
    txClear();
    drawBall(x_1, y_1, r_1, 255, 0, 0);
    drawBall(x_2, y_2, r_2, 255, 0, 100);
    drawBall(x_3, y_3, r_3, 0, 255, 255);
    moveBall(&x_1, &y_1, &Vx_1, &Vy_1);
    moveBall(&x_2, &y_2, &Vx_2, &Vy_2);
    moveBall(&x_3, &y_3, &Vx_3, &Vy_3);
    txSleep(dt);
}
    return 0;
}
