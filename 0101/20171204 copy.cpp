#include <algorithm>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;
const int maxn = 510;
const long long INF = 0x3f3f3f3f3f3f3f3f;
struct node {
  int v, t;
  long long c;
};
int n, m;
vector<vector<node>> G(maxn); //用邻接表来表示图
bool visited[maxn];
long long d[maxn];
long long con_trail[maxn]; //记录到某结点的连续小路长
long long pow_2(long long a) { return a * a; }
void Dijkstra(int i) {
  memset(d, 0x3f, sizeof(d));
  d[i] = 0;
  for (int j = 0; j < n; j++) {
    int u = 0;
    for (int k = 0; k < n; k++) {
      if (!visited[k] && (u == 0 || d[k] < d[u])) //在非S中寻找权值最小的点
      {
        u = k;
      }
    }
    visited[u] = true;
    for (int p = 0; p < G[u].size(); p++) {
      node r = G[u][p];
      if (visited[r.v])
        continue;
      if (r.t == 1) //小路
      {
        // d[u]+w(u,v)<d[v]
        if (d[u] + r.c * r.c + con_trail[u] * r.c * 2 < d[r.v]) {
          d[r.v] = d[u] + r.c * r.c + con_trail[u] * r.c * 2;
          con_trail[r.v] = con_trail[u] + r.c;
        }
      } else //大路
      {
        if (d[u] + r.c < d[r.v]) {
          d[r.v] = d[u] + r.c;
          con_trail[r.v] = 0; //连续的小路被终结
        }
      }
    }
  }
}
int main() {
  int i, a, b;
  cin >> n >> m;
  for (i = 0; i < m; i++) {
    node n1, n2;
    cin >> n1.t >> a >> b >> n1.c;
    n2.t = n1.t;
    n2.c = n1.c;
    n1.v = a;
    n2.v = b;
    G[a].push_back(n2);
    G[b].push_back(n1);
  }
  memset(visited, 0, sizeof(visited));
  memset(con_trail, 0, sizeof(con_trail));
  Dijkstra(1); //从1号路口出发
  cout << d[n];
}