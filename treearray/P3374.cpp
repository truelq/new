#include<iostream>
#include<stdio.h>
#include<string.h>

using namespace std;
//树状数组 求和
long long ss[500001];
long long sss[500001];
int update(long long sss[],int b,int c,int n);
long long suma(long long sss[],int b);

int main(){
    int n,m;
    int a,b,c;
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        scanf("%d",ss+i);
        update(sss,i,ss[i],n);
    }
    while(m--){
        scanf("%d %d %d",&a,&b,&c);
        if(a==1){
            update(sss,b,c,n);
        }else if(a==2){
            printf("%lld\n",suma(sss,c)-suma(sss,b-1));
        }
    }
}
int update(long long sss[],int x,int k,int n){
    for(int j=x;j<=n;j+=(j&-j)){
        sss[j]+=k;
    }
}
long long suma(long long sss[],int x){
    long long ans=0;
    for(int i=x;i;i-=(i&-i)){
        ans+=sss[i];
    }
    return ans;
}