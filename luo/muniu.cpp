#include <iostream>
using namespace std;

struct muniu
{
    long one = 0;
    long two = 0;
    long three = 0;
    //long four=0;
    long mu = 0;
    int year = 0;
};

int main()
{
    int year = 0;
    muniu a[56];
    int flag[56] ={0};
    muniu temp;
    temp.mu=1;
    temp.year=1;
    while (cin >> year && year)
    {
        int last = 0;
        for (int i = 0; i < year; ++i)
            if (flag[i])
                last = i;
        if (last)
            temp = a[last];
        for(int i=temp.year;i<year;++i){
            temp.mu+=temp.three;
            temp.three=temp.two;
            temp.two=temp.one;
            temp.one=temp.mu;
        }
        cout<<temp.mu+temp.one+temp.two+temp.three<<endl;
        temp.year=year;
        a[year]=temp;
        flag[year]=1;
        temp.one=0;
        temp.two=0;
        temp.three=0;
        temp.mu=1;
        temp.year=1;
    }
    return 0;
}