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
    int ss[n + 1];
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", ss + i);
    }
    ss[0]=0x7fffffff;
    int save[n + 1] = {0};
    vector<int> source[n + 2];
    int maxs = 0;
    for (int i = 1; i <= n; ++i)
    {
        int temp = 0;
        for (int j = 0; j < i; ++j)
        {
            if (ss[i] < ss[j])
                temp = max(temp, save[j]);
        }
        for (int j = 0; j < i; ++j)
        {
            if (ss[i] < ss[j] && save[j] == temp)
            {
                source[i].push_back(j);
            }
        }
        save[i] = temp + 1;
        maxs = max(maxs, save[i]);
    }
    cout<<maxs<<' ';
    int temp = 0;
    int ans=0;
    stack<int> sss;
    unordered_set<int> ssss;
    for (int i = 1; i <= n; ++i)
    {
        if (maxs == save[i])
        {
            source[n+1].push_back(i);
        }
    }
    ssss.clear();
    for(int i=source[n+1].size()-1;i>=0;--i){
        if(ssss.find(ss[source[n+1][i]])==ssss.end()){
            sss.push(source[n+1][i]);
            ssss.insert(ss[source[n+1][i]]);
        }
    }
    while(!sss.empty()){
         temp=sss.top();
         sss.pop();
         ssss.clear();
         if(source[temp].size()==0){
            ++ans;
         }
         for(int i=source[temp].size()-1;i>=0;--i){
             if(ssss.find(ss[source[temp][i]])==ssss.end()){
                 sss.push(source[temp][i]);
                 ssss.insert(ss[source[temp][i]]);
             }
         }
    }

    cout << ans << endl;
}