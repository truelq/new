#include<iostream>
#include<stdio.h>
#include<string.h>
#include<vector>

using namespace std;
//宝物筛选，多重背包经典
int main(){
    int n,W;
    cin>>n>>W;

    unsigned v;
    unsigned w;
    unsigned m;
    vector<unsigned> vv;
    vector<unsigned> ww;
    vv.push_back(0);
    ww.push_back(0);
    for(int i=1;i<=n;++i){
        scanf("%d %d %d",&v,&w,&m);
        for(int j=1;j<=m;j<<=1){
            vv.push_back(v*j);
            ww.push_back(w*j);
            m-=j;
        }
        if(m){
            vv.push_back(m*v);
            ww.push_back(m*w);
        }
    }
    unsigned save[W+1]={0};
    memset(save,0,sizeof(save));
    for(int i=1;i<vv.size();++i){
        for(int j=W;j>=ww[i];--j){
            save[j]=max(save[j],save[j-ww[i]]+vv[i]);
        }
    }
    //printf("%u\n",save[W]);
    cout<<save[W]<<endl;
    //delete[] save;
    return 0;

}