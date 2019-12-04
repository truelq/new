#include<iostream>
#include<stdlib.h>

using namespace std;
unsigned long long save[22][22];
int main(){
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    save[1][1]=1;
    for(int i=1;i<=a+1;++i){
        for(int j=1;j<=b+1;++j){
            if(i==1&&j==1)
            continue;
            save[i][j]=save[i-1][j]+save[i][j-1];
            if(abs(i-c-1)==1&&abs(j-1-d)==2||abs(i-1-c)==2&&abs(j-1-d)==1||i==(c+1)&&j==(d+1)){
                save[i][j]=0;
            }
        }
    }
    cout<<save[a+1][b+1]<<endl;
    return 0;
}