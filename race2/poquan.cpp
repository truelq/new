#include<cstdio>//破圈算法
#include<cstring>
#include<algorithm>
#include<cmath>
#define MAXN 210
#define INF 0x3FFFFFFF//有意思
using namespace std;
int fa[MAXN],f[MAXN],val[MAXN],vis[MAXN],last[MAXN];
int findset(int x){
    if(fa[x]==0)
        return x;
    fa[x]=findset(fa[x]);
    return fa[x];
}
void update(int x,int y,int stop){
    if(stop==x)
        return ;
    if(f[y]!=0)
        update(y,f[y],stop);
    val[y]=val[x];
    f[y]=x;
}
int check(int x,int y,int z){
    memset(vis,0,sizeof(vis));
    int maxl=-1,maxd,k;
    int x1=x;
    while(x1!=0){
        vis[x1]=maxl;
        last[x1]=maxd;
        if(maxl<val[x1]){
            maxl=val[x1];
            maxd=x1;
        }
        x1=f[x1];
    }
    x1=y;
    maxl=0;
    while(x1!=0){
        if(vis[x1]!=0){
            if(maxl>vis[x1]){
                vis[x1]=maxl;
                last[x1]=maxd;
                k=2;
            }
            else
                k=1;
            break;
        }
        vis[x1]=maxl;
        last[x1]=maxd;
        if(maxl<val[x1]){
            maxl=val[x1];
            maxd=x1;
        }
        x1=f[x1];
    }
    if(vis[x1]>z){
        if(k==1){
            update(y,x,last[x1]);
            val[x]=z;
        }
        else{
            update(x,y,last[x1]);
            val[y]=z;
        }
    }
    return max(vis[x1],z);
}
int sum,ins,n,m,x,y,z;
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        scanf("%d%d%d",&x,&y,&z);
        int u=findset(x);
        int v=findset(y);
        if(u!=v){
            ins++;
            update(x,y,-1);
            val[y]=z;
            fa[v]=u;
            sum+=z;
        }
        else{
            int s=check(x,y,z);
            sum=sum+z-s;
        }
        if(ins<n-1)
            printf("-1\n");
        else
            printf("%d\n",sum);
    }
}