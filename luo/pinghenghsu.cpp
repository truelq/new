#include <iostream>

using namespace std;

int main()
{
    int n, m, l, r;
    cin >> n >> m;

    int nums[n + 1];
    int back[n + 1];
    for (int i = 0; i < n + 1; ++i) {
        nums[i] = back[i] = i;
    }
    for (int i = 0; i < m; ++i) {
        cin >> l >> r;
        for (int j = 0; j <= r - l; ++j) {
            nums[j + l] = back[r - j];
        }
        for (int i = 0; i < n + 1; ++i) {
            back[i] = nums[i];
        }
    }
    for (int i = 1; i < n + 1; ++i)
        cout << nums[i] << ' ';
    return 0;
}