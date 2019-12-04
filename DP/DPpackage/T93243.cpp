#include <bits/stdc++.h>

using namespace std;
//最大报销额 多重限制
// https://www.luogu.org/problem/T93243
int save[3000050];
int sss[3000050];
int main() {
  double w = 0;
  int n = 0;
  int t = 0;
  int flag;
  char c;
  double v;
  int count=0;
  double maxs = 0;
  double ss[26];
  //vector<int> sss;
  while (scanf("%lf %d", &w, &n) && n) {
    //sss.clear();
    count=0;
    for (int i = 0; i < n; ++i) {
      ss[0] = ss[1] = ss[2] = 0;
      maxs = 0;
      flag = 0;
      scanf("%d", &t);
      for (int i = 0; i < t; ++i) {
        scanf(" %c:%lf", &c, &v);
        if (c == 'X') {
          flag=1;
        }
        ss[c - 'A'] += v;
      }
      if (flag||ss[0]>600||ss[1]>600||ss[2]>600||ss[0]+ss[1]+ss[2]>1000) {
        continue;
      }
      //sss.push_back(round((ss[0]+ss[1]+ss[2]) * 100));
      sss[count++]=round((ss[0]+ss[1]+ss[2]) * 100);
    }
    // sort(sss.begin(), sss.end());
    int length = round(w * 100);
    memset(save, 0, sizeof(save));
    for (int i = 0; i < count; ++i) {
      for (int j = length; j >= sss[i]; --j) {
        save[j] = max(save[j], save[j - sss[i]] + sss[i]);
      }
    }
    printf("%.2lf\n", save[length] / 100.0);
  }
}
