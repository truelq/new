#include <bits/stdc++.h>

//多重限制，二维费用背包
// https://www.luogu.org/problem/P1507
using namespace std;
int main() {
  int v, w;
  cin >> v >> w;
  int n;
  cin >> n;
  int ss[n + 1][3];
  memset(ss, 0, sizeof(ss));
  for (int i = 1; i <= n; ++i) {
    scanf("%d %d %d", ss[i], ss[i] + 1, ss[i] + 2);
  }
  int save[v + 1][w + 1];
  memset(save, 0, sizeof(save));
  for (int i = 1; i <= n; ++i) {
    for (int j = v; j; --j) {
      if (j >= ss[i][0]) {
        for (int k = w; k; --k) {
          if (k >= ss[i][1]) {
              save[j][k]=max(save[j][k],save[j-ss[i][0]][k-ss[i][1]]+ss[i][2]);
          }
        }
      }
    }
  }
  cout<<save[v][w]<<endl;
  return 0;
}