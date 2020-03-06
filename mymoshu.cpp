#include <algorithm>
#include <cstdio>
#include <cstring>
#include <ctime>
using namespace std;
#define MAXN 1000100
#define ull unsigned long long
ull M = 2009731336725594113; // f(x)的大模
//数组u保存群的所有元素，前面u[0]-u[4]为题目给定，u[31]=1
ull u[32] = {314882150829468584, 427197303358170108, 1022292690726729920,
             1698479428772363217, 2006101093849356424};
int com[32][32]; // u[i]*u[j]=u[com[i][j]],com[i][j]记录群之间的转换关系
int n, q, new_size; // new_size记录所有询问的l,r的个数，是离散化用的
ull A[32];          //临时变量，记录i*u[j]%M
ull ss[MAXN];
ull state[MAXN];
ull precalc
    [32]
    [MAXN]; // f(x)前缀和,presum[i][j],表示若所有元素都是乘以u[j]的时候，f(1)+f(2)+...f(i)的值
void preInit() {
  for (int i = 0; i < 32; ++i) {
    for (int j = 1; j <= n; ++j) {
      precalc[i][j] = u[i] + precalc[i][j - 1];
      if (precalc[i][j] >= M)
        precalc[i][j] -= M;
    }
  }
}
inline ull
MOD(ull a,
    ull b) //模重复平方法实现a*b(modM)，不一定快，但是只在计算群元素的时候用
{
  if (a > b)
    return MOD(b, a);
  ull res = 0;
  while (a) {
    if (a & 1) {
      res = res + b;
      if (res >= M)
        res -= M;
    }
    b <<= 1;
    if (b >= M)
      b -= M;
    a >>= 1;
  }
  return res;
}

struct Node {
  int l, r;
  long long sum;
  long long inc;
  int state;
  int mid() { return (l + r) >> 1; }
};
struct Tree {        //只包含一个区间和数据项
  Node tree[MAXN*4]; // 4n
  int root = 1;
  int end;
  void buildtree(int root, int l, int r, unsigned long long *ss) {
    this->tree[root].l = l;
    this->tree[root].r = r;
    this->tree[root].state = 31;
    if (l == r) {
      tree[root].sum = ss[l];
      return;
    }
    buildtree(root << 1, l, tree[root].mid(), ss);
    buildtree((root << 1) + 1, tree[root].mid() + 1, r, ss);
    // tree[root].sum = tree[root << 1].sum + tree[(root << 1) + 1].sum;
  }
  void update(int root, int l, int r, long long k) {
    if (l == tree[root].l && r == tree[root].r) {
      // this->tree[root].sum += (r - l + 1) * k;
      this->tree[root].inc = 1;
      this->tree[root].state = com[tree[root].state][k];
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
    // this->tree[root].sum = tree[root << 1].sum + tree[(root << 1) + 1].sum;
  }
  unsigned long long query(int root, int l, int r) {
    if (l == r && l == tree[root].l && r == tree[root].r) {
      return precalc[tree[root].state][tree[root].sum] % 2019;
    }
    down(root);
    unsigned long long ans = 0;
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
      update(root << 1, tree[root << 1].l, tree[root << 1].r, tree[root].state);
      update((root << 1) + 1, tree[(root << 1) + 1].l, tree[(root << 1) + 1].r,
             tree[root].state);
      tree[root].state = 31;
      tree[root].inc = 0;
    }
  }
} tree;

int main() {
  // freopen("C:\\Users\\32125\\Documents\\vscodec\\in.txt", "r", stdin);
  // freopen("C:\\Users\\32125\\Documents\\vscodec\\out.txt","w",stdout);
  int l, r;
  scanf("%d%d", &n, &q);
  int h = 5;
  u[31] = 1;
  for (int i = 0; i < 32; i++) //计算子群，32个元素
    for (int j = 0; j < h; j++) {
      ull a = MOD(u[i], u[j]);
      int pos = find(u, u + 32, a) - u;
      if (pos == 32) {
        u[h] = a;
        com[i][j] = com[j][i] = h;
        h++;
      } else
        com[i][j] = com[j][i] = pos;
    }
  preInit(); //计算前缀和
  for (int i = 1; i <= n; ++i) {
    ss[i] = i;
    state[i] = 31;
  }
  tree.end = n;
  tree.buildtree(1, 1, n, ss);
  for (int i = 0; i < q; ++i) {
    scanf("%d%d", &l, &r);
    ull ans = 0;
    // for (int i = l; i <= r; ++i) {
    //  ans += precalc[state[i]][i] % 2019;
    //}
    ans = tree.query(1, l, r);
    printf("%llu\n", ans);
    int t = ans % 5;
    // for (int i = l; i <= r; ++i) {
    //  state[i] = com[state[i]][t];
    //}
    tree.update(1, l, r, t);
  }
  // printf("new_size=%d,time=%lld\n",new_size,clock()-t1);
  // return 0;
  return 0;
}
