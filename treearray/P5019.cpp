#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;
int ss[100002];
int save[100002];
int update(int *save, int i, int k, int n);
int suma(int *save, int k);
int main() {
  int n;
  cin>>n;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", ss + i);
  }
  for (int i = 1; i <= n; ++i) {
    update(save, i, ss[i] - ss[i - 1], n+1);
  }
  update(save,n+1,-ss[n],n+1);
  int ans = 0;
  int begin = 0;
  int end = 0;
  int mins=0;
  int temp;
  while (begin<=n) {
    while (!suma(save, begin)&&begin<=n) {
      begin++;
    }
    if(begin>n)
    break;
    end = begin;
    mins=0x7fffffff;
    while ((temp=suma(save, end))) {
      mins=min(mins,temp);
      ++end;
    }
    update(save,begin,-mins,n+1);
    update(save,end,mins,n+1);
    ans+=mins;
  }
  cout<<ans<<endl;
  return 0;
}
int update(int *save, int i, int k, int n){
  for(int j=i;j<=n;j+=(j&-j)){
    save[j]+=k;
  }
}
int suma(int *save, int k) {
  int ans = 0;
  for (int i = k; i; i -= (i & -i)) {
    ans += save[i];
  }
  return ans;
}