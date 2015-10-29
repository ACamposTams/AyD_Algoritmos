#include <stdio.h>
#include <graphics.h>
#include <iostream>


void horizontalLine(int, int, int, int);
void verticalLine(int, int, int, int);
void diagonalLine(int, int, int, int);
void Cube();
void RectPrism();
void TrianglePrism();
void Cone();
void ellipsePoints(int, int, int);
void midPointEllipse(int,int);

int main(int argc, char **argv)
{
	int gd = DETECT, gm = VGAMAX;

	int option = 0;

	while (option!=5)
	{
		std::cout << "Selecciona una opción" << std::endl;
		std::cout << "1. Cubo" << std::endl; 
		std::cout << "2. Prisma Rectangular" << std::endl; 
		std::cout << "3. Prisma Triangular" << std::endl;
		std::cout << "4. Cono" << std::endl;
		std::cout << "5. Salir" << std::endl;
		std::cin >> option;

		switch(option)
		{
			case 1:
			{
				initgraph(&gd, &gm, NULL);
				Cube();
			}
			break;
			case 2:
			{
				initgraph(&gd, &gm, NULL);
				RectPrism();
			}
			break;
			case 3:
			{
				initgraph(&gd, &gm, NULL);
				TrianglePrism();
			}
			break;
			case 4:
			{
				initgraph(&gd, &gm, NULL);
				Cone();
			}
			break;
			case 5:
			{

			}
			break;
			default:
			{
				std::cout << "Opcion no valida" << std::endl;
			}
			break;
		}

		getch();
		closegraph();
	}

	return 0;
}



void horizontalLine(int x0, int y0, int x1, int y1)
{
  bool goesRight = false;
  bool goesLeft = false;

  if(x0 < x1)
  {
    goesRight = true;
  }
  else if (x0 > x1)
  {
    goesLeft = true;
  }

  if (goesRight)
 {
    for (int i = x0; i<=x1; i++)
    {
      putpixel(i,y0,RED);
    }
  }
  if(goesLeft)
  {
    for (int i = x1; i>=x1; i--)
    {
      putpixel(i,y0,RED);
    }
  }
}

void verticalLine(int x0, int y0, int x1, int y1)
{
  bool goesUp = false;
  bool goesDown = false;
  if(y0 < y1)
  {
    goesUp = true;
  }
  else if (y0 > y1)
  {
    goesDown = true;
  }

  if (goesUp)
 {
    for (int i = y0; i<=y1; i++)
    {
      putpixel(x0,i,RED);
    }
  }
  if(goesDown)
  {
    for (int i = y1; i>=y0; i--)
    {
      putpixel(x0,i,RED);
    }
  }
}

void diagonalLine(int x0, int y0, int x1, int y1)
{
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
			putpixel(x, y, RED);
			i += 2;
			y = y + m;
		}
	}
	else /* Es una línea con pendiente > 1 */
	{
		m = dx/dy;
		x = x0;
		for(y = y0; y <= y1; ++y)
		{
			putpixel((int)x, y, RED);
			i += 2;
			x = x + m;
		}
	}
}

 void Cube()
 {
	//Cuadrado frente
    int x0 = 300;
    int y0 = 300;
    int x1 = 400;
    int y1 = 300;
    int x2 = 300;
    int y2 = 200;
    int x3 = 400;
    int y3 = 200;

    //Cuadrado detrás
	int x4 = x0+40;
    int y4 = y0-40;
    int x5 = x1+40;
    int y5 = y1-40;
    int x6 = x2+40;
    int y6 = y2-40;
    int x7 = x3+40;
    int y7 = y3-40;

    //Dibuja cuadrado frente
    horizontalLine(x0,y0,x1,y1);
    horizontalLine(x2,y2,x3,y3);
    verticalLine(x2,y2,x0,x0);
    verticalLine(x3,y3,x1,y1);

    //Dibuja cuadrado detrás
	horizontalLine(x4,y4,x5,y5);
    horizontalLine(x6,y6,x7,y7);
    verticalLine(x6,y6,x4,y4);
    verticalLine(x7,y7,x5,y5);

    //Dibuja lineas diagonales del cubo
	diagonalLine(x0,y0,x4,y4);
	diagonalLine(x1,y1,x5,y5);
	diagonalLine(x2,y2,x6,y6);
	diagonalLine(x3,y3,x7,y7);
 }

 void RectPrism()
 {
	//Rectángulo frente
    int x0 = 300;
    int y0 = 350;
    int x1 = 350;
    int y1 = 350;
    int x2 = 300;
    int y2 = 200;
    int x3 = 350;
    int y3 = 200;

	// Rectángulo detrás
	int x4 = x0+30;
    int y4 = y0-50;
    int x5 = x1+30;
    int y5 = y1-50;
    int x6 = x2+30;
    int y6 = y2-50;
    int x7 = x3+30;
    int y7 = y3-50;

    horizontalLine(x0,y0,x1,y1);
    horizontalLine(x2,y2,x3,y3);
    verticalLine(x2,y2,x0,y0);
    verticalLine(x3,y3,x1,y1);

	horizontalLine(x4,y4,x5,y5);
    horizontalLine(x6,y6,x7,y7);
    verticalLine(x6,y6,x4,y4);
    verticalLine(x7,y7,x5,y5);

	diagonalLine(x0,y0,x4,y4);
	diagonalLine(x1,y1,x5,y5);
	diagonalLine(x2,y2,x6,y6);
	diagonalLine(x3,y3,x7,y7);
 }

 void TrianglePrism()
 {
	 //Puntos Base
	 int x0 = 300;
	 int y0 = 300;
	 int x1 = 350;
	 int y1 = 300;
	 int x2 = 325;
	 int y2 = 343;

	 //Puntos Tapa
	 int x3 = x0;
	 int y3 = y0-100;
	 int x4 = x1;
	 int y4 = y1-100;
	 int x5 = x2;
	 int y5 = y2-100;

	 horizontalLine(x0,y0,x1,y1);
	 diagonalLine(x0,y0,x2,y2);
	 diagonalLine(x1,y1,x2,y2);

	 horizontalLine(x3,y3,x4,y4);
	 diagonalLine(x3,y3,x5,y5);
	 diagonalLine(x4,y4,x5,y5);

	 verticalLine(x3,y3,x0,y0);
	 verticalLine(x4,y4,x1,y1);
	 verticalLine(x5,y5,x2,y2);

 }

 void ellipsePoints(int x, int y, int i)
 {
 	int maxx = getmaxx()/2;
 	int maxy = getmaxy()/2;

 	putpixel(maxx+x,maxy+y,RED);

 	i+=2;

 	putpixel(maxx-x,maxy+y,RED);
 	putpixel(maxx+x,maxy-y,RED);
 	putpixel(maxx-x,maxy-y,RED);

 }

 /* Algoritmo MidPointElipse */
 void midPointEllipse(int a,int b)
 {
 	int i = 0;
 	double d2;
 	int x=0;
 	int y=b;

 	double dl=b*b-(a*a*b)+(0.25*a*a);

 	putpixel(x,y, RED);

 	while((a*a*(y-0.5))>(b*b*(x+1)))
 	{
 		if(dl<0)
 			dl+=b*b*(2*x+3);
 		else
 		{
 			dl+=b*b*(2*x+3)+a*a*(-2*y+2);
 			y--;
 		}
 		x++;

 		ellipsePoints(x, y, i);
 	}

 	d2=b*b*(x+0.5)*(x+0.5)+a*a*(y-1)*(y-1)-a*a*b*b;

 	while(y>0)
 	{
 		if(d2<0)
 		{
 			d2+=b*b*(2*x+2)+a*a*(-2*y+3);
 			x++;
 		}
 		else
 			d2+=a*a*(-2*y+3);
 		y--;

 		ellipsePoints(x, y, i);
 	}
}

void Cone()
{
	midPointEllipse(50,20);

	int x0 = (getmaxx()/2) - 50;
	int y0 = getmaxy()/2;
	int x1 = (getmaxx()/2) + 50;
	int y1 = y0;
	int x2 = getmaxx()/2;
	int y2 = y0 + 100;

	diagonalLine(x0,y0,x2,y2);
	diagonalLine(x2,y2,x1,y1);
}