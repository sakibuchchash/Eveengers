# include "iGraphics.h"
#define SPEEDLIMIT 150

FILE *fp;

int score = 0;
int a = 0;

int Queue[500];
int start, end;
void Enqueue(int v)
{
    Queue[end++] = v;
}
int Dequeue()
{
    return Queue[start++];
}
void print()
{
    int i;
    for(i=start;i<=end;i++)
    {
        printf("%d\n", Queue[i]);
    }
    printf("\n");
}


int sp = 1; //startpage constant
int mp = 0; //menupage constant
int ins = 0; //instruction page constant
int go = 0; // gameover page constant
int congo = 0; // congratulation constant
int n = 0; // vaporeon
int b1 = 0; // battle 1
int b2 = 0; // battle 2
int b3 = 0; // battle 3
int pr = 0; // flareon's power constant
int mn = 0; // monferno's power constant
int vpr = 0; // vaporeon's power constant
int gd = 0;

int j = 0, k = 0; // life constant
int s = 0, f = 0;


char enemy1[4][20] = {"enemy1nrml\\f1.bmp" , "enemy1nrml\\f2.bmp" , "enemy1nrml\\f3.bmp" , "enemy1nrml\\f4.bmp"};
char flareon[4][20] = {"flnrml\\fl01.bmp" , "flnrml\\fl02.bmp" , "flnrml\\fl03.bmp" , "flnrml\\fl04.bmp"};
char enemy2[4][20] = {"enemy2nrml\\1.bmp" , "enemy2nrml\\2.bmp" , "enemy2nrml\\3.bmp" , "enemy2nrml\\4.bmp"};
char vaporeon[4][20] = {"vpnrml\\1.bmp" , "vpnrml\\2.bmp" , "vpnrml\\3.bmp" , "vpnrml\\4.bmp"};
char enemy3[4][20] = {"enemy3nrml\\gd01.bmp" , "enemy3nrml\\gd02.bmp" , "enemy3nrml\\gd03.bmp" , "enemy3nrml\\gd04.bmp"};

int eveeIndex = 0;
int enemy2Index = 0;
int eveeIndex2 = 0;
int vpIndex = 0;
int enemy3Index = 0;

int enemy1CordinateX = 150;
int enemy1CordinateY = 100;
int eveeCordinateX = 1300;
int eveeCordinateY = 100;
int enemy2CordinateX = 150;
int enemy2CordinateY = 100;
int vpCordinateX = 1300;
int vpCordinateY = 100;
int enemy3CordinateX = 150;
int enemy3CordinateY = 100;


int powerX = 900;
int powerY = 100;
int mnX = 330; //monferno's power coordinate
int mnY = 150; //
int vpowerX = 900;
int vpowerY = 100;
int gdX = 330;
int gdY = 150;




void startpage()
{
	iClear();
	iShowBMP(0, 0, "eveengers.bmp");
	iShowBMP2(650, 50, "button\\enter.bmp", 0);
}

void menupage()
{
	iClear();
	iShowBMP(0, 0, "menupage.bmp");
	iShowBMP2(100, 1300, "button\\b1.bmp", 0);
	iText(180, 760, "High Score", GLUT_BITMAP_TIMES_ROMAN_24);
	iShowBMP2(100, 1100, "button\\b1.bmp", 0);
	iText(170, 1160, "Enter", GLUT_BITMAP_TIMES_ROMAN_24);
	iShowBMP2(100, 900, "button\\b1.bmp", 0);
	iText(140, 960, "Instructions", GLUT_BITMAP_TIMES_ROMAN_24);
	iShowBMP2(100, 700, "button\\b1.bmp", 0);
	iText(180, 760, "Exit", GLUT_BITMAP_TIMES_ROMAN_24);
}

void instructionpage()
{
	iClear();
	iShowBMP(0, 0, "instruction.bmp");
	iShowBMP2(5, 1350, "button\\ylb1.bmp", 16777215);
}

void gameoverpage()
{
	iClear();
	iShowBMP(0, 0, "gameover.bmp");
	iShowBMP2(1400, 100, "button\\rlb2.bmp", 0);
}

void congratspage()
{
	iClear();
	iShowBMP(0, 0, "mcover.bmp");
	iShowBMP2(550, 1050, "congrats.bmp", 16777215);
	iText(560, 900, "You have got", GLUT_BITMAP_9_BY_15);
	iShowBMP2(700, 800, "charm.bmp", 0);
	if(a==0)
	{
		a =1;
		Enqueue(score);
		fp=fopen("score.txt","a");
		fprintf(fp,"%d\n",score);
		fclose(fp);
	}
}

