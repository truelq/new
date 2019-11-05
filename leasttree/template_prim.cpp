#include <bits/stdc++.h>
using namespace std;
// prim
int ss[5001][5001];
int lowcost[5001];
int visited[5001];
int main() {
  int n, m;
  cin >> n >> m;
  int a,b,c;
  memset(ss,0x7f,sizeof(ss));
  for (int i = 1; i <= m; ++i) {
    scanf("%d %d %d", &a, &b, &c);
    ss[a][b]=min(ss[a][b],c);
    ss[b][a]=min(ss[b][a],c);
  }
  visited[1]=1;
  for(int i=1;i<=n;++i){
    lowcost[i]=ss[1][i];
  }
  int pos=1;
  int ans=0;
  int mininum=0x7f7f7f7f;
  for(int i=1;i<=n;++i){
    mininum=0x7f7f7f7f;
    for(int j=1;j<=n;++j){
      if(!visited[j]&&mininum>lowcost[j]){
        mininum=lowcost[j];
        pos=j;
      }
    }
    if(mininum==0x7f7f7f7f){
      break;
    }
    ans+=mininum;
    visited[pos]=1;
    for(int j=1;j<=n;++j){
      if(!visited[j]&&lowcost[j]>ss[pos][j]){
        lowcost[j]=ss[pos][j];
      }
    }
  }
  cout<<ans<<endl;
  return 0;
}
