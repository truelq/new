#include<bits/stdc++.h>

//LCA
using namespace std;

int ss[301][301];
int save[301][301];
int lowcost[5001];
int visited[5001];
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            scanf("%d",&ss[i][j]);
        }
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
    cout<<mininum<<endl;
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