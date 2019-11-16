#include<bits/stdc++.h>


using namespace std;

int ss[301][301];
int save[301][301];
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            scanf("%d",&ss[i][j]);
        }
    }
    memcpy(save,ss,sizeof(ss));
    for(int k=1;k<=n;++k){
        for(int i=1;i<=n;++i){
            for(int j=1;j<=n;++j){
                ss[i][j]=min(ss[i][j],ss[i][k]+ss[k][j]);
            }
        }
    }
    int ans=0;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=i;++j){
            ans+=ss[i][j];
        }
    }
    int m;
    cin>>m;
    int a,b,c;
    for(int i=0;i<m;++i){
        scanf("%d%d%d",&a,&b,&c);
        if(ss[a][b]>c){
            
            ss[a][b]=c;
            ss[b][a]=c;
        }
    }

}