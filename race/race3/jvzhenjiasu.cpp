#include <bits/stdc++.h>

#define ll long long
#define MOD 1000000007
using namespace std;
int n;
ll matrix[11][11];
ll ans[11][2];
ll temp[11][11];
ll tempans[11][2];
int main() {
  cin >> n;

  matrix[1][2] = matrix[1][10] = 1;
  matrix[2][1] = matrix[2][3] = 1;
  matrix[3][2] = matrix[3][4] = 1;
  matrix[4][3] = matrix[4][5] = 1;
  matrix[5][4] = matrix[5][6] = 1;
  matrix[6][5] = 1;
  matrix[7][6] = matrix[7][8] = 1;
  matrix[8][9] = 1;
  matrix[9][8] = matrix[9][10] = 1;
  matrix[10][9] = matrix[10][1] = 1;
  ans[1][1] = 1;
  for (n-=1; n; n >>= 1) {
    if (n & 1) {
      memcpy(tempans, ans, sizeof(ll) * 11 * 2);
      memset(ans, 0, sizeof(ll) * 11 * 2);
      for (int i = 1; i <= 10; ++i) {
        for (int j = 1; j <= 1; ++j) {
          for (int k = 1; k <= 10; ++k) {
            ans[i][j] += matrix[i][k] * tempans[k][j] % MOD;
            ans[i][j] %= MOD;
          }
        }
      }
    }
    memcpy(temp, matrix, sizeof(ll) * 11 * 11);
    memset(matrix, 0, sizeof(ll) * 11 * 11);
    for (int i = 1; i <= 10; ++i) {
      for (int j = 1; j <= 10; ++j) {
        for (int k = 1; k <= 10; ++k) {
          matrix[i][j] += temp[i][k] * temp[k][j] % MOD;
          matrix[i][j] %= MOD;
        }
      }
    }
  }
  cout << ans[7][1] << endl;
  return 0;
}