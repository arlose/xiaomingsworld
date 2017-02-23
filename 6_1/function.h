#ifndef _FUNCTION_H_
#define _FUNCTION_H_

/* 画图区域大小 */
#define DRAWINGAREAWIDTH	500
#define DRAWINGAREAHEIGHT	400

/* 图片大小 */
#define IMGWIDTH	20
#define IMGHEIGHT	20

/* 位置大小 */
#define POSWIDTH	((DRAWINGAREAWIDTH-100)/IMGWIDTH)
#define POSHEIGHT	(DRAWINGAREAHEIGHT/IMGHEIGHT)

/* 人物方向 */
#define DIR_RIGHT	0
#define DIR_UP 		1
#define DIR_LEFT	2
#define DIR_DOWN	3

/* 键盘上下左右键值 */
#define KEYUP	72
#define KEYDOWN	80
#define KEYLEFT	75
#define KEYRIGHT 77

/* 初始地图 */
extern int map[POSHEIGHT][POSWIDTH];

/* 终点位置 */
extern int endx, endy;

/* 人物结构体 */
typedef struct 
{
	char direction;
	int positionx;
	int positiony;
	short speed;
}Person;

extern Person xiaoming;
extern Person xiaohong;

/* 初始化 
   主要完成图像读取，界面生成
 */
extern void init();

/* 基本动作——左转 */
extern void turnLeft(Person *x);
/* 基本动作——右转 */
extern void turnRight(Person *x);
/* 基本动作——后转 */
extern void turnBack(Person *x);
/* 基本动作——向当前方向移动一步 */
extern void step(Person *x);
/* 基本动作——判断前面是否为墙 */
extern int IsFrontWall(Person *x);
/* 基本动作——判断右边是否为墙 */
extern int IsRightWall(Person *x);
/* 基本动作——判断左边是否为墙 */
extern int IsLeftWall(Person *x);
/* 向上走一步 */
extern void StepUp(Person *x);
/* 向下走一步 */
extern void StepDown(Person *x);
/* 向左走一步 */
extern void StepLeft(Person *x);
/* 向右走一步 */
extern void StepRight(Person *x);
/* 基本动作——获取当前方向 
 * 右 DIR_RIGHT 0 上 DIR_UP 1 左 DIR_LEFT 2 下 DIR_DOWN 3
 */
extern int getDirection(Person *x);
/* 判断是否到终点 */
extern int IsEnd(Person *x);
/* 自定义动作 */
extern void move(Person *x);


#endif

