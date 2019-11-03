#include <bits/stdc++.h>
using namespace std;
short ss[41][4];
short save[41][4];
int main() {
  int n;
  short maxs = 0;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> ss[i][0] >> ss[i][1] >> ss[i][2] >> ss[i][3];
    // scanf("%d %d %d %d", &ss[i][0], &ss[i][1], &ss[i][2], &ss[i][3]);
  }
  short tag3 = 0;
  short tag1 = 0; //另一cpu空闲时间
  short temptag3 = 0;
  short temptag1 = 0;
  for (int i = 1; i <= n; ++i) {
    short mm = 0x7fff;
    for (int j = 0; j <= 3; ++j) {
      mm = min(mm, save[i - 1][j]);
    }
    save[i][1] = mm + ss[i][1]; // 2
    save[i][3] = mm + ss[i][3]; // 4
    // 3
    save[i][2] = min(mm, (short)(save[i - 1][0] - tag1)) + ss[i][2];
    if (mm <= save[i - 1][0] - tag1) {
      temptag3 = ss[i][2];
    } else {
      temptag3 = abs(ss[i][2] - tag1);
    }
    // tag3=abs(tag1-ss[i-1][2]);
    // 1
    int a,b;
    if (i == 1) {
      a=ss[i][0];
      b=ss[i][0];
    } else {
       a = min(save[i - 1][0], (short)(save[i - 1][0] - tag1 + ss[i][0]));
       b = min(save[i - 1][2], (short)(save[i - 1][2] - tag3 + ss[i][0]));
    }
    int tempmm = min(save[i - 1][1], save[i - 1][3]) + ss[i][0];
    if (tempmm <= a && tempmm <= b) {
      save[i][0] = tempmm;
      temptag1 = ss[i][0];
    } else if (a < b) {
      save[i][0] = a;
      temptag1 = abs(ss[i][0] - tag1);
    } else if (a > b) {
      save[i][0] = b;
      temptag1 = abs(ss[i][0] - tag3);
    } else {
      save[i][0] = a;
      temptag1 = 0x7fff;
      temptag1 = min(temptag1, (short)(abs(ss[i][0] - tag1)));
      temptag1 = min(temptag1, (short)(abs(ss[i][0] - tag3)));
    }
    tag1 = temptag1;
    tag3 = temptag3;
  }
  maxs = 0x7fff;
  for (int i = 0; i <= 3; ++i) {
    maxs = min(maxs, save[n][i]);
  }
  cout << maxs << endl;
  return 0;
}