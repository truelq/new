#include<bits/stdc++.h>
//https://www.luogu.org/problem/P1168
//离散化 树状数组

struct P1168
{
    int x;
    int k;
};
bool operator<(P1168&a,P1168&b){
    return a.k<b.k;
}
long long update(long long *save, long long i, long long k, long long n);
long long suma(long long *save, long long k);
int find(long long *save,int num,int n);
using namespace std;
P1168 ss[100001];
int sa[100001];
int state[100001];
int states[100001];
long long save[100001];
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;++i){
        scanf("%d",&ss[i].k);
        ss[i].x=i;
        sa[i]=ss[i].k;
    }
    sort(ss+1,ss+n+1);
    for(int i=1;i<=n;++i){
        state[ss[i].x]=i;
        states[i]=ss[i].x;
    }
    for(int i=1;i<=n;++i){
        update(save,state[i],1,n);
        if(i&1){
            int temp=find(save,(i+1)>>1,n);
            printf("%d\n",sa[states[temp]]);
        }
    }
    return 0;
}
long long update(long long *save, long long i, long long k, long long n){
  for(int j=i;j<=n;j+=(j&-j)){
    save[j]+=k;
  }
}
long long suma(long long *save, long long k) {
  long long ans = 0;
  for (int i = k; i; i -= (i & -i)) {
    ans += save[i];
  }
  return ans;
}
int find(long long *save,int sum,int n){
    int low=1;
    int high=n;
    int mid=(low+high)>>1;
    while(low<=high){
        if(suma(save,mid)<=sum-1){
            low=mid+1;
            mid=(low+high)>>1;
        }else{
            high=mid-1;
            mid=(low+high)>>1;
        }
    }
    return low;
}