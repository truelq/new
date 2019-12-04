#include<iostream>
#include<cstdio>
#include<vector>
#include<string.h>
#include<cmath>
using namespace std;
vector<int>g[10010];
int n,m,x,y,i,j,v,c[10010],l=0,low[10010],dfn[10010],f[10010],cnt=0,out0[10010],sum[10010],time_clock=0;
void tarjan(int u){
    low[u]=dfn[u]=++time_clock;
    c[++l]=u;
    for(int i=0;i<g[u].size();++i){
        v=g[u][i];
        if(!dfn[v]){
            tarjan(v);
            low[u]=min(low[u],low[v]);
        }else if(!f[v])low[u]=min(low[u],dfn[v]);
    }
    if(low[u]==dfn[u]){
        int len=l;
        cnt++;
        while(c[l]!=u)f[c[l--]]=cnt;
        f[c[l--]]=cnt;
        sum[cnt]=len-l;
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    for(i=1;i<=m;++i){
        scanf("%d%d",&x,&y);
        g[x].push_back(y);
    }
    memset(dfn,0,sizeof(dfn));
    for(i=1;i<=n;++i)if(!dfn[i])tarjan(i);
    for(i=1;i<=n;++i)
    for(j=0;j<g[i].size();++j){
        v=g[i][j];
        if(f[i]!=f[v])out0[f[i]]++;
    }
    x=0;
    for(i=1;i<=cnt;++i)
    if(!out0[i]){
        if(x>0){
            printf("0");
            return 0;
        }
        x=sum[i];
    }
    printf("%d",x);
    return 0;
}