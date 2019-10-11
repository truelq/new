#include <iostream>
#include <vector>

using namespace std;

struct point
{
    long  int x;
    long int y;
    bool reachsourth = false;
    bool reachaim = false;
};
int main(int argc, char const *argv[])
{
    int n, m, k, r;
    vector<point> exists;
    vector<point> newins;
    struct point sourth;
    struct point aim;
    struct point temp;

    cin >> n >> m >> k >> r;
    for (int i = 0; i < n; ++i)
    {
        cin >> temp.x >> temp.y;

        exists.push_back(temp);
    }
    for (int i = 0; i < m; ++i)
    {
        cin >> temp.x >> temp.y;
        newins.push_back(temp);
    }
    return 0;
}
