#include "TXLib.h"

const double dt = 0.1;

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

void moveBall(float *x, float *y, float *Vx, float *Vy)
{
	*x += *Vx * dt;
	*y += *Vy * dt;
	if (*y > 580 || *y < 20)
		*Vy = -*Vy;
	if (*x > 780 || *x < 20)
		*Vx = -*Vx;
}
void ballsCollision(float *x_a, float *y_a, float r_a, float *Vx_a, float *Vy_a, float *x_b, float *y_b, float r_b, float *Vx_b, float *Vy_b)
{
	if (((*x_b - *x_a) * (*x_b - *x_a) + (*y_b - *y_a) * (*y_b - *y_a)) <= ((r_b + r_a) * (r_b + r_a)))
	{
		*Vx_a = -*Vx_a;
		*Vy_a = -*Vy_a;
		*Vx_b = -*Vx_b;
		*Vy_b = -*Vy_b;
	}
}

int main()
{
	txCreateWindow(800, 600);

	float x_1 = 300;
	float y_1 = 400;
	float r_1 = 35;

	float x_2 = 560;
	float y_2 = 200;
	float r_2 = 35;

	float x_3 = 170;
	float y_3 = 200;
	float r_3 = 35;


	float Vx_1 = 20;
	float Vy_1 = 18;

	float Vx_2 = 10;
	float Vy_2 = 23;

	float Vx_3 = 17;
	float Vy_3 = 5;

	for (; ;)
	{
		txClear();

		drawBall(x_1, y_1, r_1, 255, 0, 0);
		drawBall(x_2, y_2, r_2, 255, 0, 100);
		drawBall(x_3, y_3, r_3, 0, 255, 255);

		moveBall(&x_1, &y_1, &Vx_1, &Vy_1);
		moveBall(&x_2, &y_2, &Vx_2, &Vy_2);
		moveBall(&x_3, &y_3, &Vx_3, &Vy_3);

		ballsCollision(&x_1, &y_1, r_1, &Vx_1, &Vy_1, &x_2, &y_2, r_2, &Vx_2, &Vy_2);
		ballsCollision(&x_1, &y_1, r_1, &Vx_1, &Vy_1, &x_3, &y_3, r_3, &Vx_3, &Vy_3);
		ballsCollision(&x_3, &y_3, r_3, &Vx_3, &Vy_3, &x_2, &y_2, r_2, &Vx_2, &Vy_2);

		txSleep(dt);
	}
	return 0;
}
