#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string.h>

using namespace std;
//0-1背包v=wi*vsi
int main(){
    int n,m;
    cin>>n>>m;
    int w[m+1];
    int vs[m+1];
    for(int i=1;i<=m;++i){
        scanf("%d %d",w+i,vs+i);
    }
    w[0]=0;
    vs[0]=0;
    int save[m+1][n+1];
    memset(save,0,sizeof(save));
    for(int i=1;i<=m;++i){
        for(int j=1;j<=n;++j){
            if(j<w[i]){
                save[i][j]=save[i-1][j];
            }else{
                save[i][j]=max(save[i-1][j],save[i-1][j-w[i]]+vs[i]*w[i]);
            }
        }
    }
    cout<<save[m][n]<<endl;
    return 0;
}