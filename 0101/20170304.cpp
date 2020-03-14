#include <bits/stdc++.h>

using namespace std;
int n, m;
struct ss {
  int a;
  int b;
  int d;
};
ss save[200001];
int fa[100001];
int ans;
bool operator<(ss a, ss b) { return a.d < b.d; }
int get(int x) {
  if (x == fa[x])
    return x;
  return fa[x] = get(fa[x]);
}
int main() {
  cin >> n >> m;
  for (int i = 1; i <= m; ++i) {
    scanf("%d%d%d", &save[i].a, &save[i].b, &save[i].d);
  }
  sort(save + 1, save + m + 1);
  for (int i = 1; i <= n; ++i) {
    fa[i] = i;
  }
  int i;
  for (i = 1; i <= m; ++i) {
    int x = get(save[i].a);
    int y = get(save[i].b);
    if (x == y)
      continue;
    fa[x] = y;
    if (get(fa[1]) == get(fa[n]))
      break;
  }
  printf("%d\n", save[i].d);
  return 0;
}