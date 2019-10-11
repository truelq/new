#include <iostream>
#include<algorithm>
using namespace std;

int main()
{
    int a;
    int temp;
    int number = 0;
    cin >> a;

    int stables[a+1];
    for(int i=0;i<a;++i){
        cin>>stables[i];
    }
    sort(stables,stables+a);
    if (a == 1)
    {
        cout << 0;
        return 0;
    }
    else
        for (int i=0;i<a-1;++i)
        {
            if (stables[i]+1==stables[i+1])
                ++number;
        }
    cout<<number;
    return 0;
}