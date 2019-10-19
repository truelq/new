#include <iostream>
#include <stdio.h>
#include <unordered_map>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
//打表，n=200000，最小的数肯定不超过n
int ss[200001] = {0};
int state[200001];
int statecopy[200001];
int ans[200001];
int main()
{
    int n;
    unordered_map<int, int> s;
    int temp;
    int pointer=0;
    while ((cin >> n) && n != 0)
    {
        for (int i = 1; i <= n; ++i)
        {
            scanf("%d", ss + i);
        }
        memset(state,0,sizeof(state));
        memset(ans,0,sizeof(ans));
        pointer=0;
        for(int i=1;i<=n;++i){
            if(ss[i]<=n){
                state[ss[i]]++;//打表
            }
            memcpy(statecopy,state,(n+1)<<2);//临时表
            while(statecopy[pointer]){
                pointer++;
            }
            for(int j=0;j<i;++j){//临时修改
                
            }
        }
    }
    return 0;
}