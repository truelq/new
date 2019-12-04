#include <bits/stdc++.h>

using namespace std;
// https://www.luogu.com.cn/problem/P2341
int ver[50005];
int netx[50005];
int head[10001];
int deg[10001];
int tot;
int n, m;
int dfn[10001];
int low[10001];
int indxe;
int stacks[10001];
int stackstate[10001];
int stackcut;
int sum[10001];
int sp[10001];
int ccc;
int add(int i, int t) {
  ver[++tot] = t;
  netx[tot] = head[i];
  head[i] = tot;
}
void tarjan(int u) {
  low[u] = dfn[u] = ++indxe;
  stacks[++stackcut] = u;
  stackstate[u]++;
  for (int i = head[u]; i; i = netx[i]) {
    int v = ver[i];
    if (!dfn[v]) {
      tarjan(v);
      low[u] = min(low[u], low[v]);
    } else if (stackstate[v]) {
      low[u] = min(low[u], dfn[v]);
    }
  }
  if (low[u] == dfn[u]) {
    int len = stackcut;
    ccc++;
    do {
      //printf("%d ", stacks[stackcut]);
      sum[ccc] += 1;
      stackstate[stacks[stackcut]]--;
      sp[stacks[stackcut]] = ccc;
      --stackcut;
    } while (u != stacks[stackcut + 1]);
    //sum[ccc] -= 1;
    //printf("%d\n", sum[ccc]);
  }
}
int main() {
  int a, b;
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    scanf("%d%d", &a, &b);
    add(a, b);
  }
  for (int i = 1; i <= n; ++i) {
    if (!dfn[i])
      tarjan(i);
  }

  for (int i = 1; i <= n; ++i) {
    for (int j = head[i]; j; j = netx[j]) {
      int v = ver[j];
      if (sp[i] != sp[v]) {
        deg[sp[i]]++;
      }
    }
  }
  int count = 0;
  int ans = 0;
  for (int i = 1; i <= ccc; ++i) {
    if (!deg[i]) {
      if (ans) {
        printf("0\n");
        return 0;
      }
      ans = sum[i];
    }
  }
  printf("%d\n", ans);
  return 0;
}