/*程序6.1 Cdemo.cpp*/
#include <graphics.h>      
#include <conio.h>
#include "stdio.h"
#include <stdlib.h>

#include "function.h"
extern void drawing();

Person savep;

/* 向右转 */
void turnRight(Person *x)
{
	turnLeft(x);
	turnLeft(x);
	turnLeft(x);
	return ;
}

/* 向后转 */
void turnBack(Person *x)
{
	turnLeft(x);
	turnLeft(x);
	return ;
}

/* 判断左边是否为墙 */
int IsLeftWall(Person *x)
{
	// TODO
	return 0;
}

/* 自定义动作 */
void move(Person *x)
{
	// TODO
	return ;
}

/* 遇到墙则不走 */
void AdvStep(Person *x)
{
	if(!IsFrontWall(x))
		step(x);
}

/* 向左走一步 */
void StepLeft(Person *x)
{
	int dir = getDirection(x);
	switch (dir)
	{
	case DIR_LEFT:
		break;
	case DIR_RIGHT:
		turnBack(x);
		break;
	case DIR_UP:
		turnLeft(x);
		break;
	case DIR_DOWN:
		turnRight(x);
		break;
	default:
		return ;
	}
	AdvStep(x);
	return ;
}

/* 向右走一步 */
void StepRight(Person *x)
{
	int dir = getDirection(x);
	switch (dir)
	{
	case DIR_RIGHT:
		break;
	case DIR_LEFT:
		turnBack(x);
		break;
	case DIR_DOWN:
		turnLeft(x);
		break;
	case DIR_UP:
		turnRight(x);
		break;
	default:
		return ;
	}
	AdvStep(x);
	return ;
}

/* 向上走一步 */
void StepUp(Person *x)
{
	int dir = getDirection(x);
	switch (dir)
	{
	case DIR_RIGHT:
		turnLeft(x);
		break;
	case DIR_LEFT:
		turnRight(x);
		break;
	case DIR_DOWN:
		turnBack(x);
		break;
	case DIR_UP:
		break;
	default:
		return ;
	}
	AdvStep(x);
	return ;
}

/* 向下走一步 */
void StepDown(Person *x)
{
	int dir = getDirection(x);
	switch (dir)
	{
	case DIR_RIGHT:
		turnRight(x);
		break;
	case DIR_LEFT:
		turnLeft(x);
		break;
	case DIR_DOWN:
		break;
	case DIR_UP:
		turnBack(x);
		break;
	default:
		return ;
	}
	AdvStep(x);
	return ;
}

void saveworld()
{
	FILE * fp = NULL;
	if((fp=fopen("saveworld.dat","wb"))==NULL)
	{
		printf("error\n");
		return;
	}
	fwrite(&xiaoming, sizeof(Person), 1, fp);
	fwrite(&xiaohong, sizeof(Person), 1, fp);
	fclose(fp);
	
	return ;
}
void loadworld()
{
	FILE * fp = NULL;
	if((fp=fopen("saveworld.dat","rb"))==NULL)
	{
		printf("error\n");
		return;
	}
	fread(&xiaoming, sizeof(Person), 1, fp);
	fread(&xiaohong, sizeof(Person), 1, fp);
	fclose(fp);
	drawing();
	return ;
}

int main()
{

	initgraph(DRAWINGAREAWIDTH, DRAWINGAREAHEIGHT);  

	init();

	while(true)	
	{
		/* 获取按键 */
		int key = getch(); 
		if(key=='q') // 按键q退出
			break;
		
		if(key==KEYUP) // 向上走
			StepUp(&xiaoming);
		if(key==KEYDOWN) // 向下走
			StepDown(&xiaoming);
		if(key==KEYLEFT) // 向左走
			StepLeft(&xiaoming);
		if(key==KEYRIGHT) // 向右走
			StepRight(&xiaoming);
		if(key=='m') // 按键m自定义连贯动作
			move(&xiaoming);

		if(key=='a') // 向左走
			StepLeft(&xiaohong);
		if(key=='s') // 向下走
			StepDown(&xiaohong);
		if(key=='d') // 向右走
			StepRight(&xiaohong);
		if(key=='w') // 向上走
			StepUp(&xiaohong);
		if(key=='n') // 按键n自定义连贯动作
			move(&xiaohong);

		if(key=='S')
			saveworld();
		if(key=='L')
			loadworld();
	}

	
	closegraph(); 

	return 0;
}
