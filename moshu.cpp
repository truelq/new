#include<cstdio>
#include<cstring>
#include<ctime>
#include<algorithm>
using namespace std;
#define MAXN 1000100
#define ull unsigned long long 
ull M=2009731336725594113;//f(x)的大模
//数组u保存群的所有元素，前面u[0]-u[4]为题目给定，u[31]=1 
ull u[32]={314882150829468584,427197303358170108,1022292690726729920,1698479428772363217,2006101093849356424};
int com[32][32];//u[i]*u[j]=u[com[i][j]],com[i][j]记录群之间的转换关系 
int n,q,new_size;//new_size记录所有询问的l,r的个数，是离散化用的 
ull A[32];//临时变量，记录i*u[j]%M 
int presum[MAXN][32];//f(x)前缀和,presum[i][j],表示若所有元素都是乘以u[j]的时候，f(1)+f(2)+...f(i)的值 
void preInit()
{
	for(int i=1;i<=n;i++)
	for(int j=0;j<32;j++)
	{
		A[j]+=u[j];//计算i*u[j]
		if(A[j]>=M)A[j]-=M;//计算i*u[j]%M 
		presum[i][j]=presum[i-1][j]+A[j]%2019;//A[j]%2019就是f(i),因此此处就是求前缀和 
	}
} 
inline ull MOD(ull a,ull b)//模重复平方法实现a*b(modM)，不一定快，但是只在计算群元素的时候用 
{
	if(a>b) return MOD(b,a);
	ull res=0;
	while(a)
	{
		if(a&1){
			res=res+b;
			if(res>=M)res-=M;
		}
		b<<=1;
		if(b>=M)b-=M;
		a>>=1;
	}
	return res;
}
inline int read()
{
    int x=0;char s=getchar();
    while(s<'0'||s>'9')s=getchar();
    while(s>='0'&&s<='9'){x=x*10+s-'0';s=getchar();}
    return x;
}
int seq[200001],seqh,questh;//所有问题形成的区间分割点 
int quest[200001];//所有问题的列表 

struct tnode
{
    int fa;
    int son[2];
    int val[32],sum[32];//val表示当前点的区间和，sum子树的区间和 
    int left,right;//表示区间的起始位置，每个分割点算一个区间，两个分割点之间算一个区间 
}*tree;//splay对象公用的节点数组 

