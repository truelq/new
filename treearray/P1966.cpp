#include <bits/stdc++.h>

// https://www.luogu.org/problem/P1966
//离散，排序

using namespace std;
struct P1966 {
  long long a;
  long long b;
  // int x;
};
bool operator<(P1966 &a, P1966 &b) { return a.a < b.a; }
long long update(long long *save, long long i, long long k, long long n);
long long suma(long long *save, long long k);

P1966 ss[1000001];
P1966 sa[1000001];
int state[1000001];
long long save[1000001];
int main() {

  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &ss[i].a);
    ss[i].b = i;
  }
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &sa[i].a);
    sa[i].b = i;
    // ss[i].x=i;
  }
  sort(ss + 1, ss + n + 1);
  sort(sa + 1, sa + n + 1);
  for (int i = 1; i <= n; ++i) {
    state[ss[i].b] = sa[i].b;
  }
  long long ans = 0;
  for (int i = n; i; --i) {
    ans += suma(save, state[i]);
    update(save, state[i], 1, n);
    ans %= 99999997;
  }
  cout << ans << endl;
}
long long update(long long *save, long long i, long long k, long long n) {
  for (int j = i; j <= n; j += (j & -j)) {
    save[j] += k;
  }
}
long long suma(long long *save, long long k) {
  long long ans = 0;
  for (int i = k; i; i -= (i & -i)) {
    ans += save[i];
  }
  return ans;
}