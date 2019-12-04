#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

struct test
{
    int u, v, w;
} e[20010];
int n, m, par[20010], L = 0;
test s;
void makeset(int x ){
    par[x]=x;
}
int find(int x)
{ //查
    if (x == par[x])
        return x;
    return par[x] = find(par[x]);
}
int unionn(int x, int y)
{ //并
    par[find(x)] = y;
}

int kruskal(int x)
{
    int ans = 0, k = 0;
    for (int i = 1; i <= x; i++)
    {
        if (find(e[i].v) != find(e[i].u))
        {
            unionn(e[i].u, e[i].v);
            ans += e[i].w;
            k++;
        }
        if (k == n - 1)
            break;
    }
    if (k < n - 1)
        return -1;
    return ans;
}

void Sort()
{
    int i, j;
    for (i = L; i >= 0; i--)
        if (e[i].w <= s.w)
            break;
    for (j = L; j >= i; j--)
        e[j + 1] = e[j];
    e[i + 1] = s;
    L++;
}

int main()
{
    scanf("%d%d", &n, &m);
    e[0].v = 0;
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d%d", &s.u, &s.v, &s.w);
        Sort();
        if (i < n - 1)
        {
            printf("-1\n");
            continue;
        }
        for (int j = 1; j <= i; j++)
            makeset(j);
        printf("%d\n", kruskal(i));
    }
    return 0;
}