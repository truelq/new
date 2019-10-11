#include<iostream>

using namespace std;

int main(){
    int n;
    cin>>n;
    int table[n+1]={0};
    int tables[n+1]={0};
    int temp=0;
    for(int i=0;i<n;++i){
        for(int j=0;j<i+1;++j){
            cin>>temp;
            temp=temp+(table[j-1>=0?j-1:0]>table[j]?table[j-1>=0?j-1:0]:table[j]);
            tables[j]=temp;
        }
        for(int j=0;j<n;++j){
            table[j]=tables[j];
        }
    }
    for(int i=0;i<n;++i){
        if(temp<table[i])
        temp=table[i];
    }
    cout<<temp<<endl;
    return 0;
}