#include <bits/stdc++.h>
//树状数组
using namespace std;
struct T111409 {
  int a;
  int b;
  int c;
} all[1000001];
int save[1000001];
int main() {
  int n;
  cin >> n;
  int cur = 0;
  if (getchar() != '\n')
    getchar();
  char c;
  int a, b, d;
  for (int i = 1; i <= n; ++i) {
    c = getchar();
    if (c == 'A') {
      scanf("%d%d%d", &a, &b, &d);
      all[++cur] = {a, b, d};
      save[cur] = 1;
    } else if (c == 'Q') {
      scanf("%d", &a);
      int ans = 0;
      for (int i = 1; i <= cur; ++i) {
        if (save[i] && all[i].a * a * a + all[i].b * a + all[i].c > 0) {
          ans++;
        }
      }
      printf("%d\n",ans);
    } else if (c == 'D') {
      scanf("%d", &a);
      int temp = 0;
      int tempb = 0;
      for (tempb = 1; tempb <= cur; ++tempb) {
        temp += save[tempb];
        if (temp == a)
          break;
      }
      save[tempb] = 0;
    }
    if (getchar() != '\n')
      getchar();
  }
  return 0;
}