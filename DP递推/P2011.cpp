#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <unordered_map>
#include <algorithm>
using namespace std;
//unsigned long long save[2000000000];

int main()
{
    //FILE *file = fopen("C:\\Users\\32125\\Documents\\vscodec\\DP\\testdata.in", "r");
    //if (file == nullptr)
    //    cout << "aaaa";

    unsigned long long n, m;
    cin >> n >> m;
    //fscanf(file, "%llu %llu", &n, &m);
    unsigned long long *ss = new unsigned long long[n + 1];

    unsigned long long tempmax = 0;
    for (unsigned long long i = 0; i < n; ++i)
    {
        scanf("%llu", ss + i);
        //fscanf(file, "%llu", ss + i);
        //tempmax = max(tempmax, ss[i]);
    }

    ss[n] = m+1;
    sort(ss, ss + n + 1);
    //unsigned long long *save = new unsigned long long[tempmax + 1];
    unsigned long long maxs = 0;
    unsigned long long temp = 0;
    //memset(save, 0x7f, sizeof(save));
    //save[0] = 0;

    if (ss[0] != 1)
    {
        cout << "No answer!!!" << endl;
        delete[] ss;
        //delete[] save;
        return 0;
    }
    unsigned long long current = 0;
    //unsigned long long a = m / ss[n-1];
    //unsigned long long b = m % ss[n-1];
    maxs = 0;
    maxs = 1;
    current = 1;
    for (unsigned long long i = 1; i <= n; ++i)
    {
        temp = ss[i] - ss[i - 1];
        if (temp)
            temp -= 1;

        maxs += temp / ss[i - 1];
        current += temp / ss[i - 1] * ss[i - 1];
        temp = temp % ss[i - 1];
        if (temp >= current)
        {
            maxs += 1;
            current = ss[i - 1] + current;
        }

        if (ss[i] == m+1)
        {
            break;
        }
    }
   // cout << m / ss[n - 1] << endl;
    //current-=1;
    //while(b){
    //    if(b>=ss[current]){
    //b-=ss[current];
    //       maxs+=b/ss[current];
    //       b=b%ss[current];
    //   }else{
    //  --current;
    //  }
    //cout<<maxs<<endl;
    //cout<<current<<endl;
    //}
    cout << maxs << endl;
    delete[] ss;
    //delete[] save;
    return 0;
}