#include <bits/stdc++.h>

int ss[101][101][201];
using namespace std;
int main() {
  int n, m, i, j, k, t, ans = 0;
  scanf("%d %d", &n, &m);
  if (n < m) {
    t = n;
    n = m;
    m = t;
  }
  ss[1][m][0] = 1;
  ss[1][m - 1][1] = m;
  if (m >= 2)
    ss[1][m - 2][2] = m * (m - 1) / 2;
  for (i = 2; i <= n; i++) {
    for (j = 0; j <= m; j++)
      for (k = 0; k <= m - j; k++) {
        ss[i][j][k] += ss[i - 1][j][k];
        ss[i][j][k] %= 9999997;
        if (j <= m - 1 && k >= 1) {
          ss[i][j][k] += ss[i - 1][j + 1][k - 1] * (j + 1);
          ss[i][j][k] %= 9999997;
        }
        if (k <= m - 1 && j + k + 1 <= m) {
          ss[i][j][k] += ss[i - 1][j][k + 1] * (k + 1);
          ss[i][j][k] %= 9999997;
        }
        if (j <= m - 2 && k >= 2 && m >= 2) {
          if ((j + 1) % 2 == 0)
            ss[i][j][k] +=
                ((ss[i - 1][j + 2][k - 2] * (j + 2)) % 9999997) * (j + 1) / 2;
          if ((j + 1) % 2 == 1)
            ss[i][j][k] +=
                ((ss[i - 1][j + 2][k - 2] * (j + 1)) % 9999997) * (j + 2) / 2;
          ss[i][j][k] %= 9999997;
        }
        if (j <= m - 1 && m >= 2 && j + k + 1 <= m) {
          ss[i][j][k] += ((ss[i - 1][j + 1][k] * (j + 1)) % 9999997) * k;
          ss[i][j][k] %= 9999997;
        }
        if (k <= m - 2 && m >= 2 && j + k + 2 <= m) {
          if ((k + 1) % 2 == 0)
            ss[i][j][k] +=
                ((ss[i - 1][j][k + 2] * (k + 2)) % 9999997) * (k + 1) / 2;
          if ((k + 1) % 2 == 1)
            ss[i][j][k] +=
                ((ss[i - 1][j][k + 2] * (k + 1)) % 9999997) * (k + 2) / 2;
          ss[i][j][k] %= 9999997;
        }
      }
  }
  for (j = 0; j <= m; j++)
    for (k = 0; k <= m - j; k++) {
      ans += ss[n][j][k];
      ans = ans % 9999997;
    }
  printf("%d", ans);
  return 0;
}