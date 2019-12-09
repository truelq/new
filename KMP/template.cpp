#include <bits/stdc++.h>

using namespace std;
char def[1000001];
char base[1000001];
int def_len;
int base_len;
int netx[1000001];
int f[1000001];
void calc_netx() {
  netx[1] = 0;
  for (int i = 2, j = 0; i <= base_len; ++i) {
    while (j > 0 && base[i] != base[j + 1])
      j = netx[j];
    if (base[i] == base[j + 1])
      ++j;
    netx[i] = j;
  }
}
void kmp() {
  for (int i = 1, j = 0; i <= def_len; ++i) {
    while (j > 0 && (j == base_len || def[i] != base[j + 1]))
      j = netx[j];
    if (def[i] == base[j + 1])
      ++j;
    f[i] = j;
    if (f[i] == base_len) {
      printf("%d\n", i + 1 - base_len);
    }
  }
}
int main() {
  scanf("%s", def + 1);
  scanf("%s", base + 1);
  def_len = strlen(def + 1);
  base_len = strlen(base + 1);
  calc_netx();
  kmp();
  for (int i = 1; i <= base_len; ++i) {
    printf("%d ", netx[i]);
  }
}