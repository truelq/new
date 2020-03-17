#include <bits/stdc++.h>

using namespace std;
int n;
int ss[301];
int save[301];
int vis[301][301][301];
int dfs(int t) {
  if (t == n) {
    if ((save[n] + save[n - 1]) / 2 != ss[n])
      return false;
    return true;
  }
  if (t == 1) {
    for (int i = 1; i <= 2 * ss[1]; ++i) {
      save[t] = i;
      int temp = 2 * ss[1] - i;
      if (temp > 0) {
        save[t + 1] = temp;
        if (dfs(t + 1))
          return 1;
      }
      if (temp + 1 > 0) {
        save[t + 1] = temp + 1;
        if (dfs(t + 1))
          return 1;
      }
    }
  } else {
    int temp = 3 * ss[t] - save[t] - save[t - 1];
    if (temp > 0 && !vis[t][save[t]][temp]) {
      save[t + 1] = temp;
      vis[t][save[t]][save[t + 1]] = 1;

      if (dfs(t + 1))
        return 1;
    }
    if (temp + 1 > 0 && !vis[t][save[t]][temp + 1]) {
      save[t + 1] = temp + 1;
      vis[t][save[t]][save[t + 1]] = 1;

      if (dfs(t + 1))
        return 1;
    }
    if (temp + 2 > 0 && !vis[t][save[t]][temp + 2]) {
      save[t + 1] = temp + 2;
      vis[t][save[t]][save[t + 1]] = 1;

      if (dfs(t + 1))
        return 1;
    }
    return 0;
  }
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> ss[i];
  }
  save[0] = ss[1];
  dfs(1);
  for (int i = 1; i <= n; ++i) {
    cout << save[i] << ' ';
  }
}