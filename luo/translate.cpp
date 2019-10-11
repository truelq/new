#include <iostream>
#include <queue>
#include <vector>

using namespace std;
int main()
{
    int m, n;
    int temp;
    int flag = 0;
    vector<int> memary;
    vector<int>::iterator iter;
    int counts = 0;
    cin >> m >> n;
    for (int i = 0; i < n; ++i) {
        cin >> temp;
        if (memary.empty()) {
            memary.push_back(temp);
            ++counts;
        } else {
            flag = 0;
            for (iter = memary.begin(); iter != memary.end(); ++iter) {
                if (temp == *iter) {
                    flag = 1;
                    break;
                }
            }
            if (flag)
                continue;
            else {
                if (memary.size() < m) {
                    memary.push_back(temp);
                } else {
                    iter = memary.begin();
                    memary.erase(iter);
                    memary.push_back(temp);
                }
                ++counts;
            }
        }
    }
    cout << counts;
    return 0;
}