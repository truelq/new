#include <bits/stdc++.h>

using namespace std;

int op, n;
string ss[101], src;
string ssl[101], srcl;
int save[101], savel[101];
int f[101];
void calc_next(string t, int *next) {
  next[1] = 0;
  for (int i = 2, j = 0; i <= t.size(); ++i) {
    while (j > 0 && t[i - 1] != t[j])
      j = next[j];
    if (t[j - 1] == t[j])
      ++j;
    next[i] = j;
  }
}
int cmp(string d, string t, int *next) {
  memset(f, 0, sizeof(f));
  for (int i = 1, j = 0; i <= d.size(); ++i) {
    while (j > 0 && (j == t.size() || d[i - 1] != t[j]))
      j = next[j];
    if (d[i - 1] == t[j])
      ++j;
    f[i] = j;
    if (f[i] == t.size())
      return 1;
  }
  return 0;
}
int main() {
  cin >> src;
  cin >> op >> n;
  for (int i = 0; i < n; ++i) {
    cin >> ss[i];
    ssl[i] = ss[i];
    transform(ssl[i].begin(), ssl[i].end(), ssl[i].begin(), ::tolower);
  }
  srcl = src;
  transform(srcl.begin(), srcl.end(), srcl.begin(), ::tolower);
  calc_next(src, save);
  calc_next(srcl, savel);
  for (int i = 0; i < n; ++i) {
    if (!op) {
      if (cmp(ssl[i], srcl, savel))
        cout << ss[i] << endl;
    } else {
      if (cmp(ss[i], src, save))
        cout << ss[i] << endl;
    }
  }
  return 0;
}