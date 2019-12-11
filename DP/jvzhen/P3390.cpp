#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll ss[101][101];
ll save[101][101];
ll temp[101][101];
ll tempp[101][101];
long long n, k;
int mmm = 1000000007;
void calc(ll sss[][101], ll savee[][101]) {
  memcpy(temp, sss, sizeof(ll)*101*101);
  memcpy(tempp, savee, sizeof(ll)*101*101);
  memset(sss, 0, sizeof(ll)*101*101);
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      for (int k = 1; k <= n; ++k) {
        sss[i][j] += tempp[i][k] * temp[k][j] % mmm;
        sss[i][j] %= mmm;
      }
    }
  }
}
int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j)
      scanf("%lld", &save[i][j]);
  //单位矩阵
  for (int i = 1; i <= n; ++i) {
    ss[i][i] = 1;
  }
  for (; k; k >>= 1) {
    if (k & 1) {
      calc(ss, save);
    }
    calc(save, save);
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j)
      printf("%lld ", ss[i][j]);
    cout << endl;
  }
}
