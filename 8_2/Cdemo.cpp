/*程序2.1 Cdemo.cpp*/
#include <graphics.h>      
#include <conio.h>
#include <stdlib.h>

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

/*获取鼠标消息并根据鼠标点击位置进行相应操作*/
void GetMessage(MOUSEMSG m)
{
	//鼠标循环
	switch(m.uMsg)
	{
	case WM_LBUTTONDOWN:
	case WM_LBUTTONDBLCLK:
		if(m.x>440&&m.x<460&&m.y>60&&m.y<80)
			StepUp();
		if(m.x>420&&m.x<440&&m.y>80&&m.y<100)
			StepLeft();
		if(m.x>460&&m.x<480&&m.y>80&&m.y<100)
			StepRight();
		if(m.x>440&&m.x<460&&m.y>100&&m.y<120)
			StepDown();
		break;
	default: 
		break;
	}
	return ;
}


int main()
{
	int res;
	MOUSEMSG m;

	initgraph(DRAWINGAREAWIDTH, DRAWINGAREAHEIGHT);  

	init();

	Speed = 100;

    while(1)	
	{
		if(MouseHit())
		{
			/* 检查鼠标信息 */
			m = GetMouseMsg();
			/* 根据信息进行操作 */
			GetMessage(m);
		}
	}
	
	closegraph(); 

	return 0;
}
