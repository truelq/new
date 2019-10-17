#include <iostream>
#include <stdio.h>
#include <string.h>
#include<vector>
#include<algorithm>
using namespace std;
//最长公共子序列
int main()
{
    int n;
    cin >> n;
    int ss[2][n + 1];
    int nb[n + 1] = {0};
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", ss[0] + i);
        nb[ss[0][i]] = i;
    }
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", ss[1] + i);
        ss[1][i] = nb[ss[1][i]];
    }
    ss[1][0] = 0;
    vector<int> save;
    save.reserve(n+1);
    //memset(save, 0, sizeof(save));
    int ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        if(ss[1][i]>save[ans]){
            save[++ans]=ss[1][i];
        }else{
            save[upper_bound(save.begin(),save.begin()+ans,ss[1][i])-save.begin()]=ss[1][i];
        }
    }
    cout << ans << endl;
}