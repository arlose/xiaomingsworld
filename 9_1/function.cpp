#include <graphics.h>      
#include <conio.h>
#include <stdlib.h>

#include "function.h"

int endx, endy;

Person xiaoming;
Person * newfriend[FRIENDNUM];

/* ��ʼ��ͼ */
int map[POSHEIGHT][POSWIDTH] = {
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, 
	{1, 2, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 1}, 
	{1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1},
	{1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 1},
	{1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1},
	{1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1},
	{1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1},
	{1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1},
	{1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 1},
	{1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1},
	{1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 1},
	{1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1},
	{1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1},
	{1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1},
	{1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1},
	{1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1},
	{1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1},
	{1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1},
	{1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 3},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

IMAGE WallImg;
IMAGE PersonImg[4];
IMAGE BlankImg;
IMAGE EndImg;

void drawPerson(Person *x)
{
	putimage(x->positionx*IMGWIDTH,x->positiony*IMGHEIGHT,&PersonImg[x->direction]);
	Sleep(x->speed);
	return ;
}

/* ����map�е���ֵ��ʾ��ͼ���� */
void drawing()
{
	int i, j;
	for(j=0;j<POSHEIGHT;j++)
		for(i=0;i<POSWIDTH;i++)
		{
			if(map[j][i]==1)
			{
				putimage(i*IMGWIDTH,j*IMGHEIGHT,&WallImg);
			}
			else
			{
				putimage(i*IMGWIDTH,j*IMGHEIGHT,&BlankImg);
			}
		}
	putimage(endx*IMGWIDTH,endy*IMGHEIGHT,&EndImg);

	drawPerson(&xiaoming);
	for(i=0;i<FRIENDNUM;i++)
	{
		if(newfriend[i]!=NULL)
		{
			drawPerson(newfriend[i]);
		}
	}
}

void init()
{

	/* ��ʼ��λ�÷����ٶ� */
	xiaoming.positionx = 1;
	xiaoming.positiony = 1;
	xiaoming.direction = DIR_RIGHT;
	xiaoming.speed = 100;

	endx = 19;
	endy = 18;

	for(int i=0;i<FRIENDNUM;i++)
		newfriend[i] = NULL;
	
	/* ǽ */
	loadimage(&WallImg,	"wall.bmp", IMGWIDTH, IMGHEIGHT, true);
	/* �յ� */
	loadimage(&BlankImg, "blank.bmp", IMGWIDTH, IMGHEIGHT, true);
	/* �յ� */
	loadimage(&EndImg, "end.bmp", IMGWIDTH, IMGHEIGHT, true);
	/* ���� */
	loadimage(&PersonImg[DIR_RIGHT], "right.bmp", IMGWIDTH, IMGHEIGHT, true);
	loadimage(&PersonImg[DIR_UP],    "up.bmp",    IMGWIDTH, IMGHEIGHT, true);
	loadimage(&PersonImg[DIR_LEFT],  "left.bmp",  IMGWIDTH, IMGHEIGHT, true);
	loadimage(&PersonImg[DIR_DOWN],  "down.bmp",  IMGWIDTH, IMGHEIGHT, true);

	drawing();

	return ;
	
}

/* ��������������ת */
void turnLeft(Person * x)
{
	x->direction = x->direction + 1;
	x->direction = x->direction%4;
	drawing();
	return ;
}


/* ������������ָ�������ƶ�һ�� */
void step(Person * x)
{
	int i = x->positionx;
	int j = x->positiony;
	
	switch(x->direction)
	{
	case DIR_RIGHT:
		if(i+1<POSWIDTH)
		{
			map[j][i] = 0;
			x->positionx = i+1;
		}
		break;
	case DIR_UP:
		if(j-1>=0)
		{
			map[j][i] = 0;
			x->positiony=j-1;
		}
		break;
	case DIR_LEFT:
		if(i-1>=0)
		{
			map[j][i] = 0;
			x->positionx = i-1;
		}
		break;
	case DIR_DOWN:
		if(j+1<POSHEIGHT)
		{
			map[j][i] = 0;
			x->positiony=j+1;
		}
		break;
	default:
		break;
	}

	drawing();
	return ;
}

/* �������������ж�ǰ���Ƿ�Ϊǽ */
int IsFrontWall(Person *x)
{
	int flag = 0; // 0 ����ǽ�� 1 ��ǽ
	int i = x->positionx;
	int j = x->positiony;
	
	switch(x->direction)
	{
	case DIR_RIGHT:
		if(i+1<POSWIDTH&&map[j][i+1]==1)
		{
			flag = 1;
		}
		break;
	case DIR_UP:
		if(j-1>=0&&map[j-1][i]==1)
		{
			flag = 1;
		}
		break;
	case DIR_LEFT:
		if(i-1>=0&&map[j][i-1]==1)
		{
			flag = 1;
		}
		break;
	case DIR_DOWN:
		if(j+1<POSHEIGHT&&map[j+1][i]==1)
		{
			flag = 1;
		}
		break;
	default:
		break;
	}

	return flag;
}

/* �ж��Ƿ��յ� */
int IsEnd(Person *x)
{
	if((x->positionx==endx)&&(x->positiony==endy))
		return 1;
	else
		return 0;
}

/* ��������������ȡ��ǰ���� 
 * �� DIR_RIGHT 0 �� DIR_UP 1 �� DIR_LEFT 2 �� DIR_DOWN 3
 */
int getDirection(Person *x)
{
	return x->direction;
}