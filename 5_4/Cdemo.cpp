/*程序2.1 Cdemo.cpp*/
#include <graphics.h>      
#include <conio.h>
#include <stdlib.h>

#include "function.h"
extern void drawing();

int d[POSHEIGHT][POSWIDTH];
#define MAX_VALUE POSHEIGHT*POSWIDTH
/*周围四个点 上 右 下 左*/
int aroundx[4] = {0, 1, 0, -1};
int aroundy[4] = {-1, 0, 1, 0};

/* 向右转 */
void turnRight()
{
	turnLeft();
	turnLeft();
	turnLeft();
	return ;
}

/* 判断左边是否为墙 */
int IsLeftWall()
{
	return 0;
}

/* 自定义动作 */
void move()
{
	int i,j,k;

	/* 获取地图并赋初值 */
	for(j=0;j<POSHEIGHT;j++)
		for(i=0;i<POSWIDTH;i++)
		{
			if(map[j][i]==2)
				d[j][i] = 0;
			else if(map[j][i]==0)
				d[j][i] = MAX_VALUE;
			else if(map[j][i]==3)
				d[j][i] = MAX_VALUE;
			else 
				d[j][i] = -1;
		}

	int dv = 0;
	int dvold;
	do{
		dvold = dv;
		// 是否存在继续更新的标志
		int count = 0; 
		for(j=0;j<POSHEIGHT;j++)
			for(i=0;i<POSWIDTH;i++)
			{
				if(d[j][i]==dv)
				{
					/*判断周围四个点*/
					for(k=0;k<4;k++)
					{
						if(d[j+aroundy[k]][i+aroundx[k]]>d[j][i]+1)
						{
							d[j+aroundy[k]][i+aroundx[k]] = d[j][i]+1;
							count++;
						}
					}
				}
			}
			if(count>0)
			{
				dv++;
				drawing();
			}
	}while(dvold!=dv);


	return ;
}

/* 遇到墙则不走 */
void AdvStep()
{
	if(!IsFrontWall())
		step();
}

/* 向左走一步 */
void StepLeft()
{
	return ;
}

/* 向右走一步 */
void StepRight()
{
	return ;
}

/* 向上走一步 */
void StepUp()
{
	return ;
}

/* 向下走一步 */
void StepDown()
{
	return ;
}

int main()
{

	initgraph(DRAWINGAREAWIDTH, DRAWINGAREAHEIGHT);  

	init();

	while(1)	
	{
		/* 获取按键 */
		int key = getch(); 
		if(key=='q') // 按键q退出
			break;
		if(key=='l') // 按键l向左转
			turnLeft();
		if(key=='s') // 按键s走一步
			step();
		if(key=='m') // 按键m自定义连贯动作
			move();
		if(key==KEYUP) // 键盘↑
			StepUp();
		if(key==KEYDOWN) // 键盘↓
			StepDown();
		if(key==KEYLEFT) // 键盘←
			StepLeft();
		if(key==KEYRIGHT) // 键盘→
			StepRight();
	}
	
	closegraph(); 

	return 0;
}
