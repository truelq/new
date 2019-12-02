#include <bits/stdc++.h>
//拓扑排序加bfs
using namespace std;

int ss[1000001];
int save[1000001];
int ver[100000001]; //用vector估计太慢
int netx[100000001];
int head[1000001];
int deg[1000001];
int tot;
int cnt;
int n, k;
int ttt[1001][1001];
// vector<vector<int>> sss;
void add(int x, int y) {
  ver[++tot] = y;
  netx[tot] = head[x];
  head[x] = tot;
  deg[y]++;
}
void topsort() {
  //拓扑排序
  queue<int> q;
  for (int i = 1; i <= n; ++i) {
    if (deg[i] == 0)
      q.push(i);
  }
  while (q.size()) {
    int x = q.front();
    q.pop();
    ss[++cnt] = x;
    for (int i = head[x]; i; i = netx[i]) {
      int y = ver[i];
      if (--deg[y] == 0)
        q.push(y);
    }
  }
}
int main() {
  int temp;
  int aa, bb;
  int tempa, tempb;
  cin >> aa >> bb;
  n = aa * aa;
  k = 1;
  for (int i = 0; i < bb; ++i) {
    scanf("%d%d", &tempa, &tempb);
    ttt[tempa][tempb] = 1;
  }
  for (int i = 1; i < aa; ++i) {
    for (int j = 1; j < aa; ++j) {
      if (!ttt[i + 1][j]) {
        add((i - 1) * aa + j, i * aa + j);
      }
      if (!ttt[i][j + 1]) {
        add((i - 1) * aa + j, (i - 1) * aa + j + 1);
      }
    }
    if (!ttt[i + 1][aa]) {
      add(i * aa, i * aa + aa);
    }
  }
  for (int j = 1; j < aa; ++j) {
    if (!ttt[aa][j + 1]) {
      add((aa - 1) * aa + j, (aa - 1) * aa + j + 1);
    }
  }
  topsort();
  //临时输出
  //for (int i = 1; i <= cnt; ++i)
  //  printf("%d ", ss[i]);
  //cout << endl;
  //计算路径数
  //定位起点
  for (int i = 1; i <= cnt; ++i) {
    if (ss[i] == 1) {
      temp = i;
      break;
    }
  }
  save[temp] = k;
  //统计路径数
  for (int i = 1; i <= n; ++i) {
    temp = save[ss[i]];
    for (int j = head[ss[i]]; j; j = netx[j]) {
      int k = ver[j]; //后继节点
      save[k] += temp;
      if (save[k] >= 1000000007)
        save[k] %= 1000000007;
    }
  }
  //定位终点
  for (int i = cnt; i; --i) {
    if (ss[i] == n) {
      temp = i;
      break;
    }
  }
  cout << save[temp] << endl;
}