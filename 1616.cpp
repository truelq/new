#include<iostream>

#include<cstring>
#include<algorithm>

using namespace std;
struct P1048
{
    int t;
    int v;
};
bool compare(P1048 a,P1048 b){

};
int main(){
    int n,m;
    cin>>m>>n;
    P1048 ss[n+1];
    memset(ss,0,sizeof(ss));
    for(int i=0;i<n;++i){
        cin>>ss[i].t>>ss[i].v;
    }
    int save[m+1]={0};
    for(int i=0;i<n;++i){
        for(int j=m;j>=ss[i].t;--j){
            save[j]=max(save[j],save[j-ss[i].t]+ss[i].v);
        }
    }
    cout<<save[m]<<endl;
}