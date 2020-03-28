#include<stdio.h>

static int g[1];
static int *p=&g[0];
static int *q=&g[0];

int foo(void){
    g[0]=1;
    *p=0;
    *p=*q;
    return g[0];
}
int main(){
    printf("%d\n",foo());
    return 0;
}