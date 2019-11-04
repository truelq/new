#include <bits/stdc++.h>

using namespace std;
int save[1000001];
int top;
bool state[1000001], low[1000001];
int main() {
  int l, r;
  memset(low,1,sizeof(low));
  for (int i = 2; i <= 0xffff; ++i) {
    if (low[i]) {
      save[++top] = i;
    }
    for (int j = 1; j <= top && i * save[j] <= 0x10000; ++j) {
      low[i * save[j]] = 0;
      if (i % save[j] == 0) {
        break;
      }
    }
  }
  while (scanf("%d %d", &l, &r)!=EOF) {
    memset(state, 1, sizeof(state));

    for(int i=1;i<=top;++i){
      for(int j=l/save[i];j<=r/save[i];++j){

      }
    }
  }
}