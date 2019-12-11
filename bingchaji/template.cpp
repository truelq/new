#include <bits/stdc++.h>
//P1196
using namespace std;
int setsa[30001];
int para[30001];
int pre[30001];
void makeset(int x, int *sets, int *par);
int findset(int x, int *par, int *pre);
void unionset(int x, int y, int *sets, int *par, int *pre);
void makeset(int x, int *sets, int *par) {
  sets[x] = 1;
  par[x] = x;
}
int findset(int x, int *par, int *pre) {
    if(x==par[x]){
        return x;
    }
    int parx=findset(par[x],par,pre);
    pre[x]+=pre[par[x]];
    par[x]=parx;
    return parx;


}
void unionset(int x, int y, int *sets, int *par, int *pre) {
  x = findset(x, par, pre);
  y = findset(y, par, pre);
  pre[x] += sets[y];
  sets[y] += sets[x];
  par[x] = y;
}
int main() {
  int t;
  char a;
  int b, c;
  cin >> t;
  for (int i = 1; i <= 30000; ++i) {
    makeset(i, setsa, para);
  }
  while (t--) {
    //scanf(" %c %d %d", &a, &b, &c);
    cin>>a>>b>>c;
    if (a == 'M') {
      unionset(b, c, setsa, para, pre);
    } else {
      int bb = findset(b, para, pre);
      int cc = findset(c, para, pre);
      if (bb == cc) {
        printf("%d\n", abs(pre[b] - pre[c]) - 1);
      } else {
        printf("-1\n");
      }
    }
  }
  return 0;
}
