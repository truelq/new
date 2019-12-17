#include <bits/stdc++.h>

// https://www.luogu.org/problem/P3740
// 贴海报
// 按照题目每次贴海报的时候均需要进行判断,但是如果逆向计算可以发现
// 所求可以看见的海报宽度必须按照逆序比对应位置的可见宽度宽
// 修改线段树计算方式,将sum字段的计算修改为=而非+=这样sum即可表示宽度
// 线段树传入的k参数只能是1
struct Node {
  int l, r;
  long long sum;
  long long inc;

  int mid() { return (l + r) >> 1; }
};
struct Tree {
  Node tree[400004]; // 4n
  int root = 1;
  int end;
  void buildtree(int root, int l, int r, long long *ss) {
    this->tree[root].l = l;
    this->tree[root].r = r;
    if (l == r) {
      tree[root].sum = ss[l];
      return;
    }
    buildtree(root << 1, l, tree[root].mid(), ss);
    buildtree((root << 1) + 1, tree[root].mid() + 1, r, ss);
    tree[root].sum = tree[root << 1].sum + tree[(root << 1) + 1].sum;
  }
  void update(int root, int l, int r, long long k) {
    if (l == tree[root].l && r == tree[root].r) {
      this->tree[root].sum = (r - l + 1) * k; //只要是1就可以了
      this->tree[root].inc |= k;
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
    this->tree[root].sum = tree[root << 1].sum + tree[(root << 1) + 1].sum;
  }
  long long query(int root, int l, int r) {
    if (l == tree[root].l && r == tree[root].r) {
      return tree[root].sum;
    }
    down(root);
    long long ans = 0;
    if (l > tree[root].mid()) {
      ans = query((root << 1) + 1, l, r);
    } else if (r <= tree[root].mid()) {
      ans = query((root << 1), l, r);
    } else {
      ans = query(root << 1, l, tree[root].mid()) +
            query((root << 1) + 1, tree[root].mid() + 1, r);
    }
    return ans;
  }
  void down(int root) {
    if (tree[root].inc) {
      update(root << 1, tree[root << 1].l, tree[root << 1].r, tree[root].inc);
      update((root << 1) + 1, tree[(root << 1) + 1].l, tree[(root << 1) + 1].r,
             tree[root].inc);

      // tree[root].inc = 0;
    }
  }
} tree;
struct P3740 {
  int x;
  int y;
};
bool operator<(P3740 &a, P3740 &b) { return a.x < b.x; }
using namespace std;

P3740 ss[1001];
P3740 save[2002];
// long long state[2002];
long long states[4001];
map<int, int> state;
int main() {
  int n, m;
  cin >> n >> m;
  int count = 1;
  for (int i = 1; i <= m; ++i) {
    scanf("%d %d", &ss[i].x, &ss[i].y);
    save[count].x = ss[i].x;
    save[count].y = count;
    count++;
    save[count].x = ss[i].y;
    save[count].y = count;
    count++;
  }
  tree.end = 4000;
  tree.buildtree(1, 1, 4000, states);
  sort(save + 1, save + count);
  int statecount = 1;
  //离散化
  for (int i = 1; i < count; ++i) {
    state[save[i].y] = statecount;
    if (i + 1 < count) {
      if (save[i].x + 1 < save[i + 1].x) {
        statecount += 2;
      } else if (save[i].x < save[i + 1].x) {
        statecount += 1;
      }
    }
  }

  int ans = 0;
  for (int i = m; i; --i) {
    if (state[i << 1] - state[(i << 1) - 1] + 1 >
        tree.query(1, state[(i << 1) - 1], state[i << 1])) {
      ans += 1;
    }
    tree.update(1, state[(i << 1) - 1], state[i << 1], 1);
  }
  cout << ans << endl;
  return 0;
}