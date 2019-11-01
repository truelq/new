#include<bits/stdc++.h>
//https://www.luogu.org/problem/P3865
//最大值
using namespace std;

struct Node {
  int l, r;
  long long maxs;
  long long inc;

  int mid() { return (l + r) >> 1; }
};
struct Tree {//只包含一个区间和数据项
  Node tree[400004];//4n
  int root = 1;
  int end;
  void buildtree(int root, int l, int r, long long *ss) {
    this->tree[root].l = l;
    this->tree[root].r = r;
    if (l == r) {
      tree[root].maxs = ss[l];
      return;
    }
    buildtree(root << 1, l, tree[root].mid(), ss);
    buildtree((root << 1) + 1, tree[root].mid() + 1, r, ss);
    tree[root].maxs = max(tree[root << 1].maxs , tree[(root << 1) + 1].maxs);
  }
  void update(int root, int l, int r, long long k) {
    if (l == tree[root].l && r == tree[root].r) {
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
    this->tree[root].maxs = max(tree[root << 1].maxs, tree[(root << 1) + 1].maxs);
  }
  long long query(int root, int l, int r) {
    if (l == tree[root].l && r == tree[root].r) {
      return tree[root].maxs;
    }
    //down(root);
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
long long ss[100001];
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        scanf("%d",ss+i);
    }
    tree.end=n;
    tree.buildtree(1,1,n,ss);
    int a,b;
    for(int i=0;i<m;++i){
        scanf("%d %d",&a,&b);
        printf("%d\n",tree.query(1,a,b));
    }
    return 0;
}