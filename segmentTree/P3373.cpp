#include <bits/stdc++.h>

// https://www.luogu.org/problem/P3373
// 线段树，多个操作

using namespace std;
struct Node {
  int l, r;
  long long sum;
  long long inc;
  long long times;
  int mid() { return (l + r) >> 1; }
};
struct Tree {
  Node tree[400004]; // 4n
  int root = 1;
  int end;
  void buildtree(int root, int l, int r, long long *ss, int p) {
    this->tree[root].l = l;
    this->tree[root].r = r;
    if (l == r) {
      tree[root].sum = ss[l];
      tree[root].times = 1;
      return;
    }
    buildtree(root << 1, l, tree[root].mid(), ss, p);
    buildtree((root << 1) + 1, tree[root].mid() + 1, r, ss, p);
    tree[root].sum = (tree[root << 1].sum + tree[(root << 1) + 1].sum) % p;
    tree[root].times = 1;
  }
  void update(int root, int l, int r, long long add, long long mul, int p) {
    if (l == tree[root].l && r == tree[root].r) {
      this->tree[root].sum =
          (this->tree[root].sum * mul + (r - l + 1) * add) % p;
      this->tree[root].inc = (this->tree[root].inc * mul + add) % p;
      this->tree[root].times = this->tree[root].times * mul % p;
      return;
    }
    down(root, p);
    if (l > this->tree[root].mid()) {
      update((root << 1) + 1, l, r, add, mul, p);
    } else if (r <= this->tree[root].mid()) {
      update(root << 1, l, r, add, mul, p);
    } else {
      update(root << 1, l, this->tree[root].mid(), add, mul, p);
      update((root << 1) + 1, this->tree[root].mid() + 1, r, add, mul, p);
    }
    this->tree[root].sum =
        (tree[root << 1].sum + tree[(root << 1) + 1].sum) % p;
  }
  long long query(int root, int l, int r, int p) {
    if (l == tree[root].l && r == tree[root].r) {
      return tree[root].sum;
    }
    down(root, p);
    long long ans = 0;
    if (l > tree[root].mid()) {
      ans = query((root << 1) + 1, l, r, p);
    } else if (r <= tree[root].mid()) {
      ans = query((root << 1), l, r, p);
    } else {
      ans = (query(root << 1, l, tree[root].mid(), p) +
             query((root << 1) + 1, tree[root].mid() + 1, r, p)) %
            p;
    }
    return ans;
  }
  void down(int root, int p) {
    if (tree[root].inc || tree[root].times != 1) { //!=1可能是0倍数
      update(root << 1, tree[root << 1].l, tree[root << 1].r, tree[root].inc,
             tree[root].times, p);
      update((root << 1) + 1, tree[(root << 1) + 1].l, tree[(root << 1) + 1].r,
             tree[root].inc, tree[root].times, p);

      tree[root].inc = 0;
      tree[root].times = 1;
    }
  }
} tree;

long long ss[100001];

int main() {
  int n, m, p;
  int a, b, c, d;
  cin >> n >> m >> p;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", ss + i);
  }
  tree.end = n;
  tree.buildtree(1, 1, n, ss, p);
  for (int i = 0; i < m; ++i) {
    scanf("%d", &a);
    if (a == 1) {
      scanf("%d %d %d", &b, &c, &d);
      tree.update(1, b, c, 0, d, p);
    } else if (a == 2) {
      scanf("%d %d %d", &b, &c, &d);
      tree.update(1, b, c, d, 1, p);
    } else if (a == 3) {
      scanf("%d %d", &b, &c);
      printf("%lld\n", tree.query(1, b, c, p));
    }
  }
  return 0;
}