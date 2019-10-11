#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int table[5][5] = {
    0, -1, 1, 1, -1,
    1, 0, -1, 1, -1,
    -1, 1, 0, -1, 1,
    -1, -1, 1, 0, 1,
    1, 1, -1, -1, 0};
    int n, na, nb;
    cin >> n >> na >> nb;
    int a[na];
    int b[nb];
    int aa, bb;
    aa = bb = 0;
    for (int i = 0; i < na; ++i)
        cin >> a[i];
    for (int i = 0; i < nb; ++i)
        cin >> b[i];
    for (int i = 0; i < n; ++i)
    {
        int temp = table[a[i % na]][b[i % nb]];
        if (temp == 1)
            ++aa;
        else if (temp == -1)
            ++bb;
    }
    cout << aa << ' ' << bb << endl;
    return 0;
}