void newlevel()
{
	n = 1;
}

void vap()
{
	iClear();
	iShowBMP(0, 0, "Vaporeon.bmp");
	iShowBMP2(1400, 100, "button\\rlb2.bmp", 0);
}

void battle2() //Level 2 flareon
{
	iClear();
	iShowBMP(0, 0, "fire.bmp");
	iShowBMP2(eveeCordinateX, eveeCordinateY, flareon[eveeIndex], 0);
	iShowBMP2(enemy2CordinateX, enemy2CordinateY, enemy2[enemy2Index], 0);
	iShowBMP2(1410, 1350, "life\\rlove.bmp", 0);
	iShowBMP2(1350, 1350, "life\\rlove.bmp", 0);
	iShowBMP2(1290, 1350, "life\\rlove.bmp", 0);
	iShowBMP2(1180, 1350, "Flareon.bmp", 0);
	iShowBMP2(10, 1350, "life\\rlove.bmp", 0);
	iShowBMP2(70, 1350, "life\\rlove.bmp", 0);
	iShowBMP2(130, 1350, "life\\rlove.bmp", 0);
	iShowBMP2(200, 1350, "monferno.bmp", 0);
	
	if(k == 1) // monferno will get hit
	{
		iShowBMP2(10, 1350, "life\\blove.bmp", 0);
	}
	else if(k == 2)
	{ 
		iShowBMP2(10, 1350, "life\\blove.bmp", 0);
		iShowBMP2(70, 1350, "life\\blove.bmp", 0);
	}
	else if(k == 3)
	{
		congo = 1;
		congratspage();
	}
	
	if(j == 1) // flareon will get hit
	{
		iShowBMP2(1410, 1350, "life\\blove.bmp", 0);
	}
	else if(j == 2)
	{
		iShowBMP2(1410, 1350, "life\\blove.bmp", 0);
		iShowBMP2(1350, 1350, "life\\blove.bmp", 0);
	}
	else if(j == 3)
	{
		go = 1;
		mp = 0;
		gameoverpage();
	}
}

void battle3() // battle 3 vaporeon
{
	iClear();
	iShowBMP(0, 0, "water.bmp");
	iShowBMP2(vpCordinateX, vpCordinateY, vaporeon[vpIndex], 0);
	iShowBMP2(enemy3CordinateX, enemy3CordinateY, enemy3[enemy3Index], 16777215);
	iShowBMP2(1410, 1350, "life\\bllove.bmp", 0);
	iShowBMP2(1350, 1350, "life\\bllove.bmp", 0);
	iShowBMP2(1290, 1350, "life\\bllove.bmp", 0);
	iShowBMP2(10, 1350, "life\\bllove.bmp", 0);
	iShowBMP2(70, 1350, "life\\bllove.bmp", 0);
	iShowBMP2(130, 1350, "life\\bllove.bmp", 0);
	if(s == 1) 
	{
		iShowBMP2(10, 1350, "life\\blove.bmp", 0);
	}
	else if(s == 2)
	{
		iShowBMP2(10, 1350, "life\\blove.bmp", 0);
		iShowBMP2(70, 1350, "life\\blove.bmp", 0);
	}
	else if(s == 3)
	{
		congo = 1;
		congratspage();
	}
	
	if(f == 1) 
	{
		iShowBMP2(1410, 1350, "life\\blove.bmp", 0);
	}
	else if(f == 2)
	{
		iShowBMP2(1410, 1350, "life\\blove.bmp", 0);
		iShowBMP2(1350, 1350, "life\\blove.bmp", 0);
	}
	else if(f == 3)
	{
		go = 1;
		mp = 0;
		gameoverpage();
	}
}


void power() // for flareon
{
	if(b2)
	{
		if(pr)
		{
			iShowBMP2(powerX, powerY, "flp1.bmp", 16777215);
		}
		else if(mn)
		{
			iShowBMP2(320, 130, "mnp1.bmp", 16777215); 
			iShowBMP2(mnX, mnY, "mnp0.bmp", 16777215);
		}
		
	}
	else if(b3)
	{
		if(vpr)
		{
			iShowBMP2(vpowerX, vpowerY, "vppower.bmp", 0);
		}
		
	}

}

void iDraw()
{
	//place your drawing codes here
	if(sp)
	{
	startpage();
	}
	else if(mp)
	{
		menupage();
	}
	else if(ins)
	{
		instructionpage();
	}
	else if(b2)
	{
		battle2();
		power();
	}
	else if(go)
	{
		gameoverpage();
	}
	else if(congo)
	{
		congratspage();
	}
	else if(n)
	{
		vap();
	}
	else if(b3)
	{
		battle3();
	}
}

void iMouseMove(int mx, int my)
{
	//place your codes here
}

void iMouse(int button, int state, int mx, int my)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		if(sp==1)
		{
			//printf("%d %d\n", mx, my);
			if(mx >= 609 && mx<= 775 && my>= 791 && my<= 819)
			{
				sp = 0;	
				mp = 1;
				ins = 0;
				b2 = 0;
				go = 0;
				n = 0;
				congo = 0;
			}
		}
		else if(mp==1)
		{
			//printf("%d %d\n", mx, my);
			if(mx >= 102 && mx <= 264 && my >= 1314 && my<= 1359)
			{
				sp = 0;	
				mp = 0;
				ins = 0;
				b2 = 1;
				go = 0;
				n = 0;
				congo = 0;
			}
			else if(mx >= 102 && mx <= 264 && my >= 1214 && my<= 1259)
			{
				sp = 0;	
				mp = 0;
				ins = 1;
				b2 = 0;
				go = 0;
				n = 0;
				congo = 0;
			}
			else if(mx >= 102 && mx <= 264 && my >= 1114 && my<= 1159)
			{
				exit(0);
			}
		}
		else if(ins==1)
		{
			//printf("%d %d\n", mx, my);
			if(mx >= 15 && mx <= 63 && my >= 1434 && my <= 1485)
			{
				sp = 0;
				mp = 1;
				ins = 0;
				b2 = 0;
				go = 0;
				n = 0;
				congo = 0;
			}
		}
		else if(go == 1)
		{
			//printf("%d %d\n", mx, my);
			if(mx >= 1291 && mx <= 1338 && my >= 808 && my <= 861)
			{
				//exit(0);
				sp = 1;
				mp = 0;
				ins = 0;
				b2 = 0;
				go = 0;
				n = 0;
				congo = 0;
			}
		}
		else if(congo == 1)
		{
			//printf("%d %d\n", mx, my);
			if(mx >= 639 && mx <= 791 && my >= 1151 && my <= 1307)
			{
				n = 1;
				sp = 0;
				mp = 0;
				ins = 0;
				b2 = 0;
				go = 0;
				congo = 0;
			}
		}
		else if(n  == 1)
		{
			if(mx >= 1291 && mx <= 1338 && my >= 808 && my <= 861)
			{
				n = 0;
				sp = 0;
				mp = 0;
				ins = 0;
				b2 = 0;
				go = 0;
				congo = 0;
				b3 = 1;
			}
		}
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
		if(key == 'l')
		{
			pr = 1;
			a = 0;
			//mn = 0;
		}
		else if(key == 'a')
		{
			mn = 1;
			//pr = 0;
			a = 0;
		}
		else if(key == 'k')
		{
			vpr = 1; //baporeon's power
		}
		else if(key == 's')
		{
			gd = 1; 
		}
		else if(key == 'p')
		{
			print();
		}
	//place your codes for other keys here
}


void iSpecialKeyboard(unsigned char key)
{
	if(key == GLUT_KEY_END)
	{
		
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

void change0()
{
	enemy2Index++;
	if(enemy2Index >= 4)
	{
		enemy2Index = 0;
	}
}

void change2() //flareon's andvaporeons mega power
{
	if(pr)
	{
		powerX-=20;
		if(powerX == 200)
		{
			pr = 0;
			k++;
			powerX = 900;
			score += 10;
		}
	}
}
void change6() // vaporeon's power
{
	if(vpr)
	{
		vpowerX-=20;
		if(vpowerX == 200)
		{
			pr = 0;
			s++;
			vpowerX = 900;
		}
	}
}

void change3() // monferno's power
{
	if(mn)
	{
		mnX+=40;
		if(mnX >= 1200)
		{
			mn = 0;
			j++;
			mnX = 330;
			score -= 5;
		}
	}
}

void change7()
{
	if(gd)
	{
		gdX+=40;
		if(gdX >= 1200)
		{
			gd = 0;
			f++;
			gdX = 330;
		}
	}
}


void change4()
{
	vpIndex++;
	if(vpIndex >= 4)
	{
		vpIndex = 0;
	}
}

void change5()
{
	enemy3Index++;
	if(enemy3Index >= 4)
	{
		enemy3Index = 0;
	}
}


int main()
{
	//place your own initialization codes here.
	iSetTimer(500, change);
	iSetTimer(500, change0);
	iSetTimer(80, change2);
	iSetTimer(500, change3);
	iSetTimer(500, change4);
	iSetTimer(500, change5);
	iSetTimer(500, change6);
	iSetTimer(500, change7);
	iInitialize(1500,1500, "Eveengers");
	return 0;
}