/*程序2.1 Cdemo.cpp*/
#include <graphics.h>      
#include <conio.h>
#include <stdlib.h>
#include <time.h>

#include "function.h"

/* 遇到墙则不走 */
void AdvStep()
{
	if(!IsFrontWall())
		step();
}

/* 向左走一步 */
void StepLeft()
{
	int dir = getDirection();
	switch (dir)
	{
	case DIR_LEFT:
		break;
	case DIR_RIGHT:
		turnBack();
		break;
	case DIR_UP:
		turnLeft();
		break;
	case DIR_DOWN:
		turnRight();
		break;
	default:
		return ;
	}
	AdvStep();
	return ;
}

/* 向右走一步 */
void StepRight()
{
	int dir = getDirection();
	switch (dir)
	{
	case DIR_RIGHT:
		break;
	case DIR_LEFT:
		turnBack();
		break;
	case DIR_DOWN:
		turnLeft();
		break;
	case DIR_UP:
		turnRight();
		break;
	default:
		return ;
	}
	AdvStep();
	return ;
}

/* 向上走一步 */
void StepUp()
{
	int dir = getDirection();
	switch (dir)
	{
	case DIR_RIGHT:
		turnLeft();
		break;
	case DIR_LEFT:
		turnRight();
		break;
	case DIR_DOWN:
		turnBack();
		break;
	case DIR_UP:
		break;
	default:
		return ;
	}
	AdvStep();
	return ;
}

/* 向下走一步 */
void StepDown()
{
	int dir = getDirection();
	switch (dir)
	{
	case DIR_RIGHT:
		turnRight();
		break;
	case DIR_LEFT:
		turnLeft();
		break;
	case DIR_DOWN:
		break;
	case DIR_UP:
		turnBack();
		break;
	default:
		return ;
	}
	AdvStep();
	return ;
}

/* 自定义动作 */
void move()
{
	int dir;

	srand((unsigned int)time(NULL));

	while(1){
		dir = rand()%4;
		switch(dir)
		{
			case DIR_RIGHT:
				StepRight();
				break;
			case DIR_LEFT:
				StepLeft();
				break;
			case DIR_UP:
				StepUp();
				break;
			case DIR_DOWN:
				StepDown();
				break;
			default:
				break;
		}
	}
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
	}
	
	closegraph(); 

	return 0;
}
