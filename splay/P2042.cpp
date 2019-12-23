#include <cstdio>
#include <iostream>
using namespace std;
const int mm = 100050;
const int INF = 0x7f7f7f7f;
struct node {
  int fa; //父节点
  int son[2];
  int sz;
  int val;
  int revtag;
} T[mm];
int root;
int tot;
int a[mm];
int n, m;
#define get(x) (T[T[x].fa].son[1] == x)
#define update(x)                                                              \
  { T[x].sz = T[T[x].son[0]].sz + T[T[x].son[1]].sz + 1; } // 1表示自己
#define keyvalue T[T[root].son[1]].son[0]
void updrev(int x) //将懒人标记作用在X节点，update
{
  if (!x)
    return;
  swap(T[x].son[0], T[x].son[1]);
  T[x].revtag ^= 1; //标记做到此为止
}
void pushdown(int x) //向下传递懒人标记
{
  if (T[x].revtag) //有懒人标记，表示x的子节点已经交换，但是x的子节点还没有
  {
    updrev(T[x].son[0]);
    updrev(T[x].son[1]);
    T[x].revtag = 0; //下传后，去掉x的懒人标记
  }
}
void rotate(int x) //左右旋
{
  int which = get(x);
  int y = T[x].fa;
  int z = T[y].fa;
  pushdown(y);
  pushdown(x);
  T[y].son[which] = T[x].son[which ^ 1];
  T[T[y].son[which]].fa = y;
  T[x].son[which ^ 1] = y;
  T[y].fa = x;
  T[x].fa = z;
  if (z != 0) {
    T[z].son[T[z].son[1] == y] = x;
  }
  update(y);
  update(x);
}
void splay(int x, int goal) //将节点x旋成goal的子节点
{
  int fa = T[x].fa;
  while (fa != goal) {
    if (T[fa].fa !=goal) //当T[fa].fa==goal时，只需要旋一次就到goal下了，所以下一步就不必要做了
      rotate(get(x) == get(fa) ? fa : x);
    rotate(x);
    fa = T[x].fa;
  }
  if (goal ==0) // 0方在数组的第0个元素，用来标识root，即T[x].fa==0,那么就表示x是root了
    root =x; // root才是整颗树的根，因为后面要用到root这个变量，所以，x到root的位置后，要将root改为x
}
int getkth(int x, int k) //二分法在以x为根的子树中查找第k个元素
{
  pushdown(x);
  int tt = T[T[x].son[0]].sz +1; //左子树节点数+1，表示x在 以x为根的子树中的位置，编号从1开始
  if (tt == k)
    return x;
  if (tt > k)
    return getkth(T[x].son[0], k);
  if (tt < k)
    return getkth(T[x].son[1],k - tt); //注意右子树的编号还是从1开始的，所以只需要找k-tt了，前tt个是左子树和根
}
int newnode(int fa, int v,int which) //在fa节点的which(左还是右)位置创建值为v的子节点，并返回该子节点
{
  int x =++tot; //注意是数组存储方式，tot表示数组中已经创建的节点个数，注意0号位置保留
  T[x].fa = fa;
  T[x].son[0] = T[x].son[1] = 0;
  T[x].revtag = 0;
  T[x].val = v;
  T[x].sz = 1;
  if (fa != 0) // 0号位置的儿子不需要区分左右
    T[fa].son[which] = x;
  return x;
}

int build(int fa, int l, int r,
          int which) //二分法将序列转化成splay树 ，这样最平衡
//每次在fa下面增加一个节点，这个节点就是区间的中点
{
  if (l > r)
    return 0;
  int mid = (l + r) / 2;
  int x = newnode(fa, a[mid], which);
  build(x, l, mid - 1, 0);
  build(x, mid + 1, r, 1);
  update(x); //左右都建完后，x的sz就会发生改变，所以要修改，要放到两个build之后
  return x;
}
void addrevtag(int l, int r) //反转序列区间[l,r] ，编号从1开始
{
  int gl = getkth(
      root,
      l); //树中的第l个元素，实际上是序列中的第l-1个元素（因为多了一个左哨兵）
  // cout<<gl<<endl;
  int gr = getkth(root, r + 2); //实际是第r+1个元素
  // cout<<gr<<endl;
  splay(gl, 0); //把l-1旋到root
  // cout<<"ok"<<endl;
  splay(gr, root); //把r+1旋到root的右儿子
  // cout<<"ok"<<endl;
  updrev(
      keyvalue); //那么Key_value的位置就是区间【l,r】,将翻转懒人标记作用在Key_value上
  update(T[root].son[1]); //本题此处其实啥也没做
  update(root);           //本题此处其实啥也没做
}
void dfs(int x) //中序遍历
{
  pushdown(x); //将所有的标记降到叶子节点
  if (x == 0)
    return;
  dfs(T[x].son[0]);
  if (x != 0 && T[x].val != -1)
    printf("%d ", T[x].val);
  dfs(T[x].son[1]);
}
int main() {
  scanf("%d%d", &n, &m);

  tot = 0;
  root = newnode(0, -1, 0);     //左哨兵
  int x = newnode(root, -1, 1); //右哨兵
  for (int i = 1; i <= n; ++i) {
    scanf("%d", a + i);
  }
  build(x, 0, n - 1, 0);
  update(T[root].son[1]);
  update(root);
  for (int i = 1; i <= m; i++) {
    int l, r;
    scanf("%d%d", &l, &r);
    addrevtag(l, r);
  }
  dfs(root);
  return 0;
}
