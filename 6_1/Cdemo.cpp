/*����6.1 Cdemo.cpp*/
#include <graphics.h>      
#include <conio.h>
#include "stdio.h"
#include <stdlib.h>

#include "function.h"
extern void drawing();

Person savep;

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
	// TODO
	return 0;
}

/* �Զ��嶯�� */
void move(Person *x)
{
	// TODO
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

		if(key=='a') // ������
			StepLeft(&xiaohong);
		if(key=='s') // ������
			StepDown(&xiaohong);
		if(key=='d') // ������
			StepRight(&xiaohong);
		if(key=='w') // ������
			StepUp(&xiaohong);
		if(key=='n') // ����n�Զ������ᶯ��
			move(&xiaohong);

		if(key=='S')
			saveworld();
		if(key=='L')
			loadworld();
	}

	
	closegraph(); 

	return 0;
}
