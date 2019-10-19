#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
//分组背包，每组选特定个
struct P1757
{
    int w;
    int v;
};
int save[1001];
int main()
{
    freopen("C:\\Users\\32125\\Documents\\vscodec\\DPgroup\\testdata.in","r",stdin);
    int m, n;
    int a, b, c;
    int temp=0;
    P1757 tempt;
    scanf("%d %d",&m,&n);
    //int save[m + 1] = {0};
    vector<P1757> group[101];
    for (int i = 0; i < 101; ++i)
    {
        group[i].push_back({0,0});
    }
    for (int i = 0; i < n; ++i)
    {
        scanf("%d %d %d", &a, &b, &c);
        tempt.w=a;
        tempt.v=b;
        group[c].push_back(tempt);
    }
    for (int i = 1; i < 101; ++i)
    {
        for (int k = m; k >= 0; --k)
        {
            temp=save[k];
            for (int j = 1; j < group[i].size(); ++j)
            {
                if (k >= group[i][j].w){
                    int t= max(save[k], save[k - group[i][j].w] + group[i][j].v);
                    temp=max(temp,t);
                }
            }
            save[k]=temp;
            //cout<<temp<<endl;
        }
    }
    cout << save[m] << endl;
    return 0;
}