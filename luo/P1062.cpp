#include <iostream>

using namespace std;

int main()
{
    unsigned int a, n;
    cin >> a >> n;
    long long int temp = 1;
    long long int ans = 0;
    while (n)
    {
        if (n & 1)
            ans += temp;
        temp *= a;
        n >>= 1;
    }
    cout<<ans<<endl;
    return 0;
}