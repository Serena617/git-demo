#include"snake.h"
int main(){

    srand((unsigned int)time(NULL));//设置随机数种子，需要头文件。srand（stdlib.h）,time(time.h)
    init_snake();//初始化蛇
    init_food();//初始化食物
    printf("snake:x=%d,y=%d\n",snake.body[0].X,snake.body[0].Y); 
    printf("snake:x=%d,y=%d\n",snake.body[1].X,snake.body[1].Y); 
    printf("food:x=%d,y=%d\n",food.X,food.Y);
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