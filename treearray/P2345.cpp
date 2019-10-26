#include<bits/stdc++.h>

using namespace std;
//https://www.luogu.org/problem/P2345
//树状数组
struct P2345
{
    int x;
    int v;
};
bool operator<(P2345&a,P2345&b){
    //if(a.v==b.v){
    //    return a.x<b.x;
    //}
    return a.v<b.v;
}
long long update(long long *save, long long i, long long k, long long n);
long long suma(long long *save, long long k);
P2345 ss[20001];
long long savea[20001];
long long saveb[20001];
int main(){
    int n;
    cin>>n;
    long long ans=0;
    for(int i=1;i<=n;++i){
        scanf("%d %d",&ss[i].v,&ss[i].x);
    }
    sort(ss+1,ss+n+1);
    for(int i=1;i<=n;++i){
        update(savea,ss[i].x,ss[i].x,20000);
        update(saveb,ss[i].x,1,20000);
        int temp=suma(saveb,ss[i].x);
        ans+=ss[i].v*((2*temp-i)*ss[i].x+suma(savea,20000)-2*suma(savea,ss[i].x));
    }
    cout<<ans<<endl;
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