#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
//实施指针个数也就最多4个暴力
long long ss[10][2];

int main() {
  int n;
  cin >> n;
  n -= 1;
  //初始化
  ss[3][0] = 1;
  int cur = 0;
  for (int i = 1; i < n; ++i) {
    for (int j = 0; j < 9; ++j) {
      if (ss[j][cur]) {
        ss[(j + 1) % 10][cur ^ 1] += ss[j][cur];
        ss[(j + 1) % 10][cur ^ 1] %= MOD;
        ss[(j + 9) % 10][cur ^ 1] += ss[j][cur];
        ss[(j + 9) % 10][cur ^ 1] %= MOD;
        ss[j][cur] = 0;
      }
    }
    ss[10][cur ^ 1] = 0;
    cur ^= 1;
  }
  long long ans = ss[0][cur] + ss[8][cur];
  ans %= MOD;
  cout << ans << endl;
}