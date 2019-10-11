#include <iostream>
#include <vector>

using namespace std;
int input()
{
    char ch = ' ';
    while (ch < '0' || ch > '9')
        ch = getchar();
    int x = 0;
    while (ch <= '9' && ch >= '0')
        x = x * 10 + ch - '0', ch = getchar();
    return x;
}

int main()
{
    int k = input();
    int k2 = 2 * k;
    int points;
    int i;
    int j;
    
    for (i = k + 1;; ++i) {
        if (i - 1 % k2 >= k) {
            if (i % (k + 1) < 2) {
                points = 0;
                for (j = 1; j <= k; ++j) {
                    points = (points + i - 1) % (k2 + 1 - j);
                    if (points < k)
                        break;
                    if (j == k) {
                        cout << i;
                        return 0;
                    }
                }
            }
        }
    }

    return 0;
}