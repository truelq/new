#include<iostream>
#include<stdlib.h>
#include<cstring>
#include<algorithm>

using namespace std;
struct P1048
{
    unsigned int t;
    unsigned int v;
};
bool compare(P1048 a,P1048 b){
    return a.t<b.t;
};
int main(){
    int n,m;
    //freopen("testdata.in","r",stdin);
    cin>>m>>n;
    P1048 *ss=new P1048[n+1];
    memset(ss,0,sizeof(ss));
    for(int i=0;i<n;++i){
        cin>>ss[i].t>>ss[i].v;
    }
    sort(ss,ss+n+1,compare);
    unsigned int *save=new unsigned int[m+1];
    memset(save,0,sizeof(int)*(m+1));
    unsigned int ans=0;
    for(int i=0;i<=m;++i){
        for(int j=0;j<n&&ss[j].t<=i;++j){
            unsigned int temp=i-ss[j].t;
                save[i]=max(save[i],save[temp]+ss[j].v);
        }
        ans=max(ans,save[i]);
    }
    cout<<ans<<endl;
    delete[] ss;
    delete[] save;
    return 0;
}