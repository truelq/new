#include <iostream>
#include <stdio.h>
#include <map>
#include <vector>
#include <unordered_map>

using namespace std;

int main()
{
    unordered_map<int, int> counts;
    unordered_map<int, int> remember;
    int num = 0;
    cin >> num;
    int a;
    int most = 0;
    int number = 0;
    int b;

    unordered_map<int, int>::iterator iter;
    vector<int> temp;
    counts.reserve(1000000);
    while (num--)
    {
        cin >> a;
        b = ++counts[a];
        if (b > most)
        {
            most = b;
            number = a;
            temp.clear();
        }
        else if (b == most)
        {
            temp.push_back(a);
        }
    }
    if (temp.size())
    {
        for (int i = 0; i < temp.size(); ++i)
        {
            if (number > temp[i])
                number = temp[i];
        }
    }
    cout << number;
    return 0;
}