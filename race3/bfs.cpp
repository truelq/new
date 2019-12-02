#include <bits/stdc++.h>
//拓扑排序加bfs
using namespace std;

int ss[1001];
long long save[1001];
int ver[1000001]; //用vector估计太慢
int netx[1000001];
int head[1001];
int deg[1001];
int tot;
int cnt;
long long n, k;
// vector<vector<int>> sss;
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
  freopen("C:\\Users\\32125\\Documents\\vscodec\\race3\\1\\data10.in","r",stdin);
  int temp;
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) {
    while (scanf("%d", &temp) && temp) { //假设输入有序,并且每行输入0结束
      // sss[i].push_back(temp);
      // ss[temp] += 1;
      ver[++tot] = temp;
      netx[tot] = head[i];
      head[i] = tot;
      deg[temp]++;
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
  long long tempa;
  //统计路径数
  for (int i = 1; i <= n; ++i) {
    tempa = save[ss[i]];
    for (int j = head[ss[i]]; j; j = netx[j]) {
      int k = ver[j]; //后继节点
      save[k] += tempa;
      save[k] %= 1000000007;
    }
  }
  //定位终点,不需要
  //for (int i = cnt; i; --i) {
  //  if (ss[i] == n) {
  //    tempa = i;
  //    break;
  //  }
  //}
  //printf("%d\n",tempa);
  printf("%lld\n", save[n]);
  //for (int i = 1; i <= cnt; ++i)
  //  printf("%d ", save[ss[i]]);
  cout << endl;
}