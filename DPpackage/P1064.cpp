#include <bits/stdc++.h>

//有依赖的背包，转换成分组背包
// https://www.luogu.org/problem/P1064

using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  int ss[m + 1][3];
  set<int> s[m + 1];
  for (int i = 1; i <= m; ++i) {
    scanf("%d %d %d", ss[i], ss[i] + 1, ss[i] + 2);
    ss[i][1] *= ss[i][0];
    if (ss[i][2]) {
      s[ss[i][2]].insert(i);
    }
  }
  int save[n + 1];
  int little[n + 1];
  set<int>::iterator iter;
  memset(save, 0, sizeof(save));
  for (int i = 1; i <= m; ++i) {
    if (!ss[i][2]) {
      //memset(little, 0, sizeof(little));
      memcpy(little,save,sizeof(save));
      // for (int j = ss[i][0]; j <= n; ++j) { //必选
      //  little[j] = ss[i][1];
      //}
      for (iter = s[i].begin(); iter != s[i].end(); ++iter) {
        for (int k = n; k >= ss[*iter][0]; --k) {
          little[k] = max(little[k], little[k - ss[*iter][0]] + ss[*iter][1]);
        }
      }
      for (int j = n; j >= ss[i][0]; --j) {
        little[j] = little[j - ss[i][0]] + ss[i][1];
      }
      for (int j = n; j>=ss[i][0]; --j) {
          //int temp = save[j];
          //for (int k = j; k >= ss[i][0]; --k) {
          //  temp = max(temp, save[j - k] + little[k]);
          //}
          //save[j] = temp;
          save[j]=max(save[j],little[j]);
      }
    }
  }
  cout << save[n] << endl;
  return 0;
}