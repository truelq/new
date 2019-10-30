#include <bits/stdc++.h>
// https://www.luogu.org/problem/P3149

using namespace std;
struct P3149
{
  int x;
  int k;
};
bool operator<(P3149&a,P3149&b){
  return a.k<b.k;
}
P3149 ss[300001];
int sa[300001];
int sb[300001];
long long savea[300001];
long long saveb[300001];
int state[300001];
int states[300001];
int update(long long sss[], long long b, long long c, long long n);
long long suma(long long sss[], long long b);
int main() {


  int n, m;
  cin >> n >> m ;
  for (int i = 1; i <=n; ++i) {
    scanf("%d", &ss[i].k);
    ss[i].x=i;
  }
  sort(ss+1,ss+n+1);
  for(int i=1;i<=n;++i){
    state[ss[i].x]=i;
    
  }
  int ans=0;
  for(int i=n;i;--i){
    ans+=suma(savea,state[i]);
    update(savea,state[i],1,n);
  }
  printf("%d\n",ans);

}
int update(long long sss[], long long x, long long k, long long n) {
  for (int j = x; j <= n; j += (j & -j)) {
    sss[j] += k;
  }
}
long long suma(long long sss[], long long x) {
  long long ans = 0;
  for (int i = x; i; i -= (i & -i)) {
    ans += sss[i];
  }
  return ans;
}