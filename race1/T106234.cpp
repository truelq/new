#include<bits/stdc++.h>
using namespace std;
long long ss[1001][1001];
int main(){
    int n;
    cin>>n;
    ss[1][0]=1;
    ss[1][1]=1;
    for(int i=2;i<=n;++i){
        ss[i][0]=1;
        ss[i][1]=i;
    }
    for(int i=2;i<=n;++i){
        for(int j=2;j<=i;++j){
            ss[i][j]=ss[i-1][j]+ss[i-1][j-1];
            ss[i][j]%=999999997;
        }
    }
    int mod=999999997;
    long long ans=0;
    for(int k=1;k<=n-3;++k){
        ans+=((ss[n-1][k]*k*(n-k-2)));
        ans%=mod;
    }
    cout<<ans<<endl;
    return 0;
}