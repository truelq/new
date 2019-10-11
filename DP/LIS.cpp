#include <iostream>

int binary_s(int*,int,int);
using namespace std;
int main()
{
    int n;
    cin >> n;
    int ss[n];
    int low[n];
    for (int i = 0; i < n; ++i){
        cin >> ss[i];
        low[i]=0x7fffffff;
    }
    low[0]=ss[0];

    int ans=0;
    for(int i=1;i<n;++i){
        if(ss[i]>low[ans]){ 
            low[++ans]=ss[i];
        }else{
            low[binary_s(low,ans,ss[i])]=ss[i];
        }
    }

    cout<<ans+1<<endl;
    return 0;

}
int binary_s(int *a,int r,int x){
    int l=0;
    int mid;
    while(l<=r){
        mid=(l+r)>>1;
        if(a[mid]<=x)
        l=mid+1;
        else r=mid-1;

    }
    return l;
}