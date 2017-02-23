#ifndef _FUNCTION_H_
#define _FUNCTION_H_

/* ��ͼ�����С */
#define DRAWINGAREAWIDTH	500
#define DRAWINGAREAHEIGHT	400

/* ͼƬ��С */
#define IMGWIDTH	20
#define IMGHEIGHT	20

/* λ�ô�С */
#define POSWIDTH	((DRAWINGAREAWIDTH-100)/IMGWIDTH)
#define POSHEIGHT	(DRAWINGAREAHEIGHT/IMGHEIGHT)

/* ���﷽�� */
#define DIR_RIGHT	0
#define DIR_UP 		1
#define DIR_LEFT	2
#define DIR_DOWN	3

/* �����������Ҽ�ֵ */
#define KEYUP	72
#define KEYDOWN	80
#define KEYLEFT	75
#define KEYRIGHT 77

/* ��ʼ��ͼ */
extern int map[POSHEIGHT][POSWIDTH];

/* �յ�λ�� */
extern int endx, endy;

/* ����ṹ�� */
typedef struct 
{
	char direction;
	int positionx;
	int positiony;
	short speed;
}Person;

extern Person xiaoming;
extern Person xiaohong;

/* ��ʼ�� 
   ��Ҫ���ͼ���ȡ����������
 */
extern void init();

/* ��������������ת */
extern void turnLeft(Person *x);
/* ��������������ת */
extern void turnRight(Person *x);
/* ��������������ת */
extern void turnBack(Person *x);
/* ��������������ǰ�����ƶ�һ�� */
extern void step(Person *x);
/* �������������ж�ǰ���Ƿ�Ϊǽ */
extern int IsFrontWall(Person *x);
/* �������������ж��ұ��Ƿ�Ϊǽ */
extern int IsRightWall(Person *x);
/* �������������ж�����Ƿ�Ϊǽ */
extern int IsLeftWall(Person *x);
/* ������һ�� */
extern void StepUp(Person *x);
/* ������һ�� */
extern void StepDown(Person *x);
/* ������һ�� */
extern void StepLeft(Person *x);
/* ������һ�� */
extern void StepRight(Person *x);
/* ��������������ȡ��ǰ���� 
 * �� DIR_RIGHT 0 �� DIR_UP 1 �� DIR_LEFT 2 �� DIR_DOWN 3
 */
extern int getDirection(Person *x);
/* �ж��Ƿ��յ� */
extern int IsEnd(Person *x);
/* �Զ��嶯�� */
extern void move(Person *x);


#endif

