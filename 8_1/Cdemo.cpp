/*����2.1 Cdemo.cpp*/
#include <graphics.h>      
#include <conio.h>
#include <stdlib.h>
#include <time.h>

#include "function.h"

/* ����ǽ���� */
void AdvStep()
{
	if(!IsFrontWall())
		step();
}

/* ������һ�� */
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

/* ������һ�� */
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

/* ������һ�� */
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

/* ������һ�� */
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

/* �Զ��嶯�� */
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
		/* ��ȡ���� */
		int key = getch(); 
		if(key=='q') // ����q�˳�
			break;
		if(key=='l') // ����l����ת
			turnLeft();
		if(key=='s') // ����s��һ��
			step();
		if(key=='m') // ����m�Զ������ᶯ��
			move();
	}
	
	closegraph(); 

	return 0;
}
