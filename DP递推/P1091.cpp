#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int ss[n + 1];
    for (int i = 0; i < n; ++i)
    {
        cin >> ss[i];
    }
    vector<int> save;
    save.reserve(n + 1);

    int l[n + 1];
    //memset(save,0x7f,sizeof(save));
    memset(l, 0, sizeof(l));
    save[0] = 0;
    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        if (ss[i] > save[ans])
        {
            save[++ans] = ss[i];
        }
        else
        {
            int temp = (int)(lower_bound(save.begin() , save.begin() + ans + 1, ss[i]) - save.begin());
            save[temp] = ss[i];
        }
        l[i] = ans;
    }
    //下降
    int sss[n + 1];
    for (int i = n; i > 0; --i)
    {
        sss[i] = ss[n - i];
    }
    int ll[n + 1];
    memset(ll, 0, sizeof(ll));
    save.clear();
    save.reserve(n + 1);
    save[0] = 0;

    ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (sss[i] > save[ans])
        {
            save[++ans] = sss[i];
        }
        else
        {
            int temp = lower_bound(save.begin() , save.begin() + ans + 1, sss[i]) - save.begin();
            save[temp] = sss[i];
        }
        ll[i] = ans;
    }
    ans = 0;
    for (int i = 0; i < n; ++i)
    {
        //cout<<l[i]<<' '<<ll[n-i]<<endl;
        ans = max(ans, l[i] + ll[n - i] - 1);
    }

    cout << n - ans << endl;
    return 0;
}