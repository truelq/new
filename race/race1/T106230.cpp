#include <bits/stdc++.h>
using namespace std;
void makeset(int x, int *sets, int *par);
int findset(int x, int *par);
void unionset(int x, int y, int *sets, int *par);
int sets[200001];
int par[200001];
int ss[200001];
int ans;
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", ss + i);
  }
  for (int i = 1; i <= n; ++i) {
    makeset(i, sets, par);
  }
  ans=0x7fffffff;
  for (int i = 1; i <= n; ++i) {
      unionset(i,ss[i],sets,par);
  }

  printf("%d\n", ans);
  return 0;
}
void makeset(int x, int *sets, int *par) {
  sets[x] = 0;
  par[x] = x;
}
int findset(int x, int *par) {
  if (x != par[x]) {
    int ll = par[x];
    par[x] = findset(par[x], par);
    sets[x] += sets[ll];
  }
  return par[x];
}
void unionset(int x, int y, int *sets, int *par) {
  int xx = findset(x, par);
  int yy = findset(y, par);
  if(xx!=yy){
      par[xx]=yy;
      sets[x]=sets[y]+1;

  }else{
      ans=min(ans,sets[x]+sets[y]+1);
  }
}