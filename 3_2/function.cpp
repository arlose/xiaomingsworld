#include <graphics.h>      
#include <conio.h>
#include <stdlib.h>

#include "function.h"

/* 初始地图 */
int map[POSHEIGHT][POSWIDTH] = {
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, 
	{1, 2, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1}, 
	{1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1},
	{1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1},
	{1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1},
	{1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1},
	{1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1},
	{1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1},
	{1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1},
	{1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1},
	{1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1},
	{1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1},
	{1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1},
	{1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1},
	{1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1},
	{1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1},
	{1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1},
	{1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1},
	{1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 3},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

/* 当前人物方向 */
int direction;
/* 当前人物位置 */
int positionx, positiony;
/* 终点位置 */
int endx, endy;
/* 移动速度 */
int Speed = 1;

IMAGE WallImg;
IMAGE PersonImg[4];
IMAGE BlankImg;
IMAGE EndImg;

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
	/* 初始化方向 */
	direction = DIR_RIGHT;

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

	setfont(14, 0, _T("黑体"));
	outtextxy(410, 310, _T("操作说明"));
	outtextxy(410, 330, _T("s：走一步"));
	outtextxy(410, 350, _T("l：左转"));
	outtextxy(410, 370, _T("m：自定义移动"));

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

/* 基本动作——左转 */
void turnLeft()
{
	direction = direction + 1;
	direction = direction%4;
	drawing();
	return ;
}

/* 基本动作——指定方向移动一步 */
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

/* 基本动作——判断前面是否为墙 */
int IsFrontWall()
{
	int flag = 0; // 0 不是墙， 1 是墙
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

/* 基本动作——判断右边是否为墙 */
int IsRightWall()
{
	int flag = 0; // 0 不是墙， 1 是墙
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

/* 判断是否到终点 */
int IsEnd()
{
	if((positionx==endx)&&(positiony==endy))
		return 1;
	else
		return 0;
}