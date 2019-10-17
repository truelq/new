#include <iostream>
#include <stdio.h>

#include <string.h>
using namespace std;
#define MOD 100000000
//最长公共子序列
char ss[2][5001];

int main()
{
    int n, m;
    n = m = 0;
    for (n = 1; (ss[0][n] = getchar()) != '.'; ++n)
        ;
    for (m = 1; (ss[1][m] = getchar()) != '.'; ++m)
        ;
    unsigned save[2][5002];
    unsigned count[2][5002];
    int currow=0;
    memset(save,0,sizeof(save));
    memset(count,0,sizeof(count));
    for (int i = 1; i <= 5001; ++i)
    {
        count[currow][i] = 1;
    }
    for (int i = 1; i < n; ++i)
    {
        currow^=1;
        memset(count[currow],0,sizeof(unsigned)*5002);
        //memset(save[currow],0,sizeof(unsigned)*5002);
        //count[currow][0]=1;
        for (int j = 1; j < m; ++j)
        {
            save[currow][j] = max(save[currow^1][j], save[currow][j - 1]);
            if (ss[0][i] == ss[1][j])
            {
                save[currow][j] = max(save[currow][j], save[currow^ 1][j - 1] + 1);
                if (save[currow][j] == save[currow^ 1][j - 1] + 1)
                {
                    count[currow][j] += count[currow^1][j - 1];
                }
            }
            if (save[currow][j] == save[currow^ 1][j])
            {
                count[currow][j] += count[currow^1][j];
            }
            if (save[currow][j] == save[currow][j - 1])
            {
                count[currow][j] += count[currow][j - 1];
            }
            if (ss[0][i] != ss[1][j] && save[currow][j] == save[currow^ 1][j - 1])
            {
                count[currow][j] -= count[currow^ 1][j - 1];
            }

            count[currow][j] =(count[currow][j]+MOD)%MOD;
        }
    }
    cout << save[currow][m-1]  << endl;
    cout << count[currow][m-1] << endl;
    //cout<<sizeof(save)/1000000<<endl;
    return 0;
}