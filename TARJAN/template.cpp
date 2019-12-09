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
  ver[++tot] = t; //加边模板
  netx[tot] = head[i];
  head[i] = tot;
}
void tarjan(int u) {
  low[u] = dfn[u] = ++indxe; //时间戳,标识
  stacks[++stackcut] = u;    //入栈
  stackstate[u]++;           //标记
  for (int i = head[u]; i; i = netx[i]) {
    int v = ver[i];
    if (!dfn[v]) { //没有被访问过
      tarjan(v);
      low[u] = min(low[u], low[v]);
    } else if (stackstate[v]) { //在栈中
      low[u] = min(low[u], dfn[v]);
    }
  }
  if (low[u] == dfn[u]) { //确定是一个连通分量的根节点,下面应是适应性操作
    ccc++;                //缩点后的数量
    do {
      // printf("%d ", stacks[stackcut]);
      sum[ccc] += 1;
      stackstate[stacks[stackcut]]--;
      sp[stacks[stackcut]] = ccc; //缩点标记
      --stackcut;
    } while (u != stacks[stackcut + 1]);
    // sum[ccc] -= 1;
    // printf("%d\n", sum[ccc]);
  }
}
int main() {
  int a, b;
  cin >> n >> m; //节点数和边数
  for (int i = 0; i < m; ++i) {
    scanf("%d%d", &a, &b);
    add(a, b); //加边
  }
  for (int i = 1; i <= n; ++i) {
    if (!dfn[i]) //遍历
      tarjan(i);
  }

  for (int i = 1; i <= n; ++i) {
    for (int j = head[i]; j; j = netx[j]) {
      int v = ver[j];
      if (sp[i] != sp[v]) { //计算缩点后的出度
        deg[sp[i]]++;       //出度
      }
    }
  }
  int count = 0;
  int ans = 0;
  for (int i = 1; i <= ccc; ++i) {
    if (!deg[i]) {
      if (ans) { //有两个出度为0,一定错
        printf("0\n");
        return 0;
      }
      ans = sum[i]; // tarjen中计算的强连通分量中点的个数
    }
  }
  printf("%d\n", ans);
  return 0;
}