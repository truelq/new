#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <vector>

using namespace std;
typedef struct {
    int gao;
    int fu;
    int shuai;
    int age;
    int num;
} man;
struct test {
    bool operator()(man a, man b)
    {
        if (a.shuai != b.shuai)
            return a.shuai > b.shuai;
        else if (a.gao != b.gao)
            return a.gao > b.gao;
        else if (a.fu != b.fu)
            return a.fu > b.fu;
        else if (a.age != b.age)
            return a.age < b.age;
        else
            return a.num < b.num;
    }
};

bool compare(man a, man b)
{
    if (a.shuai != b.shuai)
        return a.shuai > b.shuai;
    else if (a.gao != b.gao)
        return a.gao > b.gao;
    else if (a.fu != b.fu)
        return a.fu > b.fu;
    else if (a.age != b.age)
        return a.age < b.age;
    else
        return a.num < b.num;
}
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
    int n, k, i;
    n = input();
    k = input();
    //cin >> n >> k;
    priority_queue<man, vector<man>, test> gfs;
    man temp;
    vector<int > ans;
    ans.reserve(k );

    for (int i = 0; i < n; ++i) {
        temp.gao = input();
        temp.fu = input();
        temp.shuai = input();
        temp.age = input();
        //cin >> gfs[i].gao >> gfs[i].fu >> gfs[i].shuai >> gfs[i].age;
        temp.num = i + 1;
        if (gfs.size() < k)
            gfs.push(temp);
        else {
            if (compare(temp, gfs.top())) {
                gfs.pop();
                gfs.push(temp);
            }
        }
    }

    for(int i=0;i<k;++i){
        temp=gfs.top();
        gfs.pop();
        ans.push_back(temp.num);
    }
    for(int i=k-1;i>=0;--i){
        cout<<ans[i]<<' ';
    }
    while (!gfs.empty()) {
        temp = gfs.top();
        gfs.pop();
        cout << temp.num<<' ';
    }

    return 0;
}