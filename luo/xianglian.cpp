#include <iostream>
#include <set>
#include <unordered_set>
using namespace std;

int main()
{
    int N;
    cin >> N;
    int xianglian[N];
    for (int i = 0; i < N; ++i)
        scanf("%d", xianglian + i);

    int M;
    cin >> M;
    int a[M], b[M];
    for (int i = 0; i < M; ++i)
        scanf("%d %d", a + i, b + i);

    unordered_set<int> temp;
    temp.reserve(N);
    for (int i = 0; i < M; ++i) {

        temp.clear();
        for (int j = a[i] - 1; j < b[i]; ++j)
            temp.insert(xianglian[j]);
        cout << temp.size() << endl;
    }
    return 0;
}