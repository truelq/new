#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll t, a, b, c;
ll m, n;
ll ss[501][501];
ll sss[501][501];
ll d[501];
ll dd[501];
ll v[501];
ll leg[501];
queue<ll> q;
ll min(ll a, ll b) {
  if (a <= b)
    return a;
  return b;
}
void floyd() {
  for (int k = 1; k <= n; ++k) {
    for (int i = 1; i <= n; ++i) {
      for (int j = i+1; j <= n; ++j) {
        sss[i][j] = sss[j][i] = min(sss[i][j], sss[i][k] + sss[k][j]);
      }
    }
  }
}
void spfa() {
  memset(d, 0x3f, sizeof(d));
  memset(dd, 0x3f, sizeof(dd));
  memset(v, 0, sizeof(v));
  d[1] = 0;
  dd[1]=0;
  v[1] = 1;
  q.push(1);
  while (q.size()) {
    int x = q.front();
    q.pop();
    v[x] = 0;
    for (int i = 1; i <= n; ++i) {
      if (ss[x][i]!=0x3f3f3f3f3f3f3f3f&&d[x] + ss[x][i] < d[i]) {
        d[i] = d[x] + ss[x][i];
        if (!v[i])
          q.push(i), v[i] = 1;
      }
      if (sss[x][i]!=0x3f3f3f3f3f3f3f3f&&d[x] + sss[x][i] * sss[x][i] < dd[i]) {
        dd[i] = d[x] + sss[x][i] * sss[x][i];
        if (!v[i])
          q.push(i), v[i] = 1;
      }
      if (ss[x][i]!=0x3f3f3f3f3f3f3f3f&&dd[x] + ss[x][i] < d[i]) {
        d[i] = dd[x] + ss[x][i];
        if (!v[i])
          q.push(i), v[i] = 1;
      }
    }
  }
}
int main() {
  scanf("%lld%lld", &n, &m);
  memset(ss, 0x3f, sizeof(ss));
  memset(sss, 0x3f, sizeof(sss));
  for (int i = 1; i <= m; ++i) {
    scanf("%lld%lld%lld%lld", &t, &a, &b, &c);
    if (t)
      sss[a][b] = sss[b][a] = min(sss[a][b], c);
    else
      ss[a][b] = ss[b][a] = min(ss[a][b], c);
  }
  for (int i = 1; i <= n; ++i) {
    //sss[i][i] = ss[i][i] = 0;
  }
  floyd();
  spfa();
  printf("%lld\n", min(dd[n], d[n]));
}