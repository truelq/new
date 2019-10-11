#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main()
{
    int n, m;
    int a, b, c, i;
    vector<int> ans;

    int big = 0;
    int fun = 0;
    cin >> n >> m;
    int save[n][3];
    int base[n];
    int x[n] = { 0 };
    int xx = 0;
    int temp;
    for (int i = 0; i < n; ++i) {
        cin >> save[i][0] >> save[i][1] >> save[i][2];
        x[i]=1;
    }
    int times = m * 5;
    ans.reserve(times);
    for (int i = 0; i < n; ++i)
        base[i] = save[i][2];
    while (times > 0) {
        big = save[0][0] * (xx + 5) * (xx + 5) + save[0][1] * (xx + 5) + save[0][2];
        for (int i = 0; i < n; ++i) {
            for (int j = x[i];; ++j) {
                temp = save[i][0] * j * j + save[i][1] * j + save[i][2];
                if (temp <= big) {
                    ans.push_back(temp);
                    --times;
                } else {
                    x[i] = j;
                    break;
                }
            }
        }
        xx += 5;
    }
    sort(ans.begin(), ans.end());

    m -= 1;
    for (i = 0; i < m; ++i) {
        cout << ans[i] << ' ';
    }
    cout << ans[i];
    return 0;
}