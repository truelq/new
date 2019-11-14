#include <bits/stdc++.h>

// https://www.luogu.org/problem/P1111
using namespace std;
void makeset(int x, int *sets, int *par);
int findset(int x, int *par);
void unionset(int x, int y, int *sets, int *par);
int par[1001];
int sets[1001];
int main() {
  int n, m;
  while (scanf("%d", &n) && n) {
    scanf("%d", &m);
    int a, b;
    for (int i = 1; i <= n; ++i) {
      makeset(i, sets, par);
    }
    for (int i = 1; i <= m; ++i) {
      scanf("%d %d", &a, &b);
      unionset(a, b, sets, par);
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
      if (par[i] == i) {
        ++ans;
      }
    }
    cout << ans - 1 << endl;
  }
  return 0;
}
void makeset(int x, int *sets, int *par) {
  sets[x] = 1;
  par[x] = x;
}
int findset(int x, int *par) {
  int temp;
  int parx = x;
  while (parx != par[parx]) {
    parx = par[parx];
  }

  while (x != parx) { //查询优化
    temp = par[x];
    par[x] = parx;
    x = temp;
  }

  return parx;
}
void unionset(int x, int y, int *sets, int *par) {
  x = findset(x, par);
  y = findset(y, par);
  if (x == y) {
    return;
  }
  if (sets[x] > sets[y]) {
    par[y] = x;
  } else if (sets[x] == sets[y]) {
    par[y] = x;
    sets[x] += 1;
  } else {
    par[x] = y;
  }
}