#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
#include <stdio.h>
using namespace std;
struct node
{
    unsigned long int ip;
    int p;
    int state = 0;
    friend bool operator<(node a, node b)
    {
        if (a.ip == b.ip)
            return a.p < b.p;
        return a.ip < b.ip;
    }
};
node input()
{
    node temp;
    temp.ip = 0;
    temp.state = 1;
    int ip[4] = {0};
    char a;
    int p = 0;
    int flag = -1;
    while ((a = getchar()) != '\n')
        if (a == '\r')
            continue;
        else if (a == '.')
            p += 1;
        else if (a == '/')
            scanf("%d", &flag);
        else
            ip[p] = ip[p] * 10 + a - '0';
    for (int i = 0; i <= p; ++i)
    {
        temp.ip <<= 8;
        temp.ip += ip[i];
    }
    for (int i = 0; i < 3 - p; ++i)
        temp.ip <<= 8;
    if (flag == -1)
        temp.p = 8 * p + 8;
    else
        temp.p = flag;
    return temp;
}
unsigned long int tables[33] = {
    0,
    0x80000000, 0xc0000000, 0xe0000000, 0xf0000000,
    0xf8000000, 0xfc000000, 0xfe000000, 0xff000000,
    0xff800000, 0xffc00000, 0xffe00000, 0xfff00000,
    0xfff80000, 0xfffc0000, 0xfffe0000, 0xffff0000,
    0xffff8000, 0xffffc000, 0xffffe000, 0xfffff000,
    0xfffff800, 0xfffffc00, 0xfffffe00, 0xffffff00,
    0xffffff80, 0xffffffc0, 0xffffffe0, 0xfffffff0,
    0xfffffff8, 0xfffffffc, 0xfffffffe, 0xffffffff};
unsigned long int tabless[33] = {
    0,
    0x80000000,
    0x40000000,
    0x20000000,
    0x10000000,
    0x8000000,
    0x4000000,
    0x2000000,
    0x1000000,
    0x800000,
    0x400000,
    0x200000,
    0x100000,
    0x80000,
    0x40000,
    0x20000,
    0x10000,
    0x8000,
    0x4000,
    0x2000,
    0x1000,
    0x800,
    0x400,
    0x200,
    0x100,
    0x80,
    0x40,
    0x20,
    0x10,
    0x8,
    0x4,
    0x2,
    0x1,
};
int main()
{
    int n;
    char a;
    cin >> n;
    while (getchar() != '\n')
        ;
    node jilu[n];
    vector<node> newjilu;
    newjilu.reserve(n);

    unsigned long int temp = 0;
    for (int i = 0; i < n; ++i)
        //newjilu.push_back(input());
        jilu[i] = input();
    sort(jilu, jilu + n);
    //sort(newjilu.begin(),newjilu.end());

    for (int i = 0; i < n; ++i)
    {
        if (jilu[i].state)
            for (int j = i + 1; j < n; ++j)
                if (jilu[j].state)
                    if (jilu[i].p == jilu[j].p)
                        if (jilu[i].ip == jilu[j].ip)
                            jilu[j].state = 0;
                        else
                            break;
                    else if (jilu[i].p < jilu[j].p)
                        if (jilu[i].ip == (jilu[j].ip & tables[jilu[i].p]))
                            jilu[j].state = 0;
                        else
                            break;
                    else
                    {
                        if (jilu[j].ip == (jilu[i].ip & tables[jilu[j].p]))
                            jilu[i].state = 0;
                        break;
                    }
    }
    int pre = 0;
    for (int i = 0; i < n; ++i)
        if (jilu[i].state)
            for (int j = i + 1; j < n; ++j)
                if (jilu[j].state)
                {
                    if (jilu[i].p == jilu[j].p)
                        if ((jilu[i].ip ^ jilu[j].ip) == tabless[jilu[i].p])
                        {
                            //jilu[i].ip=jilu[i].ip^tables[jilu[i].p];
                            jilu[i].p -= 1;
                            jilu[j].state = 0;
                            for (int k = i - 1; k >= 0; --k)
                                if (jilu[k].state)
                                {
                                    i = k - 1;
                                    break;
                                }
                        }
                    break;
                }
    for (int i = 0; i < n; ++i)
        if (jilu[i].state)
        {
            char *temp = (char *)&jilu[i].ip;
            printf("%u.%u.%u.%u/%d\n", (0x0ff & *(temp + 3)), (0x00ff & *(temp + 2)), (0x00ff & *(temp + 1)), 0x00ff & *temp, jilu[i].p);
        }
    return 0;
}