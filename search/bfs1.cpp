#include<bits/stdc++.h>

using namespace std;

int ss[501][501];
queue<int> dfs;
int main(){
    int m,n;
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            scanf("%d",&ss[i][j]);
        }
    }
    for(int j=1;j<=m;++j){
        dfs.push(ss[n][j]);
    }
}