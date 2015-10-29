#include <graphics.h>
#include <stdio.h>
#include <math.h>
#include <iostream>

void MidPointLine(int, int, int, int);
void drawLine(int, int, int, int);

int main()
{
  int gd = DETECT, gm = VGAMAX;
  int n;
  int x1, y1, x2, y2;

  std::cout << "Ingrese el número de lados: " << std::endl;
  std::cin >> n;

  float angle = (2*3.1416)/n;
  initgraph(&gd, &gm, NULL);

  int i;
  for(i=1; i<=n; i++)
  {
    x1 = 200 + (50 * cos(angle*i));
    y1 = 200 + (50 * sin(angle*i));
    x2 = 200 + (50 * cos(angle*(i+1)));
    y2 = 200 + (50 * sin(angle*(i+1)));
    drawLine(x1, y1, x2, y2);
  }
  
  getch();
  closegraph();

  return 0;
}

void drawLine(int xi, int yi, int xf, int yf)
{
	int x0, y0, x1, y1;

	if(xi > xf || yi > yf)
	{
		x0 = xf;
		y0 = yf;
		x1 = xi;
		y1 = yi;
	}
	else
	{
		x0 = xi;
		y0 = yi;
		x1 = xf;
		y1 = yf;
	}

	int maxY, i;

	float dx, dy, m, x, y;

	i=0;

	dx=x1-x0;
	dy=y1-y0;

	maxY=getmaxy();

	if (dy <= dx) /* Es una línea con pendiente < 1 */
	{
		m = dy/dx;
		y = y0;

		for(x = x0; x <= x1; ++x)
		{
			putpixel(x, (maxY-y), RED);
			y = y + m;
		}
	}
	else /* Es una línea con pendiente > 1 */
	{
		m = dx/dy;
		x = x0;
		for(y = y0; y <= y1; ++y)
		{
			putpixel(x, maxY-y, RED);
			x = x + m;
		}
	}
 }
