#include<iostream>
#include<string.h>

#include<algorithm>
using namespace std;
//装箱问题，0-1背包w=v
int main(){
    int v,n;
    cin>>v>>n;
    int ss[n+1]={0};
    for(int i=1;i<=n;++i){
        cin>>ss[i];
    }
    sort(ss+1,ss+n+1);

    int save[n+1][v+1];
    memset(save,0,sizeof(save));
    for(int i=1;i<=n;++i){
        for(int j=0;j<ss[i];++j){
            save[i][j]=save[i-1][j];
        }
        for(int j=ss[i];j<=v;++j){
            save[i][j]=max(save[i-1][j],save[i-1][j-ss[i]]+ss[i]);
        }
    }
    cout<<v-save[n][v]<<endl;
}