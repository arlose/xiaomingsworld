/*����4.1 Cdemo.cpp*/
#include <graphics.h>      
#include <conio.h>
#include <stdlib.h>

#include "function.h"

/* ����ת */
void turnRight()
{
	turnLeft();
	turnLeft();
	turnLeft();
	return ;
}

/* �ж�����Ƿ�Ϊǽ */
int IsLeftWall()
{
	return 0;
}

/* �Զ��嶯�� */
void move()
{
	return ;
}

/* ����ǽ���� */
void AdvStep()
{
	if(!IsFrontWall())
		step();
}

/* ������һ�� */
void StepLeft()
{
	return ;
}

/* ������һ�� */
void StepRight()
{
	return ;
}

/* ������һ�� */
void StepUp()
{
	return ;
}

/* ������һ�� */
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
		if(key==KEYUP) // ���̡�
			StepUp();
		if(key==KEYDOWN) // ���̡�
			StepDown();
		if(key==KEYLEFT) // ���̡�
			StepLeft();
		if(key==KEYRIGHT) // ���̡�
			StepRight();
	}
	
	closegraph(); 

	return 0;
}
