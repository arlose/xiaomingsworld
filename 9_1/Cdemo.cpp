/*程序6.1 Cdemo.cpp*/
#include <graphics.h>      
#include <conio.h>
#include <stdlib.h>
#include <time.h>

#include "function.h"
extern void drawing();

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
	//TODO
	return 0;
}

/* 自定义动作 */
void move(Person *x)
{
	//TODO
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

void creatFriend()
{
	srand((unsigned int)time(NULL));
	for(int i=0;i<FRIENDNUM;i++)
	{
		if(newfriend[i]==NULL)
		{
			newfriend[i] = (Person *)malloc(sizeof(Person));
			newfriend[i]->direction = rand()%4;

			do{
				newfriend[i]->positionx = rand()%20;
				newfriend[i]->positiony = rand()%20;
			}while(map[newfriend[i]->positiony][newfriend[i]->positionx]==1);
			
			newfriend[i]->speed = 100;
			break;
		}
	}
	drawing();

	return ;
}

void removeFriend()
{
	for(int i=FRIENDNUM-1;i>=0;i--)
	{
		if(newfriend[i]!=NULL)
		{
			free(newfriend[i]);
			newfriend[i] = NULL;
			break;
		}
	}
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
		if(key=='n') // 创建一个新的朋友
			creatFriend();
		if(key=='d') // 创建一个新的朋友
			removeFriend();
	}

	closegraph(); 

	return 0;
}
