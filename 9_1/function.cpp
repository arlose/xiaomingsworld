#include <graphics.h>      
#include <conio.h>
#include <stdlib.h>

#include "function.h"

int endx, endy;

Person xiaoming;
Person * newfriend[FRIENDNUM];

/* 初始地图 */
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

/* 根据map中的数值显示绘图区域 */
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

	/* 初始化位置方向速度 */
	xiaoming.positionx = 1;
	xiaoming.positiony = 1;
	xiaoming.direction = DIR_RIGHT;
	xiaoming.speed = 100;

	endx = 19;
	endy = 18;

	for(int i=0;i<FRIENDNUM;i++)
		newfriend[i] = NULL;
	
	/* 墙 */
	loadimage(&WallImg,	"wall.bmp", IMGWIDTH, IMGHEIGHT, true);
	/* 空地 */
	loadimage(&BlankImg, "blank.bmp", IMGWIDTH, IMGHEIGHT, true);
	/* 终点 */
	loadimage(&EndImg, "end.bmp", IMGWIDTH, IMGHEIGHT, true);
	/* 人物 */
	loadimage(&PersonImg[DIR_RIGHT], "right.bmp", IMGWIDTH, IMGHEIGHT, true);
	loadimage(&PersonImg[DIR_UP],    "up.bmp",    IMGWIDTH, IMGHEIGHT, true);
	loadimage(&PersonImg[DIR_LEFT],  "left.bmp",  IMGWIDTH, IMGHEIGHT, true);
	loadimage(&PersonImg[DIR_DOWN],  "down.bmp",  IMGWIDTH, IMGHEIGHT, true);

	drawing();

	return ;
	
}

/* 基本动作——左转 */
void turnLeft(Person * x)
{
	x->direction = x->direction + 1;
	x->direction = x->direction%4;
	drawing();
	return ;
}


/* 基本动作——指定方向移动一步 */
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

/* 基本动作——判断前面是否为墙 */
int IsFrontWall(Person *x)
{
	int flag = 0; // 0 不是墙， 1 是墙
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

/* 判断是否到终点 */
int IsEnd(Person *x)
{
	if((x->positionx==endx)&&(x->positiony==endy))
		return 1;
	else
		return 0;
}

/* 基本动作——获取当前方向 
 * 右 DIR_RIGHT 0 上 DIR_UP 1 左 DIR_LEFT 2 下 DIR_DOWN 3
 */
int getDirection(Person *x)
{
	return x->direction;
}