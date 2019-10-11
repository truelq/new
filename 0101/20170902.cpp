#include <algorithm>
#include <iostream>
using namespace std;
struct teacher {
    //int begin;
    //int end;
    int time;
    int key;
    int state;
};
bool compare(teacher a, teacher b)
{
    if (a.time == b.time)
        return a.key < b.key;
    return a.time < b.time;
}
int main()
{
    int N, K;
    int start, end, key;
    cin >> N >> K;
    int keys[N + 1];

    teacher saves[2 * K + 1];

    for (int i = 0; i < K; ++i) {
        cin >> key >> start >> end;
        saves[2 * i + 1].time = start;
        saves[2 * i + 1].key = key;
        saves[2 * i + 1].state = 0;
        saves[2 * i + 2].time = start + end;
        saves[2 * i + 2].key = key;
        saves[2 * i + 2].state = 1;
    }
    for (int i = 0; i < N + 1; ++i) {
        keys[i] = i;
    }
    sort(&saves[1], &saves[2 * K + 1], compare);
    for (int i = 1; i < 2 * K + 1; ++i) {
        if (saves[i].state) {
            for (int j = 1; j < N + 1; ++j) {
                if (!keys[j]) {
                    keys[j] = saves[i].key;
                    break;
                }
            }
        } else {
            for (int j = 1; j < N + 1; ++j) {
                if (keys[j] == saves[i].key)
                    {keys[j] = 0;
                    break;}
            }
        }
    }
    for (int i = 1; i < N + 1; ++i) {
        cout << keys[i] << ' ';
    }
    return 0;
}