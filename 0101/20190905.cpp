#include <bits/stdc++.h>

//求距离最短的k个路径,只要求出m个点中任意两点距离即可,但m较大,可以求最低的,使用优先队列
//树形dp
//无向图
using namespace std;
struct T20190905 {
  int a;
  int b;
};

int n, m, k;
int ss[100001]; //有效节点
vector<T20190905> save[100001];
long long ans[100001][101]; // dp过程,和dfs很类似
long long tempans[101];
int num[100001];
void dfs(int u, int father) {
  ans[u][0] = 0;
  if (ss[u]) {
    num[u] = 1;    //初始化为1
    ans[u][1] = 0; //仅选择当前节点而不选择后继节点时
  }
  for (int i = 0; i < save[u].size(); ++i) {
    int v = save[u][i].a;
    int c = save[u][i].b;
    if (v == father)
      continue; //不能向上计算
    dfs(v, u);
    int tempsum = min(k, num[u] + num[v]); //总最大数,为减少计算
    int tempu = min(k, num[u]);            //当前节点最大数
    num[u] += num[v]; //遍历其他节点时v当做其他节点的其他节点
    memcpy(tempans, ans[u], sizeof(long long) * (k + 1));
    for (int j = 0; j <= tempu; ++j) {
      for (int t = 0; j + t <= tempsum; ++t) {
        // dp背包核心
        long long ttt = tempans[j] + ans[v][t] + c * t * (k - t);
        if (ttt < ans[u][j + t])
          ans[u][j + t] = ttt; //总共j+t个节点
      }
    }
  }
}
int main() {
  cin >> n >> m >> k;
  int temp;
  int a, b, c;
  memset(ans, 0x3f, sizeof(ans));

  for (int i = 1; i <= m; ++i) {
    scanf("%d", &temp);
    ss[temp] = 1;
  }
  for (int i = 1; i < n; ++i) {
    scanf("%d%d%d", &a, &b, &c);
    save[a].push_back({b, c});
    save[b].push_back({a, c});
  }
  dfs(1, -2);
  printf("%lld\n", ans[1][k]);
  return 0;
}