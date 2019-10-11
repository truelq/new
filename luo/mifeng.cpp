#include<iostream>

using namespace std;

int main(){
    int n;
    unsigned long int table[51]={0};
    int last=0;
    int a,b;

    table[0]=0;
    table[1]=1;
    table[2]=2;
    last=2;
    cin>>n;
    for(int i=3;i<=40;++i)
    table[i]=table[i-1]+table[i-2];
    while (n--)
    {
        cin>>a;
        a=a-1;
        
        cout<<table[a]<<endl;
    }
    return 0;
    
}