#define get(x) (tree[tree[x].fa].son[1]==(x))
#define Key_value tree[tree[root].son[1]].son[0]
#define t tree[x]
#define lson tree[x].son[0]
#define rson tree[x].son[1]
#define tlson tree[tree[x].son[0]]
#define trson tree[tree[x].son[1]]
int tot;///构建splay树时的当前指针，在新增加node的时候自动+1 
int top[32];//临时记录在一次[l,r]查询中，查到的32个splay树中[l,r]区间所在的树根，用于后面连根一起移到其他splay 
class SPLAY{
public:
int root;//当前splay的root 
int which;//代表当前splay假设所有节点都是乘以的 u[which] 
void SetWhich(int w)//初始化 
{
	root=NewNode(0, -1);//左哨兵，最小值 ，正常的index不会取-1和MAXN 
    tree[root].son[1]=NewNode(root, MAXN);//右哨兵最大值    
	which=w;
	if(w==31)//u[31]=1,每次查询的时候都是从u[31]开始，然后乘以u[s%5]之后变到其他u的 
	{
		Key_value=Build(tree[root].son[1],0,(new_size<<1)-2);//离散化后，总共有 new_size个点，new_size-1个区间 
	}
	PushUp(tree[root].son[1]);              
    PushUp(root); 
}
void PushUp(int x)//在左或者右儿子发生改变的时候,根据左右儿子的值update x节点 
{
	for(int i=0;i<32;i++)
    	t.sum[i]=tlson.sum[i]+trson.sum[i]+t.val[i];
}
void Rotate(int x)
{
    int which=get(x);
    int y=tree[x].fa;
    int z=tree[y].fa;
    
    tree[y].son[which]=tree[x].son[which^1];
    tree[tree[y].son[which]].fa =y;
    tree[x].son[which^1]=y;
    tree[y].fa=x;
    tree[x].fa=z;
    if(z!=0)
    {
        tree[z].son[tree[z].son[1]==y]=x;
    }
    PushUp(y);
    PushUp(x);
}
void Splay(int x,int goal)///将当前节点转到目标goal之下,例如goal=0,则表示转为根
{
    int fa=tree[x].fa;
    while(fa!=goal)
    {
        if(tree[fa].fa!=goal)
            Rotate(get(x)==get(fa)?fa:x);
        Rotate(x);
        fa=tree[x].fa;
    }
    if(goal==0)root=x;
}

int NewNode(int fa,int index)///在节点fa下新加一个A[index]节点，x返回该节点在tree数组中的pos
{
    int x=++tot;
    t.fa=fa;
     
    if(index!=-1 && index!=MAXN)
    {
    	if(index&1)//奇数表示区间,seq=a,b,c,则可以分成[a,a],[a+1,b-1],[b,b],[b+1,c-1],[c,c]等5个区间，index分别为0,1,2,3,4 
		{	
			t.left=seq[index>>1]+1;
			t.right=seq[(index>>1)+1]-1;
		}
		else//偶数表示单点 
		{
			t.left=t.right=seq[index>>1];
	 	}
    	for(int i=0;i<32;i++)
	    	t.sum[i]=t.val[i]=presum[t.right][i]-presum[t.left-1][i];
	}
	else
		t.left=t.right=index;
	return x;
}
int Build(int fa,int l,int r)//二分法将序列转化成splay树 ，这样最平衡 
//每次在fa下面增加一个节点，这个节点就是区间的中点 
{
    if(l>r) return 0;
    int mid=(l+r)>>1;
    int x;
    if(mid&1 && seq[mid>>1]+1>seq[(mid>>1)+1]-1)//根据上面的分割，此处不存在间隔 
	{
		if(mid+1>r)return 0; //容易出故障的地方 
		x=NewNode(fa,mid+1);//mid+1变成偶数，单点区间，一定可以成功 
      	lson=Build(x,l,mid-1);
      	rson=Build(x,mid+2,r);//mid和mid+1都已经处理完了 
	}
	else
	{
	  x=NewNode(fa,mid);
      lson=Build(x,l,mid-1);
      rson=Build(x,mid+1,r);
    }
    PushUp(x);//左右都建完后，x的sum就会发生改变，所以要修改，要放到两个build之后 
    return x;
}

inline int Get_Pre(int x,int index)///得到x子树下比index小的一个区间,注意：index不一定存在 
{
    if(t.left>=index)
	{
		if(lson==0)return x;
		return Get_Pre(lson,index);
	}
    else
	{
		if(rson==0)return x;
		int m=Get_Pre(rson,index);
		if(tree[m].left>=index)
			return x;
		else
		    return m;
	 } 
}
inline int Get_Next(int x,int index)///得到x子树下比index大的一个区间,注意：index不一定存在 
{
    if(t.right<=index)
	{
		if(rson==0)return x;
		return Get_Next(rson,index);
	}
	else
	{
		if(lson==0)return x;
		int m=Get_Next(lson,index);
		if(tree[m].right<=index)
			return x;
		else
		    return m;
	 } 
}
///从本树删除区间l到r的元素，并返回l到r的子树 
int Delete(int l,int r)
{
    Splay(Get_Pre(root,l),0);
    Splay(Get_Next(root,r),root);
    int res=Key_value;
    Key_value=0;
    PushUp(tree[root].son[1]);
    PushUp(root);
    return res;
}

void Insert(int kv)//将其他树的l到r的子树连根移到本树上 
{
    Key_value=kv;
    tree[kv].fa=tree[root].son[1];
    PushUp(tree[root].son[1]);
    PushUp(root);
}
int Query(int l,int r)//查询区间和 
{
	Splay(Get_Pre(root,l),0);
    Splay(Get_Next(root,r),root);
    top[which]=Key_value;//记录查询的子树，下次要连根移到其他子树 
    return tree[Key_value].sum[which];//通过上面的操作，区间恰好集中到Key_value处 
}
/*调试打印所有节点 
void Inorder(int x)
{
    if(!x)return;
    //PushDown(x);
    Inorder(lson);
    printf("%d->%d:%d ",t.val[1],t.left,t.right);
    Inorder(rson);
}
*/ 
}splay[32];
void query_range(int l,int r)
{
	int sum=0;
	for(int i=0;i<32;i++)//[l,r]区间中，所有乘以u[i]的节点都在splay[i]上 
		sum+=splay[i].Query(l,r);
	printf("%d\n",sum); 
	int s=sum%5;
	for(int i=0;i<32;i++)//一旦乘以u[which],这些节点将会被整体移到splay[which]上 
	{
		int which=com[i][s];
		splay[which].Insert(top[i]);
	}
}

int main()
{
	n=read();q=read();	
	//ull t1=clock();	
	int h=5;u[31]=1;
	for(int i=0;i<32;i++)//计算子群，32个元素 
	for(int j=0;j<h;j++)
	{
		ull a=MOD(u[i],u[j]);
		int pos =find(u,u+32,a)-u;
		if(pos==32)
		{
			u[h]=a;
			com[i][j]=com[j][i]=h;
			h++;
		}
		else
			com[i][j]=com[j][i]=pos;
	}
	preInit();	//计算前缀和 
	for(int i=1;i<10;i++)
	{
	for(int j=0;j<32;j++)
		printf("%d ",presum[i][j]-presum[i-1][j]);
	printf("\n");
    }
	tree=(tnode*)calloc(n+100,sizeof(tnode));
	int l,r;
	for(int i=0;i<q;i++)//离散化 
	{	
		l=read();r=read();
		quest[questh++]=l;
		quest[questh++]=r;
		seq[seqh++]=l;
		seq[seqh++]=r;
	}
	sort(seq,seq+seqh);
	new_size=unique(seq,seq+seqh)-seq;
	
	for(int i=0;i<32;i++)//初始化32棵树 
		splay[i].SetWhich(i);	
	
	for(int i=0;i<questh;i+=2)//打印结果 
	{
		query_range(quest[i],quest[i+1]);
	}	
	free(tree);
    //printf("new_size=%d,time=%lld\n",new_size,clock()-t1);
	//return 0;
	return 0;
 } 
