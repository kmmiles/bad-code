#include<stdio.h>
int main(){
    int a=0,b=0,c=0,d=0;
    c=(a=10)||(b=20)&&(c=30);
    //if(a=10||b=20)
    //c=2+1/1+3;
    printf("%d %d %d %d",a,b,c,d);
}

