#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
using namespace std;
int main()
{
    int p;
    cin >> p;
    int ss[1000][2] = {0};
    int ma = 0;
    for (int i = 0; i < p; ++i)
    {
        cin >> ss[i][0] >> ss[i][1];
        ma = max(ma, ss[i][1]);
    }
    unsigned long long c[21][21]={0};
    for(int i=0;i<21;++i){
        c[i][0]=1;
        c[i][1]=i;
        c[i][i]=1;
    }
    for(int i=2;i<21;++i){
        for(int j=1;j<i;++j){
            c[i][j]=c[i-1][j]+c[i-1][j-1];
        }
    }

    unsigned long long save[ma + 1] = {0};
    save[0]=0;
    save[1]=1;
    save[2]=2;
    save[3]=4;
    for(int i=4;i<=ma;++i){
        unsigned long long temp=0;
        for(int j=0;j<i;++j){
            if(j==0||j==i-1){
                temp=save[j]+save[i-1-j];
                temp=temp>>1;
            }else if(j==1||j==i-2){
                temp=save[j]*save[i-1-j];
                temp=temp>>1;
                temp*=c[i-1][1];
            }else{
                temp=(save[j]>>1)*(save[i-1-j]>>1);
                temp*=c[i-1][j];
            }
            save[i]+=temp;
        }
    }
    for(int i=0;i<p;++i){
        printf("%d %llu\n",ss[i][0],save[ss[i][1]]);
    }
    return 0;
}