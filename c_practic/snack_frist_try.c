#include"snake.h"
int main(){

    srand((unsigned int)time(NULL));//设置随机数种子，需要头文件。srand（stdlib.h）,time(time.h)
    init_snake();//初始化蛇
    init_food();//初始化食物
    init_UI();//改变光标位置
}
//封装一个函数，完成蛇的初始化
void init_snake(void){
    snake.body[0].X=WIDE/2;//初始化了蛇头
    snake.body[0].Y=HIGH/2;

    snake.body[1].X=WIDE/2-1;//初始化了蛇的第一个身体
    snake.body[1].Y=HIGH/2;

    snake.size=2;//初始化了蛇的长度
    return ;
}
//封装一个函数，完成食物的初始化
void init_food(void){
    food.X=rand()%WIDE;//随机生成食物的X坐标(0~WIDE-1=取余)要种随机数种子？
    food.Y=rand()%HIGH;//随机生成食物的Y坐标,<stdlib.h>
    return ;
}
//封装一个函数，完成初始化界面控件
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
    printf("X");
//将光标移动到不干扰游戏的位置
    coord.X=0;
    coord.Y=HIGH+2;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}