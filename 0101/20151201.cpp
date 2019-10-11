#include<iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int k;
    cin >> k;
    int sum = 0;
    while(k>0){
        sum += k % 10;
        k = k / 10;
    }
    cout << sum;
    getchar();
    getchar();
    return 0;
}
