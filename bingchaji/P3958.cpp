#include <bits/stdc++.h>

//并查集，一般并的条件
// https://www.luogu.org/problem/P3958
using namespace std;
struct P3958 {
  unsigned long long x;
  unsigned long long y;
  unsigned long long z;
};

P3958 ss[1001];
bool operator<(P3958 &a, P3958 &b) {
  if (a.z == b.z) {
    if (a.y == b.y) {
      return a.x < b.x;
    }
    return a.y < b.y;
  }
  return a.z < b.z;
}
int main() {
  int t;
  int n, h, r;
  cin >> t;
  while (t--) {
    memset(ss, 0, sizeof(ss));
    cin >> n >> h >> r;
    for (int i = 1; i <= n; ++i) {
      scanf("%d %d %d", &ss[i].x, &ss[i].y, &ss[i].z);
    }
    sort(ss,ss+n+1);
    
  }
}