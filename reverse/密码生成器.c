#include <stdio.h>
#include<time.h>
#include<string.h>
#include<stdlib.h>

int main(){
    int flag[12];
    for (int i = 0; i < 12;++i){
        flag[i] = 0;
    }
    int time = 3752985600;
    srand(time);
    for (int i = 0; i < 12;++i){
        for (flag[i] = rand() % 80 + i + 48; flag[i] <= 64;flag[i]+=26)
            ;
        while(flag[i]>122)
            flag[i] -= 26;
        if(flag[i]>90&&flag[i]<=96)
            flag[i] -= 43;
        printf("%d %d %c\n", i,flag[i], flag[i]);
    }
    getchar();
    getchar();
}