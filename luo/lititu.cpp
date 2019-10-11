#include <iostream>
#include <string>

using namespace std;

int main()
{
    int m, n;
    cin >> m >> n;
    int l = 4 * n + 1 + 2 * m;
    int tag[m][n];
    int temp = 0;
    int high = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> tag[i][j];
            temp = 2 * (m - i) + 1 + 3 * tag[i][j];
            if (high < temp)
                high = temp;
        }
    }
    char tables[high][l];
    for (int i = 0; i < high; ++i) {
        for (int j = 0; j < l; ++j) {
            tables[i][j] = '.';
        }
    }

    int y = high - 1;
    int x = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < tag[i][j]; ++k) {
                y = high - (m - i - 1) * 2 - k * 3 - 1;
                x = 4 * j + (m - i - 1) * 2;
                tables[y][x] = '+';
                tables[y][x + 1] = '-';
                tables[y][x + 2] = '-';
                tables[y][x + 3] = '-';
                tables[y][x + 4] = '+';

                tables[y - 1][x] = '|';
                tables[y - 1][x + 1] = ' ';
                tables[y - 1][x + 2] = ' ';
                tables[y - 1][x + 3] = ' ';
                tables[y - 1][x + 4] = '|';
                tables[y - 1][x + 5] = '/';

                tables[y - 2][x] = '|';
                tables[y - 2][x + 1] = ' ';
                tables[y - 2][x + 2] = ' ';
                tables[y - 2][x + 3] = ' ';
                tables[y - 2][x + 4] = '|';
                tables[y - 2][x + 5] = ' ';
                tables[y - 2][x + 6] = '+';

                tables[y - 3][x] = '+';
                tables[y - 3][x + 1] = '-';
                tables[y - 3][x + 2] = '-';
                tables[y - 3][x + 3] = '-';
                tables[y - 3][x + 4] = '+';
                tables[y - 3][x + 5] = ' ';
                tables[y - 3][x + 6] = '|';

                tables[y - 4][x + 1] = '/';
                tables[y - 4][x + 2] = ' ';
                tables[y - 4][x + 3] = ' ';
                tables[y - 4][x + 4] = ' ';
                tables[y - 4][x + 5] = '/';
                tables[y - 4][x + 6] = '|';

                tables[y - 5][x + 2] = '+';
                tables[y - 5][x + 3] = '-';
                tables[y - 5][x + 4] = '-';
                tables[y - 5][x + 5] = '-';
                tables[y - 5][x + 6] = '+';
            }
        }
    }

    for (int i = 0; i < high; ++i) {
        for (int j = 0; j < l; ++j) {
            cout << tables[i][j];
        }
        cout << endl;
    }
}