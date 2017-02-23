/*����6.1 Cdemo.cpp*/
#include <graphics.h>      
#include <conio.h>
#include <stdlib.h>
#include <time.h>

#include "function.h"
extern void drawing();

/* ����ת */
void turnRight(Person *x)
{
	turnLeft(x);
	turnLeft(x);
	turnLeft(x);
	return ;
}

/* ���ת */
void turnBack(Person *x)
{
	turnLeft(x);
	turnLeft(x);
	return ;
}

/* �ж�����Ƿ�Ϊǽ */
int IsLeftWall(Person *x)
{
	//TODO
	return 0;
}

/* �Զ��嶯�� */
void move(Person *x)
{
	//TODO
	return ;
}

/* ����ǽ���� */
void AdvStep(Person *x)
{
	if(!IsFrontWall(x))
		step(x);
}

/* ������һ�� */
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

/* ������һ�� */
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

/* ������һ�� */
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

/* ������һ�� */
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
		/* ��ȡ���� */
		int key = getch(); 
		if(key=='q') // ����q�˳�
			break;
		
		if(key==KEYUP) // ������
			StepUp(&xiaoming);
		if(key==KEYDOWN) // ������
			StepDown(&xiaoming);
		if(key==KEYLEFT) // ������
			StepLeft(&xiaoming);
		if(key==KEYRIGHT) // ������
			StepRight(&xiaoming);
		if(key=='m') // ����m�Զ������ᶯ��
			move(&xiaoming);
		if(key=='n') // ����һ���µ�����
			creatFriend();
		if(key=='d') // ����һ���µ�����
			removeFriend();
	}

	closegraph(); 

	return 0;
}
