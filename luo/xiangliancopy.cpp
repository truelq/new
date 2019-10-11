#include <algorithm>
#include <iostream>
#include <stdio.h>

using namespace std;
struct point
{
    int i;
    int a;
    int b;
};
void add(int x, int k, int N, int *tree)
{
    for (int i = x; i <= N; i += (i & -i))
    {
        tree[i] += k;
    }
}
bool compare(point m, point n)
{
    if (m.b == n.b)
        return m.a < n.a;
    return m.b < n.b;
}
int input()
{
    char ch = ' ';
    while (ch < '0' || ch > '9')
        ch = getchar();
    int x = 0;
    while (ch <= '9' && ch >= '0')
        x = x * 10 + ch - '0', ch = getchar();
    return x;
}
int state[1000001] = {0};
int main()
{
    int N;
    N = input();
    int xianglian[N];

    for (register int i = 0; i < N; ++i)
        xianglian[i] = input();

    int M;
    int before = 0;
    int flag = 0;
    int end = 0;
    int temp = 0;
    M = input();
    point saves[M];
    int ans[M] = {0};
    int xs[N + 1] = {0};
    int treexs[N + 1] = {0};

    for (register int i = 0; i < M; ++i)
    {
        saves[i].a = input();
        saves[i].b = input();
        saves[i].i = i;
    }
    sort(saves, saves + M, compare);

    for (register int i = 0; i < M; ++i)
    {
        register int j = 0;
        flag = 0;
        for (j = temp; j < saves[i].b; ++j)
        {
            if (!state[xianglian[j]])
            {
                state[xianglian[j]] = j + 1;
                //xs[j] = 1;
                ++end;
            }
            else
            {
                //xs[state[xianglian[j]] - 1] = 0;
                add(state[xianglian[j]], -1, N + 1, treexs);
                //xs[j] = 1;
                state[xianglian[j]] = j + 1;
            }
            add(state[xianglian[j]], 1, N + 1, treexs);
        }

        temp = saves[i].b;
        before = 0;
        for (j = saves[i].a - 1; j; j = j - (j & -j))
        {
            before += treexs[j];
        }
        ans[saves[i].i] = end - before;
    }
    for (int i = 0; i < M; ++i)
        printf("%d\n", ans[i]);

    return 0;
}