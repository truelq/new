#include <bits/stdc++.h>

using namespace std;
struct rec {
  int x, y, z;
};
rec edge[500010];
int fa[100010];
bool operator<(rec a, rec b) { return a.z < b.z; }
int get(int x) {
  if (x == fa[x])
    return x;
  return fa[x] = get(fa[x]);
}
int n, m, root;
int ans;
int main() {
  int x, y, z;
  scanf("%d%d%d", &n, &m, &root);
  for (int i = 1; i <= m; ++i) {
    scanf("%d%d%d", &x, &y, &z);
    edge[i].x = x, edge[i].y = y, edge[i].z = z;
  }
  sort(edge + 1, edge + m + 1);
  for (int i = 1; i <= n; ++i)
    fa[i] = i;
  for (int i = 1; i <= m; ++i) {
    int x = get(edge[i].x);
    int y = get(edge[i].y);
    if (x == y)
      continue;
    fa[x] = y;
    ans = max(ans, edge[i].z);
  }
  printf("%d\n", ans);
}