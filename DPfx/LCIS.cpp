#include <bits/stdc++.h>

//最长公共上升子序列
// https://www.luogu.org/problem/CF10D
using namespace std;
int main() {
  int a, b;
  cin >> a;
  int aa[a + 1];
  for (int i = 1; i <= a; ++i) {
    scanf("%d", aa + i);
  }
  cin >> b;
  int bb[b];
  for (int i = 1; i <= b; ++i) {
    scanf("%d", bb + i);
  }
  aa[0]=bb[0]=0;
  
}