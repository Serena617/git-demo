#include"snake.h"
#include<stdio.h>
int main(){

    srand((unsigned int)time(NULL));//设置随机数种子，需要头文件。srand（stdlib.h）,time(time.h)
    init_wall();//初始化墙壁
    init_snake();//初始化蛇
    init_food();//初始化食物
    init_UI();//改变光标位置
    start_game();//开始游戏
    
    
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
        putchar('@');//蛇头
    }
    else{
        putchar('o');//蛇身体
    }}
    //画食物
    coord.X=food.X;
    coord.Y=food.Y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
    printf("X\n");
//将光标移动到不干扰游戏的位置(太大的话回回到x的下方)
    coord.X=WIDE+5;
    coord.Y=0;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
    //init_wall();
}
//开始游戏
void start_game(void){
    while(snake.body[0].X>=0&&snake.body[0].X<WIDE&&snake.body[0].Y>=0&&snake.body[0].Y<HIGH){//判断蛇头是否越界
        char ch = 'd'; // 默认向右
        int kx=1,ky=0;
        if(kbhit()){//如果有键盘输入
        ch=getch(); // 获取输入的字符
        }
            //根据输入的字符改变蛇头的坐标

            switch(ch){
                case 'w':
                   kx=0;ky=-1;
                    break;
                case 's':
                    kx=0;ky=+1;
                    break;
                case 'a':
                    kx=-1;ky=0;
                    break;
                case 'd':
                    kx=+1;ky=0;
                    break;
                default:
                    break;
            }
        
        
        //判断蛇头是否和身体相撞
        for(int i=1;i<snake.size;i++){
                if(snake.body[0].X==snake.body[i].X&&snake.body[0].Y==snake.body[i].Y)
                    return ;
            }
         //蛇头和食物的碰撞
        if(snake.body[0].X==food.X&&snake.body[0].Y==food.Y){
                snake.size++;//蛇的长度加1
                init_food();//食物消失同时产生一个新事物=再调用一次函数
                    score++;
                }
int last_X=snake.body[snake.size-1].X;
int last_Y=snake.body[snake.size-1].Y;
        //蛇移动，前一节身体给后一节身体赋值
        //更新蛇身体的位置
        for(int i=snake.size-1;i>0;i--){
            snake.body[i]=snake.body[i-1];
        }
        snake.body[0].X+=kx;
        snake.body[0].Y+=ky;
        //清屏
       // system("cls");//去除蛇尾plan1
        //plan2
COORD coord={last_X,last_Y};
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
putchar(' ');//用空格覆盖蛇尾
        init_UI();
        Sleep(250);//控制游戏速度，单位是毫秒
    }
    return;//循环已退出，游戏结束
}
void init_wall(void){
    //底部
    for(int i=0;i<WIDE;i++){
        COORD coord={i,HIGH-1};
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
        putchar('-');
    }
    //右侧
    for(int i=0;i<HIGH;i++){
        COORD coord={WIDE-1,i};
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
        putchar('|');
    }


}