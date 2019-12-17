#include<stdio.h>

int main(){
    int ss[2][2];
    int *p[2];
    p[0]=ss[0];
    p[1]=ss[1];
    for(int i=0;i<2;++i){
        for(int j=0;j<2;++j){
            scanf("%d",&p[i][j]);
        }
    }
    for(int i=0;i<2;++i){
        for(int j=0;j<2;++j){
            printf("%d",p[0][0]);
            printf("%d",p[1][1]);
        }
    }
}