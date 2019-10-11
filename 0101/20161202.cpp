#include <iostream>

using namespace std;

int main()
{
    int tables[] = { 3500, 1500, 3000, 4500, 26000, 20000, 25000 };
    int sss[] = { 3500, 5000, 8000, 12500, 38500, 58500, 83500 };
    int ttt[] = { 97, 90, 80, 75, 70, 65, 55 };
    int max[7];
    int temp;
    cin >> temp;
    int i = 0;
    max[i] = tables[i];
    ++i;
    max[i] = max[i - 1] + tables[i] * 97 / 100;
    ++i;
    max[i] = max[i - 1] + tables[i] * 90 / 100;
    ++i;
    max[i] = max[i - 1] + tables[i] * 80 / 100;
    ++i;
    max[i] = max[i - 1] + tables[i] * 75 / 100;
    ++i;
    max[i] = max[i - 1] + tables[i] * 70 / 100;
    ++i;
    max[i] = max[i - 1] + tables[i] * 65 / 100;
    if (temp <= 3500) {
        cout << temp;
        return 0;
    }
    for (i = 0; i < 7; ++i) {
        if (i == 6) {
            cout << sss[i] + (temp - max[i]) * 100 / 55;
        }
        if (temp > max[i] && temp <= max[i + 1]) {
            cout << sss[i] + (temp - max[i]) * 100 / ttt[i];
            break;
        }
    }
    return 0;
}