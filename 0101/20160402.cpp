#include <iostream>

using namespace std;

int main()
{
    int tables[15][10];
    int shape[4][4];
    int lines;
    for (int i = 0; i < 15; ++i) {
        for (int j = 0; j < 10; ++j) {
            cin >> tables[i][j];
        }
    }
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            cin >> shape[i][j];
        }
    }
    cin >> lines;
    int flag = 0;
    int i = 0;
    for (i = 0; i < 18; ++i) {
        for (int k = 3; k >= 0; --k) {
            for (int l = 0; l < 4; ++l) {
                if (shape[k][l] == 1) {
                    if ((i + k - 3 >= 0) && (i + k - 3 < 15)) {
                        if (tables[i + k - 3][lines + l - 1] == 1) {
                            flag = 1;
                            break;
                        }
                    }
                }
            }
            if (flag)
                break;
        }
        if (flag)
            break;
    }
    for (int j = 0; j < 4; ++j) {
        for (int k = 0; k < 4; ++k) {
            if ((i - j - 1 >= 0) && (i - j - 1 < 15)) {
                if (tables[i - j - 1][k + lines - 1] || shape[3 - j][k]) {
                    tables[i - j - 1][k + lines - 1] = 1;
                }
            }
        }
    }
    for (int i = 0; i < 15; ++i) {
        for (int j = 0; j < 10; ++j) {
            cout << tables[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}