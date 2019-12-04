#include <bits/stdc++.h>

using namespace std;
struct T108419 {
  int a, b;
};
bool operator<(T108419 &a, T108419 &b) { return a.a < b.a; }
int ss[1001][1001];
int visit[1001];
T108419 sss[100001];
int cou[1001];
queue<int> wait;
queue<int> waita;
int main() {
  int n, m;
  cin >> n >> m;
  int a, b;
  for (int i = 1; i <= m; ++i) {
    scanf("%d%d", &a, &b);
    if (!ss[a][b]) {
      cou[a] += 1;
    }
    ss[a][b] = 1;
    sss[i].a = a;
    sss[i].b = b;
  }
  for (int i = 1; i <= m; ++i) {
    int ans = 0;
    int flag = 0;
    int a = sss[i].a;
    int b = sss[i].b;
    memset(visit, 0, sizeof(visit));
    while (!wait.empty()) {
      wait.pop();
      waita.pop();
    }
    ss[a][b] = 0;
    wait.push(a);
    waita.push(0);
    while (!wait.empty()) {
      int temp = wait.front();
      int tempa = waita.front();
      wait.pop();
      waita.pop();
      if (visit[temp]) {
        continue;
      }
      visit[temp] = 1;
      for (int i = 1; i <= n; ++i) {
        if (ss[temp][i] && !visit[i]) {
          if (i == b) {
            flag = 1;
            ans = tempa+1;
            break;
          }
          wait.push(i);
          waita.push(tempa + 1);
        }
      }
      if (flag)
        break;
    }
    if (flag)
      printf("%d ", ans);
    else
      printf("-1 ");
    ss[a][b] = 1;
  }
  return 0;
}