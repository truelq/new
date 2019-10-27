#include <bits/stdc++.h>
// https://www.luogu.org/problem/P3149

using namespace std;
int sa[100001];
int sb[100001];
long long savea[100001];
long long saveb[100001];
int update(long long sss[], long long b, long long c, long long n);
long long suma(long long sss[], long long b);
int main() {


  int n, m, q;
  int a, b, c, e, d;
  cin >> n >> m >> q;
  for (int i = 0; i < q; ++i) {
    scanf("%d", &a);
    if (a == 1) {
      scanf("%d %d", &b, &c);
      if (!sa[b]) {
        update(savea, b, 1, n);
        sa[b] = 1;
      } else {
        update(savea, b, -1, n);
        sa[b] = 0;
      }
      if (!sb[c]) {
        update(saveb, c, 1, m);
        sb[c] = 1;
      } else {
        update(saveb, c, -1, m);
        sb[c] = 0;
      }
    } else {
      scanf("%d %d %d %d", &b, &c, &d, &e);
      long long tempa = suma(savea, d) - suma(savea, b - 1);
      long long tempb = suma(saveb, e) - suma(saveb, c - 1);
      printf("%lld\n",
             tempa * (e - c + 1) + tempb * (d - b + 1) - 2 * tempa * tempb);
    }
  }
}
int update(long long sss[], long long x, long long k, long long n) {
  for (int j = x; j <= n; j += (j & -j)) {
    sss[j] += k;
  }
}
long long suma(long long sss[], long long x) {
  long long ans = 0;
  for (int i = x; i; i -= (i & -i)) {
    ans += sss[i];
  }
  return ans;
}