#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <map>
#include <stack>
using namespace std;
const int maxn = 1e3 + 10;
char st[maxn][80000+5];
bool vis[maxn];
int main() {
    int n, s, l, m, len;
    scanf("%d %d %d", &n, &s, &l);
    int temp = -1;
    for(int i = 0; i < l; ++i) {
        scanf("%d ", &temp);
        fgets(st[temp],85000,stdin);
        vis[temp] = 1;
    }
    len = strlen(st[temp]);
    scanf("%d", &m);

    while(m--) {
        int row = 1, col = 0;
        scanf("%d", &temp);

        if(temp >= (len / 8) * (n-1) ) {//如果超出范围，直接输出
            puts("-"); continue;
        }
        while(row * (n-1) * s <= temp) {//判断在哪一行
            ++row;
        }
        --row;

        col = ((n - row) + (temp - row * (n - 1) * s) / s) % n;//判断在哪个磁盘

        int offset = (temp - row * (n - 1) * s) % s;//判断在磁盘的具体那一部分

        int block = row * s + offset;


        if(vis[col]) {
            for(int i = 0; i < 8; ++i) {
                printf("%c", st[col][i + block * 8]);
            }
            printf("\n");
        } else if(n - l == 1){
            for(int i = 0; i < 8; ++i) {
                int ans = 0;
                char c;
                for(int j = 0; j < n; ++j) {
                    if(j == col) continue;
                    c = st[j][i + block * 8];

                    if(c >= '0' && c <= '9') ans ^= int(c -'0');
                    else ans ^= int(c - 'A') + 10;
                   // printf("1ans : %d\n", ans);
                }
                if(ans > 9) printf("%c", char('A'+ans - 10));
                else printf("%c", char(ans+'0'));

            }
            printf("\n");
        } else {
            puts("-");
        }
    }
    return 0;
}
/*
2 1 2
0 000102030405060710111213141516172021222324252627
1 000102030405060710111213141516172021222324252627
3
0
1
2

3 2 2
0 000102030405060710111213141516172021222324252627
1 A0A1A2A3A4A5A6A7B0B1B2B3B4B5B6B7C0C1C2C3C4C5C6C7
13
0
1
2
3
4
5
6
7
8
9
10
11
12

3 2 1
0 000102030405060710111213141516172021222324252627
3
0
1
2

4 2 2
0 000102030405060710111213141516172021222324252627
1 A0A1A2A3A4A5A6A7B0B1B2B3B4B5B6B7C0C1C2C3C4C5C6C7
13
0
1
2
3
4
5
6
7
8
9
10
11
12
*/

