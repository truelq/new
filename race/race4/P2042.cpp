#include<cstdio>
#include<cstring>
#include<iostream>

#define N 500001
#define INF 0x7fffffffffffffff

using namespace std;

struct Splay
{
    int fa,ch[2],size;
    long long val,sum,maxn,lazy,tag,ls,rs;
    bool laz;
}t[N];

long long n,m,tot,root,tot2,a[N],s[N];

void down(int k)
{
    int l=t[k].ch[0],r=t[k].ch[1];
    if(t[k].laz)
    {
        t[k].lazy=t[k].laz=0;
        if(l)
        {
            t[l].laz=true;
            t[l].val=t[k].val;
            t[l].sum=t[k].val*t[l].size;
        }
        if(r)
        {
            t[r].laz=true;
            t[r].val=t[k].val;
            t[r].sum=t[k].val*t[r].size;
        }
        if(t[k].val>=0)
        {
            if(l)t[l].ls=t[l].rs=t[l].maxn=t[l].sum;
            if(r)t[r].ls=t[r].rs=t[r].maxn=t[r].sum;
        }
        else 
        {
            if(l)t[l].ls=t[l].rs=0,t[l].maxn=t[k].val;
            if(r)t[r].ls=t[r].rs=0,t[r].maxn=t[k].val;
        }
    }
    if(t[k].tag)
    {
        t[k].tag=0;t[l].tag^=1;t[r].tag^=1;
        swap(t[l].ls,t[l].rs);swap(t[r].ls,t[r].rs);
        swap(t[l].ch[0],t[l].ch[1]);swap(t[r].ch[0],t[r].ch[1]);
    }
}

void up(int k)
{
    int l=t[k].ch[0],r=t[k].ch[1];
    t[k].size=t[l].size+t[r].size+1;
    t[k].sum=t[l].sum+t[r].sum+t[k].val;
    t[k].maxn=max(max(t[l].maxn,t[r].maxn),t[l].rs+t[k].val+t[r].ls);
    t[k].ls=max(t[l].ls,t[l].sum+t[k].val+t[r].ls);
    t[k].rs=max(t[r].rs,t[r].sum+t[k].val+t[l].rs);
}

bool get(int k)
{
    return t[t[k].fa].ch[1]==k;
}

void rotate(int k)
{
    int fa=t[k].fa,gfa=t[fa].fa;
    int d1=get(k),d2=get(fa);
    t[fa].ch[d1]=t[k].ch[d1^1];
    t[t[k].ch[d1^1]].fa=fa;
    t[fa].fa=k;
    t[k].ch[d1^1]=fa;
    t[k].fa=gfa;
    t[gfa].ch[d2]=k;
    up(fa);up(k);
}

void splay(int x,int y)
{
    while(t[x].fa!=y)
    {
        int fa=t[x].fa,gfa=t[fa].fa;
        int d1=get(x),d2=get(fa);
        if(gfa!=y)
        {
            if(d1==d2)rotate(fa);
            else rotate(x);
        }
        rotate(x);
    }
    if(!y)root=x;
}

int kth(int k)
{
    int now=root;
    while(1)
    {
        down(now);
        if(k<=t[t[now].ch[0]].size)now=t[now].ch[0];
        else if(k==t[t[now].ch[0]].size+1)return now;
        else 
        {
            k-=t[t[now].ch[0]].size+1;
            now=t[now].ch[1];
        }
    }
}

int build(int l,int r,int fa)
{
    if(l>r)return 0;
    int mid=(l+r)>>1,now;
    if(tot2)now=s[tot2--];
    else now=++tot;
    t[now].fa=fa;
    t[now].val=a[mid];
    t[now].tag=t[now].lazy=t[now].laz=0;
    t[now].ch[0]=build(l,mid-1,now);
    t[now].ch[1]=build(mid+1,r,now);
    up(now);
    return now;
}

void insert(int l,int x)
{
    int r=l+1;
    l=kth(l+1);r=kth(r+1);
    splay(l,0);splay(r,l);
    for(int i=1;i<=x;i++)scanf("%lld",&a[i]);
    t[r].ch[0]=build(1,x,r);
    n+=x;
    up(r);up(l);
}

void erase(int k)
{
    if(!k)return;
    s[++tot2]=k;
    erase(t[k].ch[0]);
    erase(t[k].ch[1]);
}

void delet(int l,int r)
{
    n-=r-l+1;
    l=kth(l);r=kth(r+2);//(l+1)-1=l,(r+1)+1=r+2
    splay(l,0);splay(r,l);
    erase(t[r].ch[0]);
    t[r].ch[0]=0;
    up(r);up(l);
}

void make_same(int l,int r,int x)
{
    l=kth(l);r=kth(r+2);
    splay(l,0);splay(r,l);
    int k=t[r].ch[0];
    t[k].val=x;
    t[k].sum=t[k].size*x;
    if(x<=0)t[k].ls=t[k].rs=0,t[k].maxn=x;
    else t[k].ls=t[k].rs=t[k].maxn=t[k].size*x;
    t[k].lazy=x;
    t[k].laz=true;
    up(r);up(l);
}

void reverse(int l,int r)
{
    l=kth(l);r=kth(r+2);
    splay(l,0);splay(r,l);
    int k=t[r].ch[0];
    if(!t[k].laz)
    {
        t[k].tag^=1;
        swap(t[k].ch[0],t[k].ch[1]);
        swap(t[k].ls,t[k].rs);
        up(r);up(l);
    }
}

void write(int k)
{
    if(k)
    {
        down(k);
        write(t[k].ch[0]);
        if(t[k].val!=-INF&&t[k].val!=INF)printf("%lld ",t[k].val);
        write(t[k].ch[1]);
    }
}

long long query_sum(int l,int r)
{
    l=kth(l);r=kth(r+2);
    splay(l,0);splay(r,l);
    return t[t[r].ch[0]].sum;
}

long long max_sum()
{
    int l=kth(1),r=kth(n+2);
    splay(l,0);splay(r,l);
    return t[t[r].ch[0]].maxn;
}

int main()
{
    scanf("%lld%lld",&n,&m);
    t[0].maxn=-INF;//注意
    a[1]=-INF;
    a[n+2]=INF;
    for(int i=1;i<=n;i++)scanf("%lld",&a[i+1]);
    root=build(1,n+2,0);
    while(m--)
    {
        char ch[9];
        int x,y,z;
        scanf("%s",ch);
        if(ch[0]=='I')
        {
            scanf("%d%d",&x,&y);
            insert(x,y);
        }
        if(ch[0]=='D')
        {
            scanf("%d%d",&x,&y);
            delet(x,x+y-1);
        }
        if(ch[0]=='M'&&ch[2]=='K')
        {
            scanf("%d%d%d",&x,&y,&z);
            make_same(x,x+y-1,z);
        }
        if(ch[0]=='R')
        {
            scanf("%d%d",&x,&y);
            reverse(x,x+y-1);
        }
        if(ch[0]=='G')
        {
            scanf("%d%d",&x,&y);
            printf("%lld\n",query_sum(x,x+y-1));
        }
        if(ch[0]=='M'&&ch[2]=='X')
        {
            printf("%lld\n",max_sum());
        }
    }
    return 0;
}