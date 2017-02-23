/*程序4.1 Cdemo.cpp*/
#include <graphics.h>      
#include <conio.h>
#include <stdlib.h>

#include "function.h"

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
