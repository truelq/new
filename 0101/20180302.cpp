#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
    int n, L, t;
    cin >> n >> L >> t;
    int a[n];
    int b[n];
    int speed[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        b[i] = a[i];
        speed[i] = 1;
    }
    sort(&a[0], &a[n]);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (b[i] == a[j]) {
                b[i] = j;
            }
        }
    }
    for (int i = 0; i < t; ++i) {
        for (int j = 0; j < n - 1; ++j) {
            if (a[j] == 0) {
                if (speed[j] == -1) {
                    speed[j] *= -1;
                }
            }
            if (a[j] == a[j + 1]) {
                if (speed[j] > speed[j + 1]) {
                    speed[j] *= -1;
                    speed[j + 1] *= -1;
                }
            }
            if (a[j] == L) {
                if (speed[j] == 1) {
                    speed[j] *= -1;
                }
            }
        }
        if (a[n - 1] == L) {
            if (speed[n - 1] == 1) {
                speed[n - 1] *= -1;
            }
        }
        for (int j = 0; j < n; ++j) {
            a[j] += speed[j];
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << a[b[i]] << ' ';
    }
    return 0;
}