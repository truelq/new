#include<bits/stdc++.h>

//https://www.luogu.org/problem/P1111
using namespace std;
void makeset(int x,int *sets,int *par);
int findset(int x,int *par);
void unionset(int x,int y,int *sets,int *par);
struct P1111
{
    int x;
    int y;
    int t;
};
bool operator<(P1111 &a,P1111&b){
    return a.t<b.t;
}
P1111 ss[100001];
int main(){
    int n,m,p;
    cin>>n>>m;
    int par[n+1]={0};
    int sets[n+1]={0};
    int a,b;
    for(int i=0;i<=n;++i){
        makeset(i,sets,par);
    }
    for(int i=1;i<=m;++i){
        scanf("%d %d %d",&ss[i].x,&ss[i].y,&ss[i].t);
        //unionset(a,b,sets,par);
    }
    sort(ss+1,ss+m+1);
    int ans=0;
    for(int i=1;i<=m;++i){
        a=findset(ss[i].x,par);
        b=findset(ss[i].y,par);
        if(a!=b){
            ans=max(ans,ss[i].t);
            unionset(a,b,sets,par);
        }
    }
    int temp=0;
    for(int i=1;i<=n;++i){
        if(sets[i]){
            ++temp;
        }
    }
    if(temp>1){
        cout<<-1<<endl;
    }else{
        cout<<ans<<endl;
    }
    return 0;
}
void makeset(int x,int *sets,int *par){
    sets[x]=1;
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
        sets[x]=1;
        sets[y]=0;
    }else if(sets[x]==sets[y]){
        par[y]=x;
        sets[x]+=1;
        sets[y]=0;
    }else{
        par[x]=y;
        sets[x]=0;
        sets[y]=1;
    }
}