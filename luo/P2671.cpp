#include <bits/stdc++.h>
// https://www.luogu.com.cn/problem/P2671
// 求和
// 模拟,使用公式变换优化
using namespace std;
struct P2671 {
  int i;
  int k;
};
int n, m;
P2671 ss[100001];
vector<P2671> sss[100001];
vector<P2671> ssd[100001];
int main() {
  cin >> n >> m;
  int temp;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &ss[i].k);
    ss[i].i = i;
  }
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &temp);
    if (i % 2)
      sss[temp].push_back(ss[i]);
    else
      ssd[temp].push_back(ss[i]);
  }
  int ans = 0;
  for (int i = 1; i <= m; ++i) {
    int tempans = 0;
    for (int j = 0; j < sss[i].size()&&sss[i].size()>1; ++j) {
      tempans += sss[i][j].k;
      tempans %= 10007;
    }
    for (int j = 0; j < sss[i].size()&&sss[i].size()>1; ++j) {
      ans += sss[i][j].i *
             (tempans + sss[i][j].k *
                            (sss[i].size() - 2 > 0 ? sss[i].size() - 2 : 0) %
                            10007) %
             10007;
      ans %= 10007;
    }
    tempans = 0;
    for (int j = 0; j < ssd[i].size()&&ssd[i].size()>1; ++j) {
      tempans += ssd[i][j].k;
      tempans %= 10007;
    }
    for (int j = 0; j < ssd[i].size()&&ssd[i].size()>1; ++j) {
      ans += ssd[i][j].i *
             (tempans + ssd[i][j].k *
                            (ssd[i].size() - 2 > 0 ? ssd[i].size() - 2 : 0) %
                            10007) %
             10007;
      ans %= 10007;
    }
  }
  cout << ans << endl;
  return 0;
}