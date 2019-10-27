#include<bits/stdc++.h>
//https://www.luogu.org/problem/P3586
//离散化
using namespace std;
struct P3586
{
    int x;
    int k;
    int temp;
    char state;
};
P3586 sa[1000001];
int ss[1000001];
int state[1000001];//离散前索引
int states[1000001];//离散后索引
long long update(long long *save, long long i, long long k, long long n);
long long suma(long long *save, long long k);
long long savea[1000001];//个数
long long saveb[1000001];//k值
int main(){
    int n,m;
    cin>>n>>m;
    int a,b;
    int count=0;
    char c;
    for(int i=1;i<=m;++i){//搜集离散数据
    getchar();
        scanf("%c %d %d",&sa[i].state,&sa[i].x,&sa[i].k);
        state[i]=sa[i].k;
        sa[i].temp=i;
    }
    sort(state+1,state+m+1);
    for(int i=1;i<=m;++i){//离散化
        states[state[i]]=i;
    }
    memset(state,0,sizeof(state));
    for(int i=1;i<=m;++i){
        if(sa[i].state=='U'){
            if(ss[sa[i].x]){//先删除旧记录
                update(savea,states[ss[sa[i].x]],-1,m);
                update(saveb,states[ss[sa[i].x]],-ss[sa[i].x],m);
            }
            ss[sa[i].x]=sa[i].k;
            if(sa[i].k){//大于0时候才需要修改状态
                update(savea,states[sa[i].k],1,m);
                update(saveb,states[sa[i].k],sa[i].k,m);
            }
        }else{
            long long tempa=suma(savea,m)-suma(savea,states[sa[i].k]-1);
            long long tempb=suma(saveb,states[sa[i].k]-1);
            if(tempa>=sa[i].x||tempb>=(sa[i].k*(sa[i].x-tempa))){
                state[sa[i].temp]=1;
            }else{
                state[sa[i].temp]=2;
            }
        }
    }
    for(int i=1;i<=m;++i){
        if(state[i]==1){
            printf("TAK\n");
        }else if(state[i]==2){
            printf("NIE\n");
        }
    }

}
long long update(long long *save, long long i, long long k, long long n){
  for(long long j=i;j<=n;j+=(j&-j)){
    save[j]+=k;
  }
}
long long suma(long long *save, long long k) {
  long long ans = 0;
  for (long long i = k; i; i -= (i & -i)) {
    ans += save[i];
  }
  return ans;
}