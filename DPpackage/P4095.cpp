#include<iostream>
#include<stdio.h>
#include<vector>
#include<string.h>
using namespace std;
//在线多重背包
int main(){
    int n;
    cin>>n;
    int a[n],b[n],c[n];
    vector<int> aa[n+1],bb[n+1];
    for(int i=0;i<n;++i){
        scanf("%d %d %d",a+i,b+i,c+i);
        for(int j=1;j<=c[i];j<<=1){
            aa[i].push_back(j*a[i]);
            bb[i].push_back(j*b[i]);
            c[i]-=j;
        }
        if(c[i]){
            aa[i].push_back(c[i]*a[i]);
            bb[i].push_back(b[i]*c[i]);
        }
    }
    int q;
    int maxs=0;
    cin>>q;
    int d[q],e[q];
    for(int i=0;i<q;++i){
        scanf("%d %d",d+i,e+i);
        maxs=max(maxs,e[i]);
    }
    int savea[n+3][maxs+2]={0};
    int saveb[n+3][maxs+2]={0};
    memset(savea,0,sizeof(savea));
    memset(saveb,0,sizeof(saveb));
    for(int i=1;i<=n;++i){
        for(int j=0;j<aa[i-1].size();++j){
            //memcpy(savea[i],savea[i-1],(maxs+2)*4);
            for(int k=0;k<maxs+2;++k)
                savea[i][k]=savea[i-1][k];
            for(int k=maxs;k>=aa[i-1][j];--k){
                savea[i][k]=max(savea[i][k],savea[i][k-aa[i-1][j]]+bb[i-1][j]);
            }
        }
    }
    cout<<savea[n][maxs]<<endl;
    for(int i=n;i;--i){
        for(int j=0;j<aa[i-1].size();++j){
            //memcpy(saveb[i],saveb[i+1],(maxs+2)*4);
            for(int k=0;k<maxs+2;++k)
                saveb[i][k]=saveb[i+1][k];
            for(int k=maxs;k>=aa[i-1][j];--k){
                saveb[i][k]=max(saveb[i][k],saveb[i][k-aa[i-1][j]]+bb[i-1][j]);
            }
        }
    }
    cout<<savea[1][maxs]<<endl;
    int temp=0;
    for(int i=0;i<q;++i){
        temp=0;
        for(int j=0;j<=e[i];++j){
            temp=max(temp,savea[d[i]][j]+saveb[d[i]+2][e[i]-j]);
        }
        cout<<temp<<endl;
    }
}