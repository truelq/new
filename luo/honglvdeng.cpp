#include <iostream>

using namespace std;

int main()
{
    long long r, y, g;
    long long all = 0;
    long n;
    long long k, t;
    long long times = 0;
    long long temp = 0;
    cin >> y >> r >> g;
    cin >> n;
    all = r + y + g;
    for (int i = 0; i < n; ++i) {
        cin >> k >> t;
        temp = times % all;
        if (k == 0) {
            times += t;

        } else if (k == 2) {
            if (((temp + r - t + all) % all) < (r + y)) {
                times += r + y - (temp + r - t + all) % all;
            }
        } else if (k == 1) {
            //cout << (temp - t + all) % all;
            if (((temp - t + all) % all) > g) {
                times += all - (temp - t + all) % all;
            }
        } else {
            if (((temp - t + all) % all) < (r + y)) {
                times += r + y - (temp - t + all) % all;
            }
        }
        cout << times<<endl;
    }
    cout << times;
    return 0;
}