#include <bits/stdc++.h>
#include<unordered_map>
//离散化
using namespace std;
struct Node {
  int l, r;
  long long sum;
  long long inc;

  int mid() { return (l + r) >> 1; }
};
struct Tree {         //只包含一个区间和数据项
  Node tree[4000004]; // 4n
  int root = 1;
  int end;
  void buildtree(int root, int l, int r) {
    this->tree[root].l = l;
    this->tree[root].r = r;
    if (l == r) {
      tree[root].sum = 0;
      return;
    }
    buildtree(root << 1, l, tree[root].mid());
    buildtree((root << 1) + 1, tree[root].mid() + 1, r);
    tree[root].sum = 0;
  }
  void update(int root, int l, int r, long long k) {
    if (l == tree[root].l && r == tree[root].r) {
      this->tree[root].sum += (r - l + 1) * k;
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

      tree[root].inc = 0;
    }
  }
} tree;

struct P4939 {
  int a, b, c;
};
P4939 ss[400001];
long long save[1000001];
int main() {
  int n, m;
  cin >> n >> m;
  // for(int i=1;i<=n;++i){
  //    scanf("%d",ss+i);
  //}
  int a, b, c;
  int count = 0;
  unordered_map<int, int> state;
  for (int i = 0; i < m; ++i) {
    scanf("%d", &ss[i].a);
    save[count++] = ss[i].a;
    if (ss[i].a) {
      scanf("%d", &ss[i].b);
      save[count++] = ss[i].b;
    } else {
      scanf("%d %d", &ss[i].b, &ss[i].c);
      save[count++] = ss[i].b;
      save[count++] = ss[i].c;
    }
  }
  tree.end=count;
  tree.buildtree(1, 1, count);

  sort(save, save + count);
  for (int i = 0; i < count; ++i) {
    state[save[i]] = i;
  }
  for (int i = 0; i < m; ++i) {
    if (ss[i].a) {
      printf("%lld\n", tree.query(1, state[ss[i].b], state[ss[i].b]));
    } else {
      tree.update(1, state[ss[i].b], state[ss[i].c], 1);
    }
  }
  return 0;
}