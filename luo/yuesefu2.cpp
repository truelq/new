#include <iostream>

#include <unordered_map>

using namespace std;

int main()
{
    int n;
    int points[100001];
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        points[i] = i + 1;
    }
    points[n] = 1;
    int last = n;
    int current = n;
    while (true) {
        for (int i = 1;; i = points[i]) {
            points[i] = points[points[i]];
            if (i == points[i]) {
                current = i;
                break;
            }
        }
        if (last == current) {
            cout << n + current;
            break;
        }
        last = current;
        for (int i = 1; i <= current; ++i) {
            points[i] = i + 1;
        }
        points[current] = 1;
    }
}