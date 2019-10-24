#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;

//前缀和的前缀和  公式设计
//https://www.luogu.org/problem/P4868
long long ss[100001];
long long save[100001];
long long savea[100001];
int update(long long sss[],long long b,long long c,long long n);
long long suma(long long sss[],long long b);

int main(){
    int n,m;
    cin>>n>>m;
    for(long long i=1;i<=n;++i){
        scanf("%d",ss+i);
        update(save,i,ss[i],n);
        update(savea,i,i*ss[i],n);
    }
    char mod[10];
    long long b,c;
    for(long long i=0;i<m;++i){
        scanf("%s",mod);
        if(strcmp(mod,"Query")==0){
            scanf("%lld",&b);
            printf("%lld\n",(b+1)*suma(save,b)-suma(savea,b));
        }else if(strcmp(mod,"Modify")==0){
            scanf("%lld %lld",&b,&c);
            update(save,b,c-ss[b],n);
            update(savea,b,b*(c-ss[b]),n);
            ss[b]=c;
        }
    }
    
}
int update(long long sss[],long long x,long long k,long long n){
    for(int j=x;j<=n;j+=(j&-j)){
        sss[j]+=k;
    }
}
long long suma(long long sss[],long long x){
    long long ans=0;
    for(int i=x;i;i-=(i&-i)){
        ans+=sss[i];
    }
    return ans;
}