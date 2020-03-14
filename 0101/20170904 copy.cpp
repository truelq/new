#include <bits/stdc++.h>

using namespace std;
const int N = 1001, M = 10001;
int n, m;
int fl[N][N];
int cur = 0;
vector<int> ss[N];

int main() {
  int a, b;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; ++i) {
    scanf("%d%d", &a, &b);
    // add(a, b, 1);
    // ss[a].push_back(b);
    fl[a][b] = 1;
  }
  for (int i = 1; i <= n; ++i) {
    // add(i, i, 1);
    // ss[i].push_back(i);
    fl[i][i] = 1;
  }
  for (int k = 1; k <= n; ++k) {
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        fl[i][j] |= fl[i][k] & fl[k][j];
      }
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    int flag = 1;
    for (int j = 1; j <= n; ++j) {
      if (!fl[i][j] && !fl[j][i]) {
        flag = 0;
        break;
      }
    }
    // cout<<count<<' ';
    if (flag) {
      ans += 1;
      // cout << i << ' ';
    }
  }
  cout << ans << endl;
  return 0;
}