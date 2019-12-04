#include <iostream>
#include <stdio.h>
#include <unordered_map>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;

unsigned int ss[200001] = {0};
int main()
{
    int n;
    unordered_map<int, int> s;
    while ((cin >> n) && n != 0)
    {
        for (int i = 1; i <= n; ++i)
        {
            scanf("%u", ss + i);
        }
        unsigned int least = 0;
        unsigned long long ans = 0;
        for (int i = 0; i < n; ++i)
        {
            s[ss[i]] += 1;
            while (s[least] != 0)
            {
                ++least;
            }
            ans += least;
        }
        printf("i:1 %d\n", least);

        for(int i=2;i<=n;++i){
            s[ss[i-1]]-=1;
            if(s[ss[i-1]]==0){
                least=min(least,ss[i-1]);
            }
            printf("i:%d %d\n", i, least);
        }
        for (int i = 1; i <= n; ++i)
        {
            s.clear();
            least = 0;
            for (int j = i; j <= n; ++j)
            {
                s[ss[j]] += 1;
                while (s[least] != 0)
                {
                    ++least;
                }
                ans += least;
            }
            printf("i:%d %d\n", i, least);
        }
        cout << ans << endl;
    }
    return 0;
}