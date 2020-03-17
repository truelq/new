#include <bits/stdc++.h>

using namespace std;
int t;
int ss[4][4];
int count() {
  int count = 0;
  for (int i = 1; i <= 3; ++i) {
    for (int j = 1; j <= 3; ++j) {
      if (!ss[i][j])
        ++count;
    }
  }
  return count;
}
int check() {
  int flag = 0;
  int ans = 0;
  for (int i = 1; i <= 3; ++i) {
    if (ss[i][1] && ss[i][1] == ss[i][2] && ss[i][2] == ss[i][3]) {
      flag = ss[i][1];
      break;
    }
    if (ss[1][i] && ss[2][i] == ss[1][i] && ss[2][i] == ss[3][i]) {
      flag = ss[1][i];
      break;
    }
  }
  if (ss[1][1] && ss[1][1] == ss[2][2] && ss[2][2] == ss[3][3])
    flag = ss[1][1];
  if (ss[3][1] && ss[3][1] == ss[2][2] && ss[2][2] == ss[1][3])
    flag = ss[3][1];
  if (flag) {
    ans = count();
    return flag == 1 ? ans + 1 : (-1 * ans - 1);
  }
  return 0;
}

int dfs(int t) {
  if (check())
    return check();
  if (!count())
    return 0;
  int Max = -10, Min = 10;
  for (int i = 1; i <= 3; ++i) {
    for (int j = 1; j <= 3; ++j) {
      if (!ss[i][j]) {
        ss[i][j] = t;
        if (t == 1)
          Max = max(Max, dfs(2)); // 1下完后返回值为1的情况
        if (t == 2)
          Min = min(Min, dfs(1));
        ss[i][j] = 0;
      }
    }
  }
  if (t == 1)
    return Max;
  if (t == 2)
    return Min;
}
int main() {
  int temp;
  cin >> t;
  while (t--) {
    for (int i = 1; i <= 3; ++i)
      for (int j = 1; j <= 3; ++j)
        scanf("%d", &ss[i][j]);
    cout << dfs(1) << endl;
  }
}