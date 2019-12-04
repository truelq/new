#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;
//在线多重背包
int main() {
  int n;
  cin >> n;
  int a[n + 1], b[n + 1], c[n + 1];
  vector<int> aa[n + 1], bb[n + 1];
  for (int i = 1; i <= n; ++i) {
    scanf("%d %d %d", a + i, b + i, c + i);
    for (int j = 1; j <= c[i]; j <<= 1) {
      aa[i].push_back(j * a[i]);
      bb[i].push_back(j * b[i]);
      c[i] -= j;
    }
    if (c[i]) {
      aa[i].push_back(c[i] * a[i]);
      bb[i].push_back(b[i] * c[i]);
    }
  }
  int q;
  int maxs = 0;
  cin >> q;
  int d[q], e[q];
  for (int i = 0; i < q; ++i) {
    scanf("%d %d", d + i, e + i);
    maxs = max(maxs, e[i]);
  }
  int savea[n + 3][maxs + 2] = {0};
  int saveb[n + 3][maxs + 2] = {0};
  memset(savea, 0, sizeof(savea));
  memset(saveb, 0, sizeof(saveb));
  for (int i = 1; i <= n; ++i) {
    memcpy(savea[i], savea[i - 1], (maxs + 2) << 2);
    for (int j = 0; j < aa[i].size(); ++j) {
      for (int k = maxs; k >= aa[i][j]; --k) {
        savea[i][k] = max(savea[i][k], savea[i][k - aa[i][j]] + bb[i][j]);
      }
    }
  }
  //cout << savea[n][maxs] << endl;
  for (int i = n; i; --i) {
    memcpy(saveb[i], saveb[i + 1], (maxs + 2) << 2);
    for (int j = 0; j < aa[i].size(); ++j) {
      for (int k = maxs; k >= aa[i][j]; --k) {
        saveb[i][k] = max(saveb[i][k], saveb[i][k - aa[i][j]] + bb[i][j]);
      }
    }
  }
  //cout << saveb[1][maxs] << endl;
  int temp = 0;
  for (int i = 0; i < q; ++i) {
    temp = 0;
    for (int j = 0; j <= e[i]; ++j) {
      temp = max(temp, savea[d[i]][j] + saveb[d[i] + 2][e[i] - j]);
    }
    cout << temp << endl;
  }
}