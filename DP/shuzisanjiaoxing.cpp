#include <iostream>
#include <string.h>
#define max(a, b) ((a)>(b)?(a):(b))

using namespace std;

int main()
{
    int n, m;
    int ans=0;
    cin >> n >> m;

    int ss[n + 2][m + 2] = {0};
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
        {
            scanf("%d",&ss[i][j]);
            //cin >> ss[i][j];
        }

    //莽一下
    int force[4][n + 2][m + 2];
    memset(force, 0, sizeof(force));
    //(0,0)
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            force[0][i][j]=ss[i][j]+max(force[0][i-1][j],force[0][i][j-1]);
        }
    }
    //(n,0)
    for (int i = n; i >= 1; --i)
    {
        for (int j = 1; j <= m; ++j)
        {
            force[1][i][j]=ss[i][j]+max(force[1][i+1][j],force[1][i][j-1]);
        }
    }
    //(0,m)
    for (int i = 1; i <= n; ++i)
    {
        for (int j = m; j>=1; --j)
        {
            force[2][i][j]=ss[i][j]+max(force[2][i-1][j],force[2][i][j+1]);
        }
    }
    //(n,m)
    for (int i = n; i >=1; --i)
    {
        for (int j = m; j >=1; --j)
        {
            force[3][i][j]=ss[i][j]+max(force[3][i+1][j],force[3][i][j+1]);
        }
    }

    for(int i=2;i<n;++i){
        for(int j=2;j<m;++j){
            ans=max(ans,force[0][i-1][j]+force[1][i][j-1]+force[2][i][j+1]+force[3][i+1][j]);
            ans=max(ans,force[0][i][j-1]+force[1][i+1][j]+force[2][i-1][j]+force[3][i][j+1]);
        }
    }
    cout<<ans<<endl;
    return 0;
}