/*����2.1 Cdemo.cpp*/
#include <graphics.h>      
#include <conio.h>
#include <stdlib.h>

#include "function.h"

/* �Զ��嶯�� */
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
