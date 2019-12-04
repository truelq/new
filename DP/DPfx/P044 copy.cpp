#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;

//单调栈
int main(){
    int n;
    cin>>n;

    int ans=0;
    int save[n+1][n+1];//save[进栈][出栈]
    memset(save,0,sizeof(save));
    for(int i=0;i<=n;++i){
        save[i][0]=1;
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<i;++j){
            save[i][j]=save[i-1][j]+save[i][j-1];
        }
        save[i][i]=save[i][i-1];
    }
    cout<<save[n][n]<<endl;
}