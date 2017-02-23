/*程序2.1 function.h*/
#ifndef _FUNCTION_H_
#define _FUNCTION_H_

/* 画图区域大小 */
#define DRAWINGAREAWIDTH	500
#define DRAWINGAREAHEIGHT	400

/* 初始化 
   主要完成图像读取，界面生成
 */
extern void init();

/* 基本动作——左转 */
extern void turnLeft();

/* 基本动作——指定方向移动一步 */
extern void step();

#endif
