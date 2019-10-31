#include <bits/stdc++.h>

//并查集，一般并的条件
// https://www.luogu.org/problem/P3958
using namespace std;
struct P3958 {
  long long x;
  long long y;
  long long z;
};

P3958 ss[100005];
bool operator<(P3958 &a, P3958 &b) {
  if (a.z == b.z) {
    if (a.y == b.y) {
      return a.x < b.x;
    }
    return a.y < b.y;
  }
  return a.z < b.z;
}
int sets[100005];
int par[100005];
void makeset(int x, int *sets, int *par);
int findset(int x, int *par);
void unionset(int x, int y, int *sets, int *par);
int savea[100005];
int saveb[100005];
int acount = 0;
int bcount = 0;
int main() {
  freopen("C:\\Users\\32125\\Documents\\vscodec\\bingchaji\\testdata.in", "r",
          stdin);
  int t;
  int n, h, r;
  cin >> t;
  while (t--) {
    memset(ss, 0, sizeof(ss));
    acount = 0;
    bcount = 0;
    cin >> n >> h >> r;
    for (int i = 1; i <= n; ++i)
      makeset(i, sets, par);
    for (int i = 1; i <= n; ++i) {
      scanf("%lld %lld %lld", &ss[i].x, &ss[i].y, &ss[i].z);
    }
    sort(ss + 1, ss + n + 1);
    if (ss[1].z > r || ss[n].z + r < h) {
      printf("No\n");
    } else {
      for (int i = 1; i <= n; ++i) {
        if (ss[i].z <= r) {
          savea[acount++] = i;
        }
        if (ss[i].z + r >= h) {
          saveb[bcount++] = i;
        }
        for (int j = i + 1; j <= n; ++j) {
          unsigned long long x = (ss[j].x - ss[i].x) * (ss[j].x - ss[i].x);
          unsigned long long y = (ss[j].y - ss[i].y) * (ss[j].y - ss[i].y);
          unsigned long long z = (ss[j].z - ss[i].z) * (ss[j].z - ss[i].z);
          if (sqrt(x) <= 2 * r && sqrt(x + y) <= 2 * r &&
              sqrt(x + y + z) <= 2 * r) {
            int x = findset(i, par);
            int y = findset(j, par);
            if (x != y)
              unionset(i, j, sets, par);
          }
        }
      }

      int flag = 0;
      for (int i = 0; i < acount; ++i) {
        for (int j = 0; j < bcount; ++j) {
          if (findset(savea[i], par) == findset(saveb[j], par)) {
            flag = 1;

            break;
          }
        }
        if (flag)
          break;
      }
      if (flag) {
        printf("Yes\n");
      } else {
        printf("No\n");
      }
    }
  }
  return 0;
}
void makeset(int x, int *sets, int *par) {
  sets[x] = 0;
  par[x] = x;
}
int findset(int x, int *par) {
  int temp;
  int parx = x;
  while (parx != par[parx]) {
    parx = par[parx];
  }

  while (x != parx) { //查询优化
    temp = par[x];
    par[x] = parx;
    x = temp;
  }

  return parx;
}
void unionset(int x, int y, int *sets, int *par) {
  x = findset(x, par);
  y = findset(y, par);
  if (sets[x] > sets[y]) {
    par[y] = x;
    sets[x] = 1;
    sets[y] = 0;
  } else if (sets[x] == sets[y]) {
    par[y] = x;
    sets[x] += 1;
    sets[y] = 0;
  } else {
    par[x] = y;
    sets[x] = 0;
    sets[y] = 1;
  }
}