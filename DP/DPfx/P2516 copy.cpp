#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#define rg register
using namespace std;

const int MAXN=5e3+7;
const int mod=1e8;
int n,m;
char S[MAXN],T[MAXN];
int f[2][MAXN],g[2][MAXN];

int main()
{
//  freopen("lcs.in","r",stdin);
//  freopen("lcs.out","w",stdout);
    scanf("%s",S+1);
    n=strlen(S+1)-1;
    scanf("%s",T+1);
    m=strlen(T+1)-1;
    int cur=0;
    for(rg int i=0;i<=m;++i)
        g[cur][i]=1;
    for(rg int i=0;i<=n;++i)
    {
        cur^=1;g[cur][0]=1;
        for(rg int j=1;j<=m;++j)
        {
            g[cur][j]=0;
            f[cur][j]=max(f[cur^1][j],f[cur][j-1]);
            if(S[i]==T[j])
                f[cur][j]=max(f[cur][j],f[cur^1][j-1]+1);
            if(f[cur][j]==f[cur^1][j])
                g[cur][j]+=g[cur^1][j];
            if(f[cur][j]==f[cur][j-1])
                g[cur][j]+=g[cur][j-1];
            if(S[i]==T[j]&&f[cur][j]==f[cur^1][j-1]+1)
                g[cur][j]+=g[cur^1][j-1];
            if(S[i]!=T[j]&&f[cur][j]==f[cur^1][j-1])
                g[cur][j]-=g[cur^1][j-1];
            g[cur][j]=(g[cur][j]+mod)%mod;
        }
    }
    printf("%d\n%d",f[cur][m],g[cur][m]);
}