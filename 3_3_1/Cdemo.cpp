/*程序2.1 Cdemo.cpp*/
#include <graphics.h>      
#include <conio.h>
#include <stdlib.h>

#include "function.h"

/* 自定义动作 */
void move()
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
	}
	
	closegraph(); 

	return 0;
}
