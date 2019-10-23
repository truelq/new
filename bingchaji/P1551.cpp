#include<bits/stdc++.h>
//https://www.luogu.org/problem/P1551
//并查集
using namespace std;
void makeset(int x,int *sets,int *par);
int findset(int x,int *par);
void unionset(int x,int y,int *sets,int *par);
int main(){
    int n,m,p;
    cin>>n>>m>>p;
    int par[n+1]={0};
    int sets[n+1]={0};
    int a,b;
    for(int i=0;i<=n;++i){
        makeset(i,sets,par);
    }
    for(int i=1;i<=m;++i){
        scanf("%d %d",&a,&b);
        unionset(a,b,sets,par);
    }
    for(int i=1;i<=p;++i){
        scanf("%d %d",&a,&b);
        a=findset(a,par);
        b=findset(b,par);
        if(a==b){
            printf("Yes\n");

        }else{
            printf("No\n");
        }
    }
    return 0;
}
void makeset(int x,int *sets,int *par){
    sets[x]=0;
    par[x]=x;
}
int findset(int x,int *par){
    int temp;
    int parx=x;
    while(parx!=par[parx]){
        parx=par[parx];
    }
    while(x!=parx){//查询优化
        temp=par[x];
        par[x]=parx;
        x=temp;
    }
    return parx;
}
void unionset(int x,int y,int *sets,int *par){
    x=findset(x,par);
    y=findset(y,par);
    if(sets[x]>sets[y]){
        par[y]=x;
    }else if(sets[x]==sets[y]){
        par[y]=x;
        sets[x]+=1;
    }else{
        par[x]=y;
    }
}