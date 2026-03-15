#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

#define WIDE     //宽度
#define HIGH 30  //长度
//一个身体的对象
struct BODY{
    int X;
    int Y; 
}；
struct snack{
    struct BODY body[WIDE*HIGH];
    int size;
}；
int main(){
    int i,j;
for(i=0;i<30;i++){
    for(j=0;j<100;j++){
        printf("*");
    }
    printf("\n");
}
return 0;
}