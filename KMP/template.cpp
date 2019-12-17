#include <bits/stdc++.h>

using namespace std;
char def[2000002];
char base[2000002];
int def_len;
int base_len;
int netx[2000002];
int f[2000002];
int main() {
  scanf("%s", def );
  scanf("%s", base );
  def_len = strlen(def );
  base_len = strlen(base);
  strcat(base, "#");
  strcat(base, def);

  for (int i = 1, mx = 0, l = 0; base[i]; ++i) {
    netx[i] = i < mx ? min(mx - i, netx[i - l]) : 0;
    while (base[netx[i]] == base[i + netx[i]])
      netx[i]++;
    if (i + netx[i] > mx)
      mx = i + netx[i], l = i;
  }
  for (int i = 0; i < base_len; ++i)
    printf("%d ", netx[i]);
  cout << endl;
  for (int i = base_len+1 ; base[i]; ++i)
    printf("%d ", netx[i]);
}