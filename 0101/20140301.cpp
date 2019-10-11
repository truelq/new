#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;
int main()
{
    int num;
    int a;
    int count = 0;
    unordered_map<int, int> tables;
    unordered_map<int, int>::iterator iter;
    cin >> num;
    tables.reserve(1000000);
    while (num--)
    {
        cin >> a;
        ++tables[abs(a)];
    }
    for (iter = tables.begin(); iter != tables.end(); ++iter)
    {
        if (iter->second == 2)
            ++count;
    }
    cout<<count;
    return 0;
}