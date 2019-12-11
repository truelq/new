#include <bits/stdc++.h>

using namespace std;

char ss[100002];
char sss[100002];
int nextsss[100002];
int ans[100002];
int n, m;
void calc_next() {
  nextsss[1] = 0;
  for (int i = 2, j = 0; i <= m; ++i) {
    while (j > 0 && sss[i] != sss[j + 1])
      j = nextsss[j];
    if (sss[i] == sss[j + 1])
      j++;
    nextsss[i] = j;
  }
}
int main() {
  scanf("%s", ss + 1);
  scanf("%s", sss + 1);
  n = strlen(ss + 1);
  m = strlen(sss + 1);

  calc_next();

  for (int i = 1; i <= n; ++i) {
    for (int j = i, k = 1; j <= n; ++j) {
      if(ss[j]==sss[k]){
          ans[i]=k;
          ++k;
      }else break;
    }
  }
  printf("%d ", m);
  for (int i = 2; i <= m; ++i) {
    printf("%d ", nextsss[i]);
  }
  cout<<endl;
  for(int i=1;i<=n;++i){
      printf("%d ",ans[i]);
  }
}