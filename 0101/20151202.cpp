#include <iostream>

using namespace std;
struct cell {
    int color;
    int state;
};

int main()
{
    int n, m;
    cin >> n >> m;
    cell tables[n][m];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> tables[i][j].color;
            tables[i][j].state = 1;
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m - 2; ++j) {
            if (tables[i][j].color == tables[i][j + 1].color && tables[i][j + 2].color == tables[i][j].color) {
                //tables[i][j].color=tables[i][j+1].color=tables[i][j+2].color=0;
                tables[i][j].state = tables[i][j + 1].state = tables[i][j + 2].state = 0;
                for (int k = j + 1; k < m; ++k) {
                    if (tables[i][k].color == tables[i][j].color)
                        tables[i][k].state = 0;
                    else
                        break;
                }
            }
        }
    }
    for (int i = 0; i < n - 2; ++i) {
        for (int j = 0; j < m; ++j) {
            if (tables[i][j].color == tables[i + 1][j].color && tables[i + 2][j].color == tables[i][j].color) {
                //tables[i][j].color=tables[i][j+1].color=tables[i][j+2].color=0;
                tables[i][j].state = tables[i + 1][j].state = tables[i + 2][j].state = 0;
                for (int k = i + 1; k < n; ++k) {
                    if (tables[k][j].color == tables[i][j].color)
                        tables[k][j].state = 0;
                    else
                        break;
                }
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (tables[i][j].state)
                cout << tables[i][j].color << ' ';
            else
                cout << 0 << ' ';
        }
        cout << endl;
    }
    return 0;
}