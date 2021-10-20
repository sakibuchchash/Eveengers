# include "iGraphics.h"

int sp = 1; //startpage constant
int gp = 0; //gamepage constant
int mp = 0; //menupage constant
int b1 = 0; //battle 1




char flareon[4][20] = {"flnrml\\fl01.bmp" , "flnrml\\fl02.bmp" , "flnrml\\fl03.bmp" , "flnrml\\fl04.bmp"};

char enemy1[4][20] = {"enemy1nrml\\f1.bmp" , "enemy1nrml\\f2.bmp" , "enemy1nrml\\f3.bmp" , "enemy1nrml\\f4.bmp"};


int eveeCordinateX = 1200;
int eveeCordinateY = 200;
int enemy1CordinateX = 100;
int enemy1CordinateY = 200;
int eveeIndex = 0;


void iDraw()
{
	iClear();
	iShowBMP(0, 0, "fire.bmp");
	iShowBMP2(eveeCordinateX, eveeCordinateY, flareon[eveeIndex], 0);
	iShowBMP2(enemy1CordinateX, enemy1CordinateY, enemy1[eveeIndex], 0);
}

void iMouseMove(int mx, int my)
{
	//place your codes here
}

void iMouse(int button, int state, int mx, int my)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) // && st==1)
	{
		/*printf("%d %d\n", mx, my);
		if(mx >= 600 && mx<=788 && my>=800 && my<=880)
		{
			st=0;	
			ST=1;
			
		}*/
		
	}
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here
	}
}

void iPassiveMouseMove(int mx, int my)
{
	//place your codes here
}

void iKeyboard(unsigned char key)
{
	if(key == 'q')
	{
		//do something with 'q'
	}
	//place your codes for other keys here
}


void iSpecialKeyboard(unsigned char key)
{
	if(key == GLUT_KEY_END)
	{
		exit(0);
	}
	//place your codes for other keys here
}

void change()
{
	eveeIndex++;
	if(eveeIndex >= 4)
	{
		eveeIndex = 0;
	}
}

int main()
{
	//place your own initialization codes here.
	iSetTimer(500, change);
	
	iInitialize(1500,1500, "Eveengers");
	return 0;
}