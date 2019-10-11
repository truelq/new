#include <iostream>

using namespace std;

void add(int x,int k,int N,int *tree){
    for(int i=x;i<=N;i+=i&-i){
        tree[i]+=k;
    }
}
int main()
{
    int N, M;
    cin >> N >> M;
    int tables[N + 1]={0};
    int chafen[N + 1] = {0};
    int tree[N + 1] = {0};
    int a = 0;
    int x, y, k;
    int lowbit = 0;
    for (int i = 1; i < N + 1; ++i)
    {
        cin >> tables[i];
        chafen[i] = tables[i] - tables[i - 1];
    }
    for (int i = 1; i < N + 1; ++i)
    {
        for (int j = i + 1 - (i & -i); j <= i; ++j)
            tree[i] += chafen[j];
    }
    for (int i = 0; i < M; ++i)
    {
        cin >> a;
        if (a == 1)
        {
            cin>>x>>y>>k;
            add(x,k,N+1,tree);
            add(y+1,-k,N+1,tree);
        }
        else
        {
            cin>>x;
            int ans=0;
            for(int j=x;j;j=j-(j&-j)){
                ans+=tree[j];
            }
            cout<<ans<<endl;

        }
    }
    return 0;
}