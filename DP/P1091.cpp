#include <iostream>

using namespace std;
int binary_s(int*,int,int);
int main()
{
    int n;
    cin >> n;
    int ss[n + 1] = {0};
    int sss[n + 1] = {0};
    int save[n + 1] = {0};
    int savee[n + 1] = {0};
    for (int i = 0; i < n; ++i)
    {
        cin >> ss[i];
        sss[n - i - 1] = ss[i];
        save[i]=savee[i]=0x7fffffff;
    }
    
    for (int i = 0; i < n; ++i)
    {
        
    }
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