#include<bits/stdc++.h>
using namespace std;
const int inf=1<<29,N=50010,M=300010;
int head[N],ver[M],edge[M],Next[M],d[N];
int n,m,s,t,tot,maxflow;
queue<int> q;
void add(int x,int y,int z){
    ver[++tot]=y,edge[tot]=z,Next[tot]=head[x],head[x]=tot;
    ver[++tot]=x,edge[tot]=0;Next[tot]=head[y],head[y]=tot;
}
bool bfs(){//在参量网络上构造分层图
    memset(d,0,sizeof(d));
    while(q.size()) q.pop();
    q.push(s);
    d[s]=1;
    while(q.size()){
        int x=q.front();q.pop();
        for(int i=head[x];i;i=Next[i]){
            if(edge[i]&&!d[ver[i]]){
                q.push(ver[i]);
                d[ver[i]]=d[x]+1;
                if(ver[i]==t) return 1;
            }
        }
    }
    return 0;
}
int dinic(int x,int flow){//当前分层图桑增广
    if(x==t) return flow;
    int rest=flow,k;
    for(int i=head[x];i&&rest;i=Next[i]){
        if(edge[i]&&d[ver[i]]==d[x]+1){
            k=dinic(ver[i],min(rest,edge[i]));
            if(!k) d[ver[i]]=0;//剪枝,去掉増广完毕的点
            edge[i]-=k;
            edge[i^1]+=k;
            rest-=k;
        }
    }
    return flow-rest;
}
int main(){
    int n1,n2,n3;
    int m1,m2;
    cin>>n1>>n2>>n3;

    n=n1*2+n2+n3;
    s=0;t=n+1;//源点,汇点
    tot=1;
    cin>>m1;
    for(int i=1;i<=m1;++i){
        int x,y;
        scanf("%d%d",&x,&y);
        add(y,x+n2,1);
    }
    cin>>m2;
    for(int i=1;i<=m2;++i){
        int x,y;
        scanf("%d%d",&x,&y);
        add(n1+n2+x,y+n1+n2+n2,1);
    }
    for(int i=1;i<=n1;++i){
        add(i+n2,i+n1+n2,1);
    }
    for(int i=1;i<=n2;++i){
        add(s,i,1);
    }
    for(int i=1;i<=n3;++i){
        add(i+n1+n2+n2,t,1);
    }
    int flow=0;
    while(bfs()){
        while(flow=dinic(s,inf)) maxflow+=flow;
    }
    cout<<maxflow<<endl;
    return 0;
}