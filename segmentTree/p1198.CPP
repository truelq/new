#include <bits/stdc++.h>

using namespace std;
#include <bits/stdc++.h>
// https://www.luogu.org/problem/P1198
// 线段树基础
struct Node {
  int l, r;
  long long m;
  long long inc;

  int mid() { return (l + r) >> 1; }
};
struct Tree {        //只包含一个区间和数据项
  Node tree[800004]; // 4n
  int root = 1;
  int end;
  void buildtree(int root, int l, int r, long long *ss) {
    this->tree[root].l = l;
    this->tree[root].r = r;
    if (l == r) {
      tree[root].m = ss[l];
      return;
    }
    buildtree(root << 1, l, tree[root].mid(), ss);
    buildtree((root << 1) + 1, tree[root].mid() + 1, r, ss);
    tree[root].m = max(tree[root << 1].m, tree[(root << 1) + 1].m);
  }
  void update(int root, int l, int r, long long k) {
    if (l == tree[root].l && r == tree[root].r) {
      this->tree[root].m += (r - l + 1) * k;
      this->tree[root].inc += k;
      return;
    }
    down(root);
    if (l > this->tree[root].mid()) {
      update((root << 1) + 1, l, r, k);
    } else if (r <= this->tree[root].mid()) {
      update(root << 1, l, r, k);
    } else {
      update(root << 1, l, this->tree[root].mid(), k);
      update((root << 1) + 1, this->tree[root].mid() + 1, r, k);
    }
    this->tree[root].m = max(tree[root << 1].m , tree[(root << 1) + 1].m);
  }
  long long query(int root, int l, int r) {
    if (l == tree[root].l && r == tree[root].r) {
      return tree[root].m;
    }
    down(root);
    long long ans = 0;
    if (l > tree[root].mid()) {
      ans = query((root << 1) + 1, l, r);
    } else if (r <= tree[root].mid()) {
      ans = query((root << 1), l, r);
    } else {
      ans = max(query(root << 1, l, tree[root].mid()) ,
            query((root << 1) + 1, tree[root].mid() + 1, r));
    }
    return ans;
  }
  void down(int root) {
    if (tree[root].inc) {
      update(root << 1, tree[root << 1].l, tree[root << 1].r, tree[root].inc);
      update((root << 1) + 1, tree[(root << 1) + 1].l, tree[(root << 1) + 1].r,
             tree[root].inc);

      tree[root].inc = 0;
    }
  }
} tree;

long long ss[200001];

int main() {
  int m, d;
  cin >> m >> d;
  tree.end = m;
  tree.buildtree(1, 1, m, ss);
  long long t = 0;
  int count = 0;
  char a;
  long long b;
  for (int i = 0; i < m; ++i) {
    scanf(" %c %lld", &a, &b);
    if (a == 'A') {
      b = b + t;
      b %= d;
      count += 1;
      tree.update(1, count, count, b);
    } else {
      t = tree.query(1, count - b + 1, count);
      printf("%lld\n", t);
    }
  }
  return 0;
}