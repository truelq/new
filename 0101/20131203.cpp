//单调栈

#include <iostream>
#include <stack>

using namespace std;
int main()
{
    int n;
    cin >> n;
    int a[n + 1];
    int s[n + 2] = {0};
    int w[n+1]={0};
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    a[n] = 0;

    int p = 0;
    int ans=0;
    for (int i = 0; i < n + 1; ++i)
    {
        if(a[i]>s[p])
        {
            s[++p]=a[i];
            w[p]=1;
        }else{
            int width=0;
            while(s[p]>a[i]){
                width+=w[p];
                ans=max(ans,width*s[p]);
                --p;
            }
            s[++p]=a[i];
            w[p]=width+1;
        }
    }
    cout<<ans;
    return 0;
}