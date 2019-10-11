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
    int m, n;
    vector<int> circle;

    n = input();
    m = input();
    for (int i = 0; i < n; ++i) {
        circle.push_back(i + 1);
    }

    int k = 0;
    int base = -1;
    vector<int>::iterator iter;

    while (!circle.empty()) {
        iter = circle.begin();
        base += m;
        base %= circle.size();
        iter += (base ) % circle.size();
        cout << *iter<<' ';
        circle.erase(iter);
        base-=1;
        //base%=circle.size();
    }
    return 0;
}