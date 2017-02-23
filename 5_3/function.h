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

/* ��ǰ���﷽�� */
extern int direction;
/* ��ǰ����λ�� */
extern int positionx, positiony;
/* �յ�λ�� */
extern int endx, endy;
/* �ƶ��ٶ� */
extern int Speed;

/* ��ʼ�� 
   ��Ҫ���ͼ���ȡ����������
 */
extern void init();

/* ��������������ת */
extern void turnLeft();

/* ������������ָ�������ƶ�һ�� */
extern void step();

/* �������������ж�ǰ���Ƿ�Ϊǽ */
extern int IsFrontWall();

/* �������������ж��ұ��Ƿ�Ϊǽ */
extern int IsRightWall();

/* �ж��Ƿ��յ� */
extern int IsEnd();

/* ��������������ȡ��ǰ���� 
 * �� DIR_RIGHT 0 �� DIR_UP 1 �� DIR_LEFT 2 �� DIR_DOWN 3
 */
extern int getDirection();

/* ѡ��ͬ�ĵ�ͼ */
extern void SelectMap(int index);

#endif

