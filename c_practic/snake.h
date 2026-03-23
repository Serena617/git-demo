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
//初始化界面控件
void init_UI(void){
    COORD coord={0,0};//表示光标移动的位置
    //画蛇
    for(int i=0;i<snake.size;i++){
    coord.X=snake.body[i].X;
    coord.Y=snake.body[i].Y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
    if(i==0){
        printf("@");//蛇头
    }
    else{
        printf("o");//蛇身体
    }}
    //画食物
    coord.X=food.X;
    coord.Y=food.Y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
    printf("X");//食物

}
//声明函数
void init_snake(void);
void init_food(void);
void init_UI(void);
#endif