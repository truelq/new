#include<bits/stdc++.h>

using namespace std;

struct Node {
  int l, r;
  long long sum;
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
      tree[root].sum = ss[l];
      return;
    }
    buildtree(root << 1, l, tree[root].mid(), ss);
    buildtree((root << 1) + 1, tree[root].mid() + 1, r, ss);
    tree[root].sum = tree[root << 1].sum + tree[(root << 1) + 1].sum;
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
long long ss[100001];
int main(){
  int n,m;
  int a,b,c,d;
  cin>>n>>m;
  for(int i=1;i<=n;++i){
    scanf("%d",ss+i);
  }
  tree.end=n;
  tree.buildtree(1,1,n,ss);
  for(int i=0;i<m;++i){
    scanf("%d",&a);
    if(a==1){
      scanf("%d %d %d",&b,&c,&d);
      for(int i=b;i<=c;++i){
        if(ss[i]&&ss[i]!=1&&ss[i]%d==0){
          int temp=ss[i]/d;
          tree.update(1,i,i,temp-ss[i]);
          ss[i]=temp;
        }
      }
    }else{
      scanf("%d %d",&b,&c);
      printf("%d\n",tree.query(1,b,c));
    }
  }
}