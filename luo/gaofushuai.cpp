#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
typedef struct {
    int gao;
    int fu;
    int shuai;
    int age;
    int num;
} man;

bool compare(man a, man b)
{
    if (a.shuai != b.shuai)
        return a.shuai > b.shuai;
    else if (a.gao != b.gao)
        return a.gao > b.gao;
    else if (a.fu != b.fu)
        return a.fu > b.fu;
    else if (a.age != b.age)
        return a.age < b.age;
    else
        return a.num < b.num;
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

int main()
{
    int n, k, i;
    n=input();
    k=input();
    //cin >> n >> k;
    man gfs[n];
    int x[k];
    int x_high[k];
    vector<man> ans;
    ans.reserve(k * 2);

    for (int i = 0; i < n; ++i) {
        gfs[i].gao =input();
        gfs[i].fu =input();
        gfs[i].shuai =input();
        gfs[i].age =input();
        //cin >> gfs[i].gao >> gfs[i].fu >> gfs[i].shuai >> gfs[i].age;
        gfs[i].num = i + 1;
    }

    int nums = n / k;
    for (i = 0; i < k - 1;) {
        x[i] = nums * i;
        sort(gfs + x[i], gfs + nums * (1 + i), compare);
        x_high[i] = nums * (i + 1);
        ++i;
        //x_high[i] = nums * i;
    }
    x[i] = nums * i;
    x_high[i] = n;
    sort(gfs + x[i], gfs + n, compare);
    i = k;
    int j = 0;
    man min;
    while (i) {
        min = gfs[x[0]];
        ans.push_back(gfs[x[0]]);
        x[0] += 1;
        for (j = 1; j < k; ++j) {
            for (int l = x[j]; l < x_high[j]; ++l) {
                if (compare(gfs[l], min)) {
                    ans.push_back(gfs[l]);
                    if (l + 1 == x_high[j])
                        x[j] = x_high[j];
                } else {
                    x[j] = l;
                    break;
                }
            }
        }
        if (ans.size() >= k)
            break;
    }

    sort(ans.begin(), ans.end(), compare);
    for (int i = 0; i < k; ++i) {
        cout << ans[i].num << ' ';
    }

    return 0;
}