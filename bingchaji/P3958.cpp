#include <bits/stdc++.h>

//并查集，一般并的条件
// https://www.luogu.org/problem/P3958
using namespace std;
struct P3958 {
  unsigned long long x;
  unsigned long long y;
  unsigned long long z;
};

P3958 ss[10005];
bool operator<(P3958 &a, P3958 &b) {
  if (a.z == b.z) {
    if (a.y == b.y) {
      return a.x < b.x;
    }
    return a.y < b.y;
  }
  return a.z < b.z;
}
int sets[10005];
int par[10005];
void makeset(int x, int *sets, int *par);
int findset(int x, int *par);
void unionset(int x, int y, int *sets, int *par);

int main() {
  int t;
  int n, h, r;
  cin >> t;
  while (t--) {
    memset(ss, 0, sizeof(ss));
    cin >> n >> h >> r;
    makeset(n, sets, par);
    for (int i = 1; i <= n; ++i) {
      scanf("%d %d %d", &ss[i].x, &ss[i].y, &ss[i].z);
    }
    sort(ss + 1, ss + n + 1);
    if (ss[1].z > r || ss[n].z + r < h) {
      printf("No\n");
    } else {
      for (int i = 1; i <= n; ++i) {
      }
    }
  }
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
  if (sets[x] > sets[y]) {
    par[y] = x;
    sets[x] = 1;
    sets[y] = 0;
  } else if (sets[x] == sets[y]) {
    par[y] = x;
    sets[x] += 1;
    sets[y] = 0;
  } else {
    par[x] = y;
    sets[x] = 0;
    sets[y] = 1;
  }
}