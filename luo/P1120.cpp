#include <bits/stdc++.h>
//这是一个没有顺序的树
using namespace std;
int ss[66];
int visit[66];
int tot;
int sum;
int num;
int len;
int dfs(int stick, int cab, int last) {
  if (stick > num)
    return true;
  if (cab == len)
    return dfs(stick + 1, 0, 1);
  int fail = 0;
  for (int i = last; i <= tot; ++i) {
    if (!visit[i] && cab + ss[i] <= len && fail != ss[i]) {
      visit[i] = 1;
      if (dfs(stick, cab + ss[i], i + 1))
        return true;
      fail = ss[i];
      visit[i] = 0;
      if (cab == 0 || cab + ss[i] == len)
        return false;
    }
  }
  return false;
}
int main() {
  int n;
  int temp;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> temp;
    if (temp <= 50) {
      ss[++tot] = temp;
      sum += temp;
    }
  }
  sort(ss + 1, ss + tot + 1);
  reverse(ss + 1, ss + tot + 1);
  for (len = ss[1]; len <= sum; ++len) {
    if (sum % len != 0)
      continue;
    num = sum / len;
    memset(visit, 0, sizeof visit);
    if (dfs(1, 0, 1))
      break;
  }
  cout << len << endl;
  return 0;
}