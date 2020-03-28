#include <bits/stdc++.h>

using namespace std;
int n, s, l, m;
vector<long long> ss[1001];
string ssss[1001];
int len = 0;

void init(int t, string &temp) {
  for (int i = 0; i<temp.size()>> 3; ++i) {
    string s = "";
    s = temp.substr(8 * i, 8);
    ss[t].push_back(stoll(s, 0, 16));
  }
}
void solve(int t) {
  int tiao = t / s;
  int dsk = tiao % n;
  int blk = tiao / (n - 1);
  if (blk < ssss[dsk].size() / 8 / s) {
    for (int i = 0; i < 8; ++i) {
      printf("%c", ssss[dsk][(blk * s + t % s) * 8 + i]);
    }
  } else if (blk < len / 8 / s && ssss[dsk].size() == 0 && l + 1 == n) {
    long long ans = 0;
    for (int j = 0; j < n; ++j) {
      if (j == dsk)
        continue;
      string tt = ssss[j].substr((blk * s + t % s) * 8, 8);
      ans ^= stoll(tt, 0, 16);
      // ans ^= ss[j][blk * s + t % s];
    }
    printf("%08llX", ans);
  } else {
    printf("-");
  }
  printf("\n");
}
char ttt[10240];
int main() {
  string temp;
  int t;
  // cin >> n >> s >> l;
  scanf("%d%d%d", &n, &s, &l);
  for (int i = 0; i < l; ++i) {
    scanf("%d %s", &t, ttt);
    // cin >> t >> temp;
    ssss[t] = ttt;
    len = max(len, (int)ssss[t].size());
    // init(t, temp);
  }
  // cin >> m;
  scanf("%d", &m);
  for (int i = 0; i < m; ++i) {
    // cin >> t;
    scanf("%d", &t);
    solve(t);
  }
}