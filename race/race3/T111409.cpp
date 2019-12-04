#include <bits/stdc++.h>
//树状数组
using namespace std;
struct T111409 {
  int a;
  int b;
  int c;
} all[1000001];
int ss[2005];
int save[2005];
int savet[1000001];
int update(int *save, int i, int k, int n) {
  for (int j = i; j <= n; j += (j & -j)) {
    save[j] += k;
  }
}
int suma(int *save, int k) {
  int ans = 0;
  for (int i = k; i; i -= (i & -i)) {
    ans += save[i];
  }
  return ans;
}
int finda(int *save, int sum, int n) {
  int low = 1;
  int high = n;
  int mid = (low + high) >> 1;
  while (low <= high) {
    if (suma(save, mid) < sum) {
      low = mid + 1;
      mid = (low + high) >> 1;
    } else {
      high = mid - 1;
      mid = (low + high) >> 1;
    }
  }
  return low;
}
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
      savet[cur] = 1;
      // update(savet, cur, 1, 1000000);
      int t = b * b - 4 * a * d;
      if (a == 0) {
        if (b == 0) {
          if (d > 0) {
            update(save, 1, 1, 2001);
          }
        } else if (b > 0) {
          double x = -d / b;
          int temp = -d / b;
          if (temp * 1.0 <= x)
            temp += 1;
          if (temp >= -1000)
            update(save, temp + 1001, 1, 2001);
          else
            update(save, 1, 1, 2001);
        } else { // b<0
          double x = -d / b;
          int temp = -d / b;
          if (temp * 1.0 >= x)
            temp -= 1;
          if (temp >= -1000) {
            update(save, 1, 1, 2001);
            update(save, temp + 1 + 1001, -1, 2001);
          }
        }
      } else if (a > 0) {
        if (t < 0) {
          update(save, 1, 1, 2001);
        } else if (t == 0) {
          double x = -b / a / 2;
          int temp = -b / a / 2;
          if (temp * 1.0 == x) {
            if (temp < -1000)
              update(save, 1, 1, 2001);
            else {
              update(save, 1, 1, 2001);
              update(save, temp + 1001, -1, 2001);
              update(save, temp + 1002, 1, 2001);
            }
          } else {
            update(save, 1, 1, 2001);
          }
        } else if (t > 0) { //两边的部分
          double x1 = (-b - sqrt(t)) / a / 2;
          double x2 = (-b + sqrt(t)) / a / 2;
          int xx1 = (-b - sqrt(t)) / a / 2;
          int xx2 = (-b + sqrt(t)) / a / 2;
          if (xx1 * 1.0 >= x1)
            xx1 -= 1;
          if (xx2 * 1.0 <= x2)
            xx2 += 1;
          if (xx1 >= -1000) {
            update(save, 1, 1, 2001);
            update(save, xx1 + 1001 + 1, -1, 2001);
          }
          if (xx2 <= 1000) {
            update(save, xx2 + 1001, 1, 2001);
          }
        }
      } else if (a < 0) {
        // t<0无解
        if (t == 0) {
          double x = -b / a / 2;
          int temp = -b / a / 2;
          if (temp * 1.0 == x) {
            //只有这一个点
            if (temp >= -1000) {
              update(save, temp + 1001, 1, 2001);
              update(save, temp + 1001 + 1, -1, 2001);
            }
          }
        } else if (t > 0) {
          double x1 = (-b - sqrt(t)) / a / 2;
          double x2 = (-b + sqrt(t)) / a / 2;
          int xx1 = (-b - sqrt(t)) / a / 2;
          int xx2 = (-b + sqrt(t)) / a / 2;
          if (xx1 * 1.0 <= x1)
            xx1 += 1;
          if (xx2 * 1.0 >= x2)
            xx2 -= 1;
          if (xx1 > 1000 || xx2 < -1000) {
            //啥也不做
          } else {
            if (xx1 >= -1000) {
              update(save, xx1 + 1001, 1, 2001);
            } else {
              update(save, 1, 1, 2001);
            }
            update(save, xx2 + 1002, -1, 2001);
          }
        }
      }
    } else if (c == 'Q') {
      scanf("%d", &a);
      printf("%d\n", suma(save, a + 1001));
    } else if (c == 'D') {
      scanf("%d", &a);
      //二分法定位
      // int temp = finda(savet, a, cur);
      // update(savet, temp, -1, 1000000);
      int temp = 0;
      int tempb = 0;
      for (tempb = 1; tempb <= cur; ++tempb) {
        temp += savet[tempb];
        if (temp == a)
          break;
      }
      savet[tempb] = 0;
      //维护save树状数组,这情况也太多了吧
      a = all[tempb].a;
      b = all[tempb].b;
      d = all[tempb].c;
      int t = b * b - 4 * a * d;
      if (a == 0) {
        if (b == 0) {
          if (d > 0) {
            update(save, 1, -1, 2001);
          }
        } else if (b > 0) {
          double x = -d / b;
          int temp = -d / b;
          if (temp * 1.0 <= x)
            temp += 1;
          if (temp >= -1000)
            update(save, temp + 1001, -1, 2001);
          else
            update(save, 1, -1, 2001);
        } else { // b<0
          double x = -d / b;
          int temp = -d / b;
          if (temp * 1.0 >= x)
            temp -= 1;
          if (temp >= -1000) {
            update(save, 1, -1, 2001);
            update(save, temp + 1 + 1001, 1, 2001);
          }
        }
      } else if (a > 0) {
        if (t < 0) {
          update(save, 1, -1, 2001);
        } else if (t == 0) {
          double x = -b / a / 2;
          int temp = -b / a / 2;
          if (temp * 1.0 == x) {
            if (temp < -1000)
              update(save, 1, -1, 2001);
            else {
              update(save, 1, -1, 2001);
              update(save, temp + 1001, 1, 2001);
              update(save, temp + 1002, -1, 2001);
            }
          } else {
            update(save, 1, -1, 2001);
          }
        } else if (t > 0) { //两边的部分
          double x1 = (-b - sqrt(t)) / a / 2;
          double x2 = (-b + sqrt(t)) / a / 2;
          int xx1 = (-b - sqrt(t)) / a / 2;
          int xx2 = (-b + sqrt(t)) / a / 2;
          if (xx1 * 1.0 >= x1)
            xx1 -= 1;
          if (xx2 * 1.0 <= x2)
            xx2 += 1;
          if (xx1 >= -1000) {
            update(save, 1, -1, 2001);
            update(save, xx1 + 1001 + 1, 1, 2001);
          }
          if (xx2 <= 1000) {
            update(save, xx2 + 1001, -1, 2001);
          }
        }
      } else if (a < 0) {
        // t<0无解
        if (t == 0) {
          double x = -b / a / 2;
          int temp = -b / a / 2;
          if (temp * 1.0 == x) {
            //只有这一个点
            if (temp >= -1000) {
              update(save, temp + 1001, -1, 2001);
              update(save, temp + 1001 + 1, 1, 2001);
            }
          }
        } else if (t > 0) {
          double x1 = (-b - sqrt(t)) / a / 2;
          double x2 = (-b + sqrt(t)) / a / 2;
          int xx1 = (-b - sqrt(t)) / a / 2;
          int xx2 = (-b + sqrt(t)) / a / 2;
          if (xx1 * 1.0 <= x1)
            xx1 += 1;
          if (xx2 * 1.0 >= x2)
            xx2 -= 1;
          if (xx1 > 1000 || xx2 < -1000) {
            //啥也不做
          } else {
            if (xx1 >= -1000) {
              update(save, xx1 + 1001, -1, 2001);
            } else {
              update(save, 1, -1, 2001);
            }
            update(save, xx2 + 1002, 1, 2001);
          }
        }
      }
    }
    if (getchar() != '\n')
      getchar();
  }
  return 0;
}