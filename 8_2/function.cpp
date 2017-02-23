#include <graphics.h>      
#include <conio.h>
#include <stdlib.h>

#include "function.h"

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

/* ��ǰ���﷽�� */
int direction;
/* ��ǰ����λ�� */
int positionx, positiony;
/* �յ�λ�� */
int endx, endy;
/* �ƶ��ٶ� */
int Speed = 1;

IMAGE WallImg;
IMAGE PersonImg[4];
IMAGE BlankImg;
IMAGE EndImg;

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
			}else if(map[j][i]==2)
			{
				putimage(i*IMGWIDTH,j*IMGHEIGHT,&PersonImg[direction]);
				positionx = i;
				positiony = j;
			}
			else if(map[j][i]==3)
			{
				putimage(i*IMGWIDTH,j*IMGHEIGHT,&EndImg);
				endx = i;
				endy = j;
			}
			else
			{
				putimage(i*IMGWIDTH,j*IMGHEIGHT,&BlankImg);
			}
		}
	Sleep(Speed);
}

void init()
{
	int i, j;
	/* ��ʼ������ */
	direction = DIR_RIGHT;

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

	setbkcolor(BLUE);
	setfillcolor(BLUE);
	bar3d(440, 60, 460, 80, 3, 1);
	outtextxy(443, 63, _T("��"));
	bar3d(420, 80, 440, 100, 3, 1);
	outtextxy(423, 83, _T("��"));
	bar3d(460, 80, 480, 100, 3, 1);
	outtextxy(463, 83, _T("��"));
	bar3d(440, 100, 460, 120, 3, 1);
	outtextxy(443, 103, _T("��"));

	drawing();

	for(j=0;j<POSHEIGHT;j++)
		for(i=0;i<POSWIDTH;i++)
		{
			if(map[j][i]==3)
			{
				endx = i;
				endy = j;
				return ;
			}
		}

	return ;
	
}

/* ��������������ת */
void turnLeft()
{
	direction = direction + 1;
	direction = direction%4;
	drawing();
	return ;
}

/* ������������ָ�������ƶ�һ�� */
void step()
{
	int i = positionx;
	int j = positiony;
	
	if(map[j][i]==2)
	{
		switch(direction)
		{
		case DIR_RIGHT:
			if(i+1<POSWIDTH)
			{
				map[j][i] = 0;
				positionx = i+1;
				map[j][i+1] = 2;
			}
			break;
		case DIR_UP:
			if(j-1>=0)
			{
				map[j][i] = 0;
				positiony=j-1;
				map[j-1][i] = 2;
			}
			break;
		case DIR_LEFT:
			if(i-1>=0)
			{
				map[j][i] = 0;
				positionx = i-1;
				map[j][i-1] = 2;

			}
			break;
		case DIR_DOWN:
			if(j+1<POSHEIGHT)
			{
				map[j][i] = 0;
				positiony=j+1;
				map[j+1][i] = 2;
			}
			break;
		default:
			break;
		}
	}
	drawing();
	return ;
}

/* �������������ж�ǰ���Ƿ�Ϊǽ */
int IsFrontWall()
{
	int flag = 0; // 0 ����ǽ�� 1 ��ǽ
	int i = positionx;
	int j = positiony;
	
	if(map[j][i]==2)
	{
		switch(direction)
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
	}

	return flag;
}

/* �ж��Ƿ��յ� */
int IsEnd()
{
	if((positionx==endx)&&(positiony==endy))
		return 1;
	else
		return 0;
}

/* ��������������ȡ��ǰ���� 
 * �� DIR_RIGHT 0 �� DIR_UP 1 �� DIR_LEFT 2 �� DIR_DOWN 3
 */
int getDirection()
{
	return direction;
}

/* �������������ж��ұ��Ƿ�Ϊǽ */
int IsRightWall()
{
	int flag = 0; // 0 ����ǽ�� 1 ��ǽ
	int i = positionx;
	int j = positiony;

	if(map[j][i]==2)
	{
		switch(direction)
		{
		case DIR_RIGHT:
			if(j+1<POSHEIGHT&&map[j+1][i]==1)
			{
				flag = 1;
			}
			break;
		case DIR_UP:
			if(i+1<POSWIDTH&&map[j][i+1]==1)
			{
				flag = 1;
			}
			break;
		case DIR_LEFT:
			if(j-1>=0&&map[j-1][i]==1)
			{
				flag = 1;
			}
			break;
		case DIR_DOWN:
			if(i-1>=0&&map[j][i-1]==1)
			{
				flag = 1;
			}
			break;
		default:
			break;
		}
	}

	return flag;
}


/* ��������������ת */
void turnRight()
{
	direction = direction + 3;
	direction = direction%4;
	drawing();
	return ;
}
/* ��������������ת */
void turnBack()
{
	direction = direction + 2;
	direction = direction%4;
	drawing();
	return ;
}