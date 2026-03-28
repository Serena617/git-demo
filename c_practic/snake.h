#ifndef SNAKE_H
#define SNAKE_H
//声明基本量

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<conio.h>
#include<Windows.h>
#define WIDE 100 //宽度
#define HIGH 30  //长度
//一个身体的对象
struct BODY{
    int X;
    int Y; 
};
//定义蛇对象
struct SNAKE{
    struct BODY body[WIDE*HIGH];//蛇的身体，最多占满整个屏幕，body[0]是蛇头
    int size;
}snake;//一个蛇对象
struct FOOD{
	int X;
	int Y;
	}food;//一个食物对象
int score=0;//分数

//声明函数
void init_snake(void);
void init_food(void);
void init_UI(void);
void start_game(void);
void init_wall(void);
#endif