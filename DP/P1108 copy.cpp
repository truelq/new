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
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", ss + i);
    }
    ss[0]=0x7fffffff;
    ss[n+1]=0;
    int save[n + 2] = {0};
    vector<int> source[n + 2];
    int count[n+2]={0};
    count[0]=1;
    unordered_set<int> ssss;
    int maxs = 0;
    for (int i = 1; i <= n+1; ++i)
    {
        int temp = 0;
        ssss.clear();
        for (int j = 0; j < i; ++j)
        {
            if (ss[i] < ss[j])
                temp = max(temp, save[j]);
        }
        for (int j = i-1; j >=0; --j)
        {
            if (ss[i] < ss[j] && save[j] == temp)
            {
                source[i].push_back(j);
                if(ssss.find(ss[j])==ssss.end()){
                    count[i]+=count[j];
                    ssss.insert(ss[j]);
                }
            }
        }
        save[i] = temp + 1;
        maxs = max(maxs, save[i]);
    }
    cout<<maxs-1<<' ';
    
    cout << count[n+1] << endl;
}