#include <bits/stdc++.h>

using namespace std;
const int N = 1001, M = 10001;
int n, m;
int head[N], ver[M], edge[M], Next[M], d[N];
int state[N][N];
int fl[N][N];
int tot;
int cur = 0;
vector<int> ss[N];
void add(int a, int b, int z) {
  ver[++tot] = b;
  edge[tot] = z;
  Next[tot] = head[a];
  head[a] = tot;
}

void dfs(int t) {
  d[t] = 1;
  state[cur][t] = 1;
  state[t][cur] = 1;
  for (int i = head[t]; i; i = Next[i]) {
    if (!d[ver[i]]) {
      dfs(ver[i]);
    }
  }
}
void dfss(int t) {
  d[t] = 1;
  state[cur][t] = 1;
  state[t][cur] = 1;
  for (int i = 0; i < ss[t].size(); ++i) {
    if (!d[ss[t][i]]) {
      dfss(ss[t][i]);
    }
  }
}
int main() {
  int a, b;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; ++i) {
    scanf("%d%d", &a, &b);
    // add(a, b, 1);
    ss[a].push_back(b);
  }
  for (int i = 1; i <= n; ++i) {
    // add(i, i, 1);
    ss[i].push_back(i);
  }
  for (int i = 1; i <= n; ++i) {
    cur = i;
    memset(d, 0, sizeof(d));
    dfss(i);
  }
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    int flag = 1;
    for (int j = 1; j <= n; ++j) {
      if (!state[i][j] && !state[j][i]) {
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