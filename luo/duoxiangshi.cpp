#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;
    int temp;
    string x = "x^";
    cin >> n;
    if (n == 0) {
        cin >> temp;
        cout << temp;
        return 0;
    }
    if (n == 1) {
        cin >> temp;
        if (abs(temp) == 1) {
            if (temp < 0)
                cout << '-';
            cout << 'x';
        } else {
            cout << temp << 'x';
        }
        cin >> temp;
        if (temp > 0) {
            cout << '+' << temp;
        } else if (temp < 0)
            cout << temp;
        return 0;
    }
    for (int i = 0; i <= n; ++i) {
        cin >> temp;
        if (i == 0) {
            if (abs(temp) == 1) {
                if (temp < 0)
                    cout << '-';
                cout << x << n - i;
            } else {
                cout << temp << x;
                cout << n - i;
            }
        } else if (i == n - 1) {
            if (abs(temp) == 1) {
                if (temp < 0) {
                    cout << '-';
                } else {
                    cout << '+';
                }
                cout << 'x';
            } else if (temp > 0) {
                cout << '+' << temp << 'x';
            } else if (temp < 0) {
                cout << temp << 'x';
            } else {
                continue;
            }
        } else if (i == n) {
            if (temp > 0) {
                cout << '+' << temp;
            } else if (temp < 0)
                cout << temp;
        } else {
            if (abs(temp) == 1) {
                if (temp < 0) {
                    cout << '-';
                } else {
                    cout << '+';
                }
                cout << x << n - i;
            } else if (temp > 0) {
                cout << '+' << temp << x << n - i;
            } else if (temp < 0) {
                cout << temp << x << n - i;
            } else {
                continue;
            }
        }
    }
}