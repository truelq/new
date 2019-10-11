#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int ditanx[n];
    int ditany[n];
    int ditanl[n];
    int ditanh[n];
    int x, y;

    for (int i = 0; i < n; ++i) {
        cin >> ditanx[i] >> ditany[i] >> ditanl[i] >> ditanh[i];
    }
    cin >> x >> y;
    for (int i = n - 1; i >= 0; --i) {
        if (x >= ditanx[i] && y >= ditany[i]) {
            if (x - ditanx[i] <= ditanl[i] && y - ditany[i] <= ditanh[i]) {
                cout << i + 1;
                return 0;
            }
        }
    }
    cout << -1;
    return 0;
}