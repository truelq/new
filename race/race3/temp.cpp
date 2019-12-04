#include<bits/stdc++.h>
using namespace std;
const int MAXN=1010;
const int mod=1000000007;
int n,m;
long long k,ans;
int Rank[MAXN + 1];
int inDegree[MAXN+1];
int Ans[MAXN+1];
vector<int> Adj[MAXN+1];
bool topologicalSort()
{
    int num=0;
    queue<int> q;
    for(int i=1;i<=n;i++){
        if(inDegree[i]==0)
            q.push(i);
    }
    while(!q.empty()){
        int u=q.front();
        Rank[num+1]=u;
        q.pop();
        for(int i=0;i<Adj[u].size();i++){
            int v=Adj[u][i];
            inDegree[v]--;
            if(inDegree[v]==0)
                q.push(v);
        }
        num++;
    }
    if(num==n) return true;
    else return false;
}
int main()
{
    freopen("C:\\Users\\32125\\Documents\\vscodec\\race3\\1\\data7.in","r",stdin);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        inDegree[i]=0;
    for(int i=1;i<=n;i++){
        scanf("%d",&m);
        while(m!=0){
            Adj[i].push_back(m);
            inDegree[m]++;
            scanf("%d",&m);
        }
    }
    topologicalSort();
    for(int i=1;i<=n;i++)
        Ans[i]=0;
    Ans[1]=1;
    for(int i=1;i<=n;i++){
        int u=Rank[i];
        for(int i=0;i<Adj[u].size();i++){
            int v=Adj[u][i];
            Ans[v]+=Ans[u];
            Ans[v]%=1000000007;
        }
    }
    ans=Ans[n]*k%mod;
    cout<<ans<<endl;
    cout<<Ans[n]<<endl;
    system("pause");
    return 0;
}
