#include <bits/stdc++.h>
// https://www.luogu.com.cn/problem/P1402
// 酒店之王
// 这个题重点在于抽象出网络流模型
// 关键点在于如何限制流量使每个客人对应一间房间一份菜
// 因为网络流是从源点流向汇点,所以为客人加点,每个客人指向自己的备份,最大流量为1,即可
// 和P1231类似
using namespace std;
const int inf = 1 << 29, N = 50010, M = 300010;
int head[N], ver[M], edge[M], Next[M], d[N];
int n, m, s, t, tot, maxflow;
queue<int> q;
void add(int x, int y, int z) {
  ver[++tot] = y, edge[tot] = z, Next[tot] = head[x], head[x] = tot;
  ver[++tot] = x, edge[tot] = 0;
  Next[tot] = head[y], head[y] = tot;
}
bool bfs() { //在残量网络上构造分层图
  memset(d, 0, sizeof(d));
  while (q.size())
    q.pop();
  q.push(s);
  d[s] = 1;
  while (q.size()) {
    int x = q.front();
    q.pop();
    for (int i = head[x]; i; i = Next[i]) {
      if (edge[i] && !d[ver[i]]) {
        q.push(ver[i]);
        d[ver[i]] = d[x] + 1;
        if (ver[i] == t)
          return 1;
      }
    }
  }
  return 0;
}
int dinic(int x, int flow) { //当前分层图桑增广
  if (x == t)
    return flow;
  int rest = flow, k;
  for (int i = head[x]; i && rest; i = Next[i]) {
    if (edge[i] && d[ver[i]] == d[x] + 1) {
      k = dinic(ver[i], min(rest, edge[i]));
      if (!k)
        d[ver[i]] = 0; //剪枝,去掉増广完毕的点
      edge[i] -= k;
      edge[i ^ 1] += k;
      rest -= k;
    }
  }
  return flow - rest;
}
int main() {
  int n1, n2, n3;
  int m1, m2;
  cin >> n1 >> n2 >> n3;

  n = n1 * 2 + n2 + n3;
  s = 0;
  t = n + 1; //源点,汇点
  tot = 1;
  int temp;
  for (int i = 1; i <= n1; ++i) {
    for (int j = 1; j <= n2; ++j) {
      scanf("%d", &temp);
      if (temp)
        add(j, i + n2, 1);
    }
  }
  for (int i = 1; i <= n1; ++i) {
    for (int j = 1; j <= n3; ++j) {
      scanf("%d", &temp);
      if (temp)
        add(n1 + n2 + i, j + n1 + n2 + n2, 1);
    }
  }
  for (int i = 1; i <= n1; ++i) {
    add(i + n2, i + n1 + n2, 1);
  }
  for (int i = 1; i <= n2; ++i) {
    add(s, i, 1);
  }
  for (int i = 1; i <= n3; ++i) {
    add(i + n1 + n2 + n2, t, 1);
  }
  int flow = 0;
  while (bfs()) {
    while (flow = dinic(s, inf))
      maxflow += flow;
  }
  cout << maxflow << endl;
  return 0;
}