#include <bits/stdc++.h>
#include <cmath>
// https://www.luogu.com.cn/problem/P1991
// 无线通讯网
// 理解起来就是最小生成树,还是Kruskal
using namespace std;
// Kruskal
struct P3366 {
  int x;
  int y;
  int z;
};
bool operator<(P3366 &a, P3366 &b) { return a.z < b.z; }
P3366 ss[250001];
int sss[501][2];
int par[250001];
int sets[250001];
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
  } else if (sets[xx] == sets[yy]) {
    par[yy] = xx;
    sets[xx] += 1;
  } else {
    par[xx] = yy;
  }
  return 1;
}
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= m; ++i) {
    scanf("%d%d", &sss[i][0], &sss[i][1]);
  }
  int total = 0;
  for (int i = 1; i <= m; ++i) {
    for (int j = 1; j <= m; ++j) {
      ++total;
      ss[total].x = i;
      ss[total].y = j;
      ss[total].z = (sss[i][0] - sss[j][0]) * (sss[i][0] - sss[j][0]) +
                    (sss[i][1] - sss[j][1]) * (sss[i][1] - sss[j][1]);
    }
  }
  for (int i = 1; i <= total; ++i) {
    makeset(i, sets, par);
  }
  sort(ss + 1, ss + total + 1);
  int counts = 0;
  long long ans = 0;
  int x, y;
  for (int i = 1; i <= total && counts < (m - n); ++i) {
    if (unionset(ss[i].x, ss[i].y, sets, par)) {
      counts += 1;
      ans = ss[i].z;
    }
  }
  printf("%.2f", (double)sqrt(ans));
  return 0;
}
