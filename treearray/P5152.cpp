#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;
//伪三维 差分
int update(int save[][2501], int x, int y, int b, int n);
int suma(int save[][2501], int x, int y);
int save[31][2501][2501];
int main() {
  int n, m;
  int x, y, xx, yy;
  int a, b, k;
  char temp;
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    while ((temp = getchar()) != 'P' && temp != 'Q')
      ;
    if (temp == 'P') {
      scanf("%d %d %d %d %d", &x, &y, &xx, &yy, &k);
      while (scanf("%d %d", &a, &b)) {
        update(save[a], x, y, b , n);
        update(save[a], x, yy + 1, -b , n);
        update(save[a], xx + 1, y, -b , n);
        update(save[a], xx + 1, yy + 1, b, n);
      }
    } else if (temp == 'Q') {
      scanf("%d %d %d %d", &x, &y, &xx, &yy);
      for (int j = 1; j <= 30; ++j) {
        printf("%d", suma(save[i], xx, yy) + suma(save[i], x - 1, y - 1) -
                         suma(save[i], x - 1, yy) -
                         -suma(save[i], xx, y - 1) );
      }
      printf("\n");
    }
  }
}
int update(int save[][2501], int x, int y, int b, int n) {
  for (int i = x; i <= n; i += (i & -i)) {
    for (int j = y; j <= n; j += (j & -j)) {
      save[i][j] += b;
    }
  }
  return 0;
}
int suma(int save[][2501], int x, int y) {
  int ans = 0;
  for (int i = x; i; i -= (i & -i)) {
    for (int j = y; j; j -= (j & -j)) {
      ans += save[i][j];
    }
  }
  return ans;
}