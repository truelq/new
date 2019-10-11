#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std;

typedef unsigned short ushort;

const int N = 6e4 + 5;

struct Query {
    int id, l, r, fir;
    bool operator < (const Query & q2) const {
        return fir < q2.fir || (fir == q2.fir && r < q2.r);
    }
} q[N];

int n, m, b, a[N], ans[N], now;
int st[N][26], len[N]; //有用状态 
char s[N];
ushort c[1 << 26]; //桶 
bool tag[1 << 26]; //a的访问标记 

void ins(int x) { //insert
    now += c[a[x]] ++;
    for(ushort i = 0; i < len[x]; i ++)
        now += c[st[x][i]];
}

void del(int x) { //delete
    now -= -- c[a[x]];
    for(ushort i = 0; i < len[x]; i ++)
        now -= c[st[x][i]];
}

int main() {
    scanf("%d%d%s", &n, &m, s + 1);
    b = (int) (n / sqrt(m)); //block size
    for(ushort i = 0; i <= n; i ++) {
        a[i] = i ? a[i - 1] ^ (1 << (s[i] - 'a')) : 0;
        tag[a[i]] = 1;
    }
    for(ushort i = 0; i <= n; i ++) {
        for(ushort j = 0; j < 26; j ++) {
            if(tag[a[i] ^ (1 << j)]) {
                st[i][len[i] ++] = a[i] ^ (1 << j);
            }
        }
    }
    for(ushort i = 1; i <= m; i ++) {
        scanf("%d%d", &q[i].l, &q[i].r);
        q[i].fir = q[i].l / b;
        q[i].id = i;
    }
    sort(q + 1, q + m + 1);
    int l = q[1].l, r = q[1].l - 1;
    c[a[l - 1]] ++;
    for(ushort i = 1; i <= m; i ++) {
        while(l > q[i].l) ins(-- l - 1);
        while(r < q[i].r) ins(++ r);
        while(l < q[i].l) del(l ++ - 1);
        while(r > q[i].r) del(r --);
        ans[q[i].id] = now;
    }
    for(int i = 1; i <= m; i ++)
        printf("%d\n", ans[i]);
    return 0;