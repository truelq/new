#include <iostream>

using namespace std;

int main()
{
    int n, m, p, q, temp;
    cin >> n >> m;
    int students[n + 1];
    for (int i = 0; i < n + 1; ++i)
        students[i] = i;
    for (int i = 0; i < m; ++i) {
        cin >> p >> q;
        for (int j = 1; j < n + 1; ++j) {
            if (students[j] == p)
                temp = j;
        }
        p = temp;
        temp = students[p];
        if (q > 0) {
            for (int j = p; j < p + q; ++j) {
                students[j] = students[j + 1];
            }
            students[p + q] = temp;
        } else {
            for (int j = p; j > p + q; --j) {
                students[j] = students[j - 1];
            }
            students[p + q] = temp;
        }
    }
    for (int i = 1; i < n + 1; ++i) {
        cout << students[i] << ' ';
    }
    return 0;
}