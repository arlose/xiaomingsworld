/*����2.1 Cdemo.cpp*/
#include <graphics.h>      
#include <conio.h>
#include <stdlib.h>

#include "function.h"
extern void drawing();

int d[POSHEIGHT][POSWIDTH];
#define MAX_VALUE POSHEIGHT*POSWIDTH
/*��Χ�ĸ��� �� �� �� ��*/
int aroundx[4] = {0, 1, 0, -1};
int aroundy[4] = {-1, 0, 1, 0};

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
	int i,j,k;

	/* ��ȡ��ͼ������ֵ */
	for(j=0;j<POSHEIGHT;j++)
		for(i=0;i<POSWIDTH;i++)
		{
			if(map[j][i]==2)
				d[j][i] = 0;
			else if(map[j][i]==0)
				d[j][i] = MAX_VALUE;
			else if(map[j][i]==3)
				d[j][i] = MAX_VALUE;
			else 
				d[j][i] = -1;
		}

	int dv = 0;
	int dvold;
	do{
		dvold = dv;
		// �Ƿ���ڼ������µı�־
		int count = 0; 
		for(j=0;j<POSHEIGHT;j++)
			for(i=0;i<POSWIDTH;i++)
			{
				if(d[j][i]==dv)
				{
					/*�ж���Χ�ĸ���*/
					for(k=0;k<4;k++)
					{
						if(d[j+aroundy[k]][i+aroundx[k]]>d[j][i]+1)
						{
							d[j+aroundy[k]][i+aroundx[k]] = d[j][i]+1;
							count++;
						}
					}
				}
			}
			if(count>0)
			{
				dv++;
				drawing();
			}
	}while(dvold!=dv);


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
