#include <bits/stdc++.h>
using namespace std;
// Kruskal
struct P3366 {
  int x;
  int y;
  int z;
};
bool operator<(P3366 &a, P3366 &b) { return a.z < b.z; }
P3366 ss[200001];
int par[5001];
int sets[5001];
void makeset(int i, int *sets, int *par) {
  par[i] = i;
  sets[i] = 1;
}
int findset(int i, int *par) {
  if (par[i] == i) {
    return i;
  }
  return par[i] = findset(par[i], par);
}
int unionset(int x, int y, int *sets, int *par) {
  int xx = findset(x, par);
  int yy = findset(y, par);
  if (xx == yy) {
    return 0;
  }
  if (sets[xx] > sets[yy]) {
    par[yy] = x;
  }else if(sets[xx]==sets[yy]){
    par[yy] = xx;
    sets[xx] += 1;
  }else{
    par[xx] = yy;
  }
  return 1;
}
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= m; ++i) {
    scanf("%d %d %d", &ss[i].x, &ss[i].y, &ss[i].z);
  }
  for(int i=1;i<=n;++i){
      makeset(i,sets,par);
  }
  sort(ss + 1, ss + m + 1);
  int counts=0;
  long long ans=0;
  int x,y;
  for(int i=1;i<=m&&counts<n;++i){
      if(unionset(ss[i].x,ss[i].y,sets,par)){
          counts+=1;
          ans+=ss[i].z;
      }
  }
  cout<<ans<<endl;
  return 0;
}
