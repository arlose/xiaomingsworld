/*����2.1 Cdemo.cpp*/
#include <graphics.h>      
#include <conio.h>
#include <stdlib.h>

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

/*��ȡ�����Ϣ�����������λ�ý�����Ӧ����*/
void GetMessage(MOUSEMSG m)
{
	//���ѭ��
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
			/* ��������Ϣ */
			m = GetMouseMsg();
			/* ������Ϣ���в��� */
			GetMessage(m);
		}
	}
	
	closegraph(); 

	return 0;
}
