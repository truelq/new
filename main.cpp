#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main()
{
    //输入
    vector<int> A, B, ans;
    int N;
    int temp;
    //unordered_map<int, int> points;
    //points.reserve(N);
    A.reserve(N);
    B.reserve(N);
    ans.reserve(N * 2);

    cin >> N;
    int points[N] = { 0 };
    int pointsb[N] = { 0 };
    int a = N;
    while (a--) {
        cin >> temp;
        A.push_back(temp);
    }
    a = N;
    while (a--) {
        cin >> temp;
        B.push_back(temp);
    }
    //开始
    a = 2 * N;

    int aa, bb, big;
    int tempa, tempb;
    aa = bb = tempa = tempb = 0;
    //int litte_max = 0;
    int lowa = 0;
    int lowb = 0;

    ans.push_back(A[aa] + B[bb]);

    while (a > 0) {
        if (bb + 1 >= N)
            break;
        ans.push_back(A[aa] + B[bb + 1]);
        points[aa] = bb + 2;
        pointsb[bb] = aa + 2;
        ans.push_back(A[++aa] + B[bb++]);
        a -= 2;
        big = A[aa] + B[bb];
        ans.push_back(big);

        for (int i = lowa; i < aa; ++i) {
            for (int j = points[i]; j < N; ++j) {
                temp = A[i] + B[j];
                if (temp <= big) {
                    ans.push_back(temp);
                    if (j == N - 1)
                        points[i] = N;
                    a -= 1;
                } else {
                    points[i] = j;
                    break;
                }
            }
            if (points[i] >= N)
                ++lowa;
        }
        for (int i = lowb; i < bb; ++i) {
            for (int j = pointsb[i]; j < N; ++j) {
                temp = A[j] + B[i];
                if (temp <= big) {
                    ans.push_back(temp);
                    if (j == N - 1)
                        pointsb[i] = N;
                    a -= 1;
                } else {
                    pointsb[i] = j;
                    break;
                }
            }
            if (pointsb[i] >= N)
                ++lowb;
        }
    }

    sort(ans.begin(), ans.end());
    //输出
    N -= 1;
    for (a = 0; a < N; ++a)
        cout << ans[a] << ' ';
    cout << ans[N];
    return 0;
}
