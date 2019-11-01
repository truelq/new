#include<bits/stdc++.h>
// 贪心
//https://www.luogu.org/problem/P3078
using namespace std;
struct Node {
  int l, r;
  long long sum;
  long long inc;

  int mid() { return (l + r) >> 1; }
};
struct Tree {
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
long long ss[100000];
int main(){
    int n;
    long long ans=0;
    int temp;
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        scanf("%d",ss+i);
        temp=ss[i]-ss[i-1];
        if(temp>0)
        ans+=temp;
    }
    /*
    tree.end=n;
    tree.buildtree(1,1,n+1,ss);
    int start=1;
    int end=1;
    int mins;
    int temp;
    
    while(true){
        while(!tree.query(1,start,start)&&start<=n){
            start++;
        }
        if(start>n){
            break;
        }
        end=start;
        mins=0x7fffffff;
        while(temp=tree.query(1,end,end)){
            mins=min(temp,mins);
            ++end;
        }
        tree.update(1,start,end-1,-mins);
        ans+=mins;
    }
    */
    cout<<ans<<endl;
    return 0;
}