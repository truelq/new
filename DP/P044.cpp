#include<iostream>

using namespace std;

//单调栈
int main(){
    int n;
    cin>>n;

    int ans=0;
    int save[n+1]={0};
    save[1]=1;
    save[0]=1;
    for(int i=2;i<=n;++i){
        for(int j=0;j<i;++j){
            save[i]+=save[j]*save[i-j-1];
        }
    }
    cout<<save[n]<<endl;
}