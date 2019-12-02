#include <bits/stdc++.h>

using namespace std;

int ss[101][101][200][3];
int search(int m, int n, int k, int t) {
  if (m < 0 || n < 0)
    return 0;
  if (m > 0 && n > 0 && m * n < k)
    return 0;
  if (t == 0) {
    if (m <= 0 || n <= 0)
      return 0;
    if (ss[m][n][k][0])
      return ss[m][n][k][0];
    int temp = 0;
    int a = search(n - 1, m, k, 0) % 9999997;
    int b = m * (search(n - 1, m, k - 1, 1) % 9999997) % 9999997;
    int c =
        ((m * (m - 1)) >> 1) * (search(n - 1, m, k - 2, 2) % 9999997) % 9999997;
    ss[m][n][k][0] = ss[n][m][k][0] = (a + b + c) % 9999997;
    // printf("%d %d %d %d\n", m, n, k, ss[m][n][k][0]);
    return ss[m][n][k][0];
  } else if (t == 1) {
    if (k == 1)
      if (m <= 0 || n <= 0)
        return 0;
      else
        return m * n;
    // if (k == 0 && m >= 0 && n >= 0)
    //  return 1;
    else if (k == 0)
      return 0;
    if (ss[m][n][k][1])
      return ss[m][n][k][1];
    ss[m][n][k][1] = (search(n - 1, m, k, 0) % 9999997 +
                      search(n - 1, m, k - 1, 1) % 9999997 * m % 9999997) %
                     9999997;
    return ss[m][n][k][1];
  } else if (t == 2) {
    if (k == 2) {
      if (m <= 0 || n <= 0)
        return 0;
      if (m * n < 2)
        return 0;
      if (n == 2) {
        return m * m;
      }
      if (m == 1) {
        return (1 + 2 * (n - 2) + ((n - 2) * (n - 3) >> 1));
      }
    }
    if (k == 1) {
      if (m <= 0 || n <= 0)
        return 0;
      return m * n;
    }
    if (k == 0) {
      if (m < 0 || n < 0)
        return 0;
      return 1;
    }
    if (ss[m][n][k][2])
      return ss[m][n][k][2];
    ss[m][n][k][2] =
        (search(n - 2, m, k, 0) +
         search(n - 2, m, k - 1, 1) % 9999997 * m % 9999997 * 2 % 9999997 +
         search(n - 2, m - 1, k - 2, 0) % 9999997 * m % 9999997 +
         search(n - 2, m, k - 2, 2) % 9999997 * m % 9999997 * (m - 1) %
             9999997) %
        9999997;
    return ss[m][n][k][2];
  }
}
int main() {
  int m, n;
  int k;
  cin >> m >> n;
  ss[1][1][0][0] = 1;
  ss[1][1][1][0] = 1;
  for (int i = 1; i <= 100; ++i) {
    ss[i][1][0][0] = 1;
    ss[1][i][0][0] = 1;
    ss[i][1][1][0] = i;
    ss[1][i][1][0] = i;
  }
  for (int i = 1; i <= 100; ++i) {
    for (int j = 1; j <= 100; ++j) {
      ss[i][j][0][0] = 1;
      ss[i][j][1][0] = i * j;
    }
  }
  int ans = 0;
  int temp;
  for (int i = 0; i <= 2 * m; ++i) {
    temp = search(m, n, i, 0);
    if (temp) {
      ans += temp;
      ans %= 9999997;
    } else
      break;
    //printf("%d\n", temp);
  }
  printf("%d\n", ans);
}