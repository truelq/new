#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>
#include<unordered_set>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int ss[n + 2];
    int s[n + 2];
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d %d", ss + i, s + i);
    }
    ss[0] = 0x7fffffff;
    s[0] = 0x7fffffff;
    ss[n + 1] = 0;
    s[n + 1] = 0;
    double save[n + 2] = {0};
    vector<int> source[n + 2];
    unordered_set<int> sou[n+2];
    double count[n + 2] = {0};
    double maxs = 0;
    count[0] = 1;
    for (int i = 1; i <= n + 1; ++i)
    {
        double temp = 0;
        for (int j = 0; j < i; ++j)
        {
            if (ss[i] <= ss[j] && s[i] <= s[j])
                temp = max(temp, save[j]);
        }
        for (int j = 0; j < i; ++j)
        {
            if (ss[i] <= ss[j] && s[i] <= s[j] && save[j] == temp)
            {
                source[i].push_back(j);
                sou[j].insert(i);
                count[i] += count[j];
            }
        }
        save[i] = temp + 1;
        maxs = max(maxs, save[i]);
    }
    cout << maxs - 1 << endl;
    int temp = 0;
    double ans = count[n + 1];
    stack<int> as;
    
    for (int i = 1; i <= n; ++i)
    {
        if (state[i])
            count[i] /= ans;
        else
            count[i] = 0;
        cout << count[i] << ' ';
    }

    //cout << ans << endl;
}