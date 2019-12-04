#include <bits/stdc++.h>
#define PI 3.1415926535
using namespace std;
struct dfs1 {
  int x;
  int y;
};

int x[2], y[2];
double maxans;
vector<dfs1> points;
double r[100];
int visit[100];
double calc(int t) {
  double x1 = min(abs(points[t].x - x[0]), abs(points[t].x - x[1]));
  double y1 = min(abs(points[t].y - y[0]), abs(points[t].y - y[1]));
  double temp = min(x1, y1);
  for (int i = 0; i < points.size(); ++i) {
    if (visit[i] && i != t) {
      double d =
          sqrt((points[i].x - points[t].x) * (points[i].x - points[t].x) +
               (points[i].y - points[t].y) * (points[i].y - points[t].y));
      temp = min(temp, max(d - r[i], 0.0));
    }
  }
  return temp;
}
void dfs(int k, double sum) {
  if (k >= points.size()) {
    maxans = max(maxans, sum);
    return;
  }
  for (int i = 0; i < points.size(); ++i) {
    if (!visit[i]) {
      r[i] = calc(i);
      visit[i] = 1;
      dfs(k + 1, sum + PI * r[i] * r[i]);
      visit[i] = 0;
    }
  }
}
int main() {
  int n;
  int a, b;
  cin >> n;
  cin >> x[0] >> y[0] >> x[1] >> y[1];
  for (int i = 0; i < n; ++i) {
    scanf("%d%d", &a, &b);
    points.push_back({a, b});
  }
  dfs(0, 0);
  printf("%0.0f\n", (abs(x[0] - x[1]) * abs(y[0] - y[1])) - maxans);
  return 0;
}