#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#define ll long long
#define lowbit(x) ((x) & (-x))
#define N 300010
using namespace std;

struct info {
  int p, id;
} A[N];
int n, m, qn, mx, d[N], a[N << 1], q[N][2];
vector<info> t[N];
vector<ll> v[N], lst;
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-')
      f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
void add(int x, int y) {
  for (; x <= mx; x += lowbit(x))
    a[x] += y;
}
int Q(int x) {
  int r = 0;
  for (; x; x -= lowbit(x))
    r += a[x];
  return r;
}
int Find(int R) {
  int tmp = 0;
  for (int l = 0, r = mx; l <= r;) {
    int mid = (l + r) >> 1;
    if (Q(mid) >= R)
      tmp = mid, r = mid - 1;
    else
      l = mid + 1;
  }
  return tmp;
}
void Init() {
  n = read(), m = read(), qn = read(), mx = max(n, m) + qn;
  for (int i = 1; i <= qn; ++i) {
    q[i][0] = read(), q[i][1] = read();
    if (q[i][1] != m)
      t[q[i][0]].push_back((info){q[i][1], i});
  }
  for (int i = 1; i <= mx; ++i)
    add(i, 1);
  for (int i = 1; i <= n; ++i) {
    for (info x : t[i])
      add(d[x.id] = Find(x.p), -1);
    for (info x : t[i])
      add(d[x.id], 1);
  }
}
void solve() {
  ll Ans;
  for (int i = 1; i <= qn; ++i) {
    int x = Find(q[i][0]);
    Ans = (x <= n) ? (ll)x * m : lst[x - n - 1];
    add(x, -1);
    if (q[i][1] != m) {
      v[q[i][0]].push_back(Ans);
      Ans = (d[i] < m) ? (q[i][0] - 1) * 1ll * m + d[i] : v[q[i][0]][d[i] - m];
    }
    lst.push_back(Ans);
    printf("%lld\n", Ans);
  }
}
int main() {
  Init();
  solve();
}
