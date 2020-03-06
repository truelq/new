// 第二轮
// Floyd算法
// 2-1最短路
#include <bits/stdc++.h>
#include <time.h>
using namespace std;
int d[310][310], n, m;
int save[310][310];
int main() {
  //freopen("1\\data10.in", "r",stdin);
  //freopen("data10.out", "w",stdout);
  //clock_t start, end;
  int temp;
  //start = clock();
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      scanf("%d", &save[i][j]);
    }
  }
  memcpy(d, save, sizeof(save));
  long long ans = 0;
  for (int k = 1; k <= n; ++k) {
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
      }
    }
  }
  ans = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = i + 1; j <= n; ++j) {
      ans += d[i][j];
    }
  }
  cin >> m;
  int a, b, c;
  for (int l = 1; l <= m; ++l) {
    scanf("%d%d%d", &a, &b, &c);
    if (c < d[a][b]) {
      d[a][b] = d[b][a] = c;
      //memcpy(d, save, sizeof(save));
      for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
          for (int j = 1; j <= n; ++j) {
            temp=d[i][k] + d[k][j];
            if(temp<d[i][j])
              d[i][j]=temp;
            //d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
          }
        }
      }
      ans = 0;
      for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
          ans += d[i][j];
        }
      }
    }
    printf("%d\n", ans);
  }
  //end = clock();
  //printf("%d\n", end - start);
}