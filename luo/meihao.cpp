#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <cmath>
using namespace std;
struct meihao
{
    int a;
    int b;
    int i;
    int fir;
};
bool compare(meihao x, meihao y)
{
    if (x.fir == y.fir)
        if (x.b == y.b)
            return x.a < y.a;
        else
            return x.b < y.b;
    return x.fir < y.fir;
}
short mem[0x4000000] = {0};
bool state[0x4000000] = {0};

int main()
{
    int n, m;
    cin >> n >> m;
    meihao xs[m + 1];

    int ans[m + 1];
    int aans = 0;

    int start, end;
    char tab[n + 2];
    long int jl[n + 1][27] = {0};
    int leng[n + 1] = {0};

    long int cha[n + 1] = {0};
    long int chaa[27] = {
        0, 0x1, 0x2, 0x4, 0x8, 0x10, 0x20, 0x40, 0x80, 0x100, 0x200, 0x400, 0x800, 0x1000, 0x2000, 0x4000, 0x8000,
        0x10000, 0x20000, 0x40000, 0x80000, 0x100000, 0x200000, 0x400000, 0x800000, 0x1000000, 0x2000000};
    scanf("%s", tab + 1);
    for (register int i = 1; i <= n; ++i)
    {
        cha[i] = cha[i - 1] ^ chaa[tab[i] - 'a' + 1];
        state[cha[i]] = 1;
    }
    state[0] = 1;
    for (register int i = 0; i <= n; ++i)
    {
        for (register int j = 0; j < 27; ++j)
        {
            //异或预处理无敌
            if (state[cha[i] ^ chaa[j]])
            {
                jl[i][leng[i]] = cha[i] ^ chaa[j];
                ++leng[i];
            }
        }
    }

    int b = (int)n / (sqrt(m));
    for (int i = 1; i <= m; ++i)
    {
        scanf("%d %d", &xs[i].a, &xs[i].b);
        xs[i].i = i;
        xs[i].fir = xs[i].a / b;
    }
    sort(xs + 1, xs + m + 1, compare);

    start = xs[1].a;
    end = start - 1;
    mem[cha[start - 1]] = 1;
    for (int i = 1; i <= m; ++i)
    {
        while (end < xs[i].b)
        {
            int j = ++end;

            for (int k = 0; k < leng[j]; ++k)
                aans += mem[jl[j][k]];
            mem[cha[j]]++;
        }

        while (end > xs[i].b)
        {
            int j = end--;
            mem[cha[j]]--;
            for (int k = 0; k < leng[j]; ++k)
                aans -= mem[jl[j][k]];
            
        }

        while (start < xs[i].a)
        {
            int j = start - 1;
            ++start;
            --mem[cha[j]];
            for (int k = 0; k < leng[j]; ++k)
                aans -= mem[jl[j][k]];
        }

        while (start > xs[i].a)
        {
            --start;
            int j = start - 1;

            for (int k = 0; k < leng[j]; ++k)
                aans += mem[jl[j][k]];
            mem[cha[j]]++;
        }
        ans[xs[i].i] = aans;
    }
    for (int i = 1; i <= m; ++i)
        printf("%d\n", ans[i]);
    return 0;
}