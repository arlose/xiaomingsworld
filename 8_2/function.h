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

/* 初始地图 */
extern int map[POSHEIGHT][POSWIDTH];

/* 当前人物方向 */
extern int direction;
/* 当前人物位置 */
extern int positionx, positiony;
/* 终点位置 */
extern int endx, endy;
/* 移动速度 */
extern int Speed;

/* 初始化 
   主要完成图像读取，界面生成
 */
extern void init();

/* 基本动作——左转 */
extern void turnLeft();

/* 基本动作——指定方向移动一步 */
extern void step();

/* 基本动作——判断前面是否为墙 */
extern int IsFrontWall();

/* 基本动作——判断右边是否为墙 */
extern int IsRightWall();

/* 判断是否到终点 */
extern int IsEnd();

/* 基本动作——获取当前方向 
 * 右 DIR_RIGHT 0 上 DIR_UP 1 左 DIR_LEFT 2 下 DIR_DOWN 3
 */
extern int getDirection();

/* 基本动作——右转 */
void turnRight();

/* 基本动作——后转 */
void turnBack();

#endif

