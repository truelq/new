#include <iostream>

using namespace std;
struct point {
    int x;
    int y;
};

int main()
{
    int n;
    cin >> n;
    point begin[n];
    point end[n];
    for (int i = 0; i < n; ++i) {
        cin >> begin[i].x >> begin[i].y >> end[i].x >> end[i].y;
    }
    int counts = 0;
    for (int i = 0; i < 100; ++i) {
        for (int j = 0; j < 100; ++j) {
            for (int k = 0; k < n; ++k) {
                if (i >= begin[k].x && i < end[k].x)
                    if (j >= begin[k].y && j < end[k].y) {
                        ++counts;
                        break;
                    }
            }
        }
    }
    cout << counts;
    return 0;
}