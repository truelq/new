#include<iostream>

using namespace std;

int main(){
    int n;
    int table[10001]={0};
    int temp;
    table[0]=1;
    table[1]=2;
    int last=1;
    cin>>n;
    while (n--)
    {
        cin>>temp;
        if(last<temp){
            for(int i=last+1;i<=temp;++i){
                table[i]=table[i-1]+4*i-3;
            }
            last=temp;
        }
        cout<<table[temp]<<endl;
    }
    return 0;
    
}