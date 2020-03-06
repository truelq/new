#include <bits/stdc++.h>
#define ll long long
using namespace std;
// https://www.luogu.com.cn/problem/T113918 魔数
ll M = 2009731336725594113;
ll u[5] = {314882150829468584, 427197303358170108, 1022292690726729920,
           1698479428772363217, 2006101093849356424};
#define f(x) ((x % M)) % 2019
ll ss[1000001];
int main() {
  int n, q;
  int l, r;
  scanf("%d %d", &n, &q);
  for (int i = 1; i <= n; ++i)
    ss[i] = i;
  for (int i = 1; i <= q; ++i) {
    scanf("%d%d", &l, &r);
    ll ans = 0;
    for (int i = l; i <= r; ++i) {
      ans += ss[i];
    }
    printf("%lld\n", ans);
  }
  return 0;
}