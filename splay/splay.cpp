#include <cstdio>
#include <iostream>
using namespace std;
const int mm = 100050;
const int INF = 0x7f7f7f7f;
struct node {
  int fa; //���ڵ�
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
  { T[x].sz = T[T[x].son[0]].sz + T[T[x].son[1]].sz + 1; } // 1��ʾ�Լ�
#define keyvalue T[T[root].son[1]].son[0]
void updrev(int x) //�����˱��������X�ڵ㣬update
{
  if (!x)
    return;
  swap(T[x].son[0], T[x].son[1]);
  T[x].revtag ^= 1; //���������Ϊֹ
}
void pushdown(int x) //���´������˱��
{
  if (T[x].revtag) //�����˱�ǣ���ʾx���ӽڵ��Ѿ�����������x���ӽڵ㻹û��
  {
    updrev(T[x].son[0]);
    updrev(T[x].son[1]);
    T[x].revtag = 0; //�´���ȥ��x�����˱��
  }
}
void rotate(int x) //������
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
void splay(int x, int goal) //���ڵ�x����goal���ӽڵ�
{
  int fa = T[x].fa;
  while (fa != goal) {
    if (T[fa].fa !=
        goal) //��T[fa].fa==goalʱ��ֻ��Ҫ��һ�ξ͵�goal���ˣ�������һ���Ͳ���Ҫ����
      rotate(get(x) == get(fa) ? fa : x);
    rotate(x);
    fa = T[x].fa;
  }
  if (goal ==
      0) // 0��������ĵ�0��Ԫ�أ�������ʶroot����T[x].fa==0,��ô�ͱ�ʾx��root��
    root =
        x; // root�����������ĸ�
           // ����Ϊ����Ҫ�õ�root������������ԣ�x��root��λ�ú�Ҫ��root��Ϊx
}
int getkth(int x, int k) //���ַ�����xΪ���������в��ҵ�k��Ԫ��
{
  pushdown(x);
  int tt = T[T[x].son[0]].sz +
           1; //�������ڵ���+1����ʾx�� ��xΪ���������е�λ�ã���Ŵ�1��ʼ
  if (tt == k)
    return x;
  if (tt > k)
    return getkth(T[x].son[0], k);
  if (tt < k)
    return getkth(
        T[x].son[1],
        k - tt); //ע���������ı�Ż��Ǵ�1��ʼ�ģ�����ֻ��Ҫ��k-tt�ˣ�ǰtt�����������͸�
}
int newnode(
    int fa, int v,
    int which) //��fa�ڵ��which(������)λ�ô���ֵΪv���ӽڵ㣬�����ظ��ӽڵ�
{
  int x =
      ++tot; //ע��������洢��ʽ��tot��ʾ�������Ѿ������Ľڵ������ע��0��λ�ñ���
  T[x].fa = fa;
  T[x].son[0] = T[x].son[1] = 0;
  T[x].revtag = 0;
  T[x].val = v;
  T[x].sz = 1;
  if (fa != 0) // 0��λ�õĶ��Ӳ���Ҫ��������
    T[fa].son[which] = x;
  return x;
}

int build(int fa, int l, int r,
          int which) //���ַ�������ת����splay�� ��������ƽ��
//ÿ����fa��������һ���ڵ㣬����ڵ����������е�
{
  if (l > r)
    return 0;
  int mid = (l + r) / 2;
  int x = newnode(fa, a[mid], which);
  build(x, l, mid - 1, 0);
  build(x, mid + 1, r, 1);
  update(x); //���Ҷ������x��sz�ͻᷢ���ı䣬����Ҫ�޸ģ�Ҫ�ŵ�����build֮��
  return x;
}
void Init() {
  tot = 0;
  root = newnode(
      0, -1, 0); //��0�½�һ��ֵΪ-1�Ľڵ㣬��ʱ��root ///////////0/////////////
  int x = newnode(root, -1,
                  1); //��root�½�һ��ֵΪ-1���Ҷ��� ///////////|/////////////
  for (int i = 0; i < n; i++) //ԭʼ���� ///////////root(-1)//���ڱ�
    a[i] = i + 1;             ///////////////\//////////
  build(x, 0, n - 1,
        0); //��x������ӽ��������� /////////////////son[1](-1)x//���ڱ�
  update(T[root].son[1]); //\\\\\\\\\\\\\\\\/\\\\\\\\\\\\\\
    update(root);                                                   /////////Key_value(����)/////////
}
void addrevtag(int l, int r) //��ת��������[l,r] ����Ŵ�1��ʼ
{
  int gl = getkth(
      root,
      l); //���еĵ�l��Ԫ�أ�ʵ�����������еĵ�l-1��Ԫ�أ���Ϊ����һ�����ڱ���
  // cout<<gl<<endl;
  int gr = getkth(root, r + 2); //ʵ���ǵ�r+1��Ԫ��
  // cout<<gr<<endl;
  splay(gl, 0); //��l-1����root
  // cout<<"ok"<<endl;
  splay(gr, root); //��r+1����root���Ҷ���
  // cout<<"ok"<<endl;
  updrev(
      keyvalue); //��ôKey_value��λ�þ������䡾l,r��,����ת���˱��������Key_value��
  update(T[root].son[1]); //����˴���ʵɶҲû��
  update(root);           //����˴���ʵɶҲû��
}
void dfs(int x) //�������
{
  pushdown(x);
  if (x == 0)
    return;
  dfs(T[x].son[0]);
  if (x != 0 && T[x].val != -1)
    printf("%d ", T[x].val);
  dfs(T[x].son[1]);
}
int main() {
  scanf("%d%d", &n, &m);
  Init();
  for (int i = 1; i <= m; i++) {
    int l, r;
    scanf("%d%d", &l, &r);
    addrevtag(l, r);
  }
  dfs(root);
  return 0;
}
