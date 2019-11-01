#include<bits/stdc++.h>

using namespace std;
struct P2487
{
    int h;
    int v;
};
P2487 ss[50001];
int save[50001];
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;++i){
        scanf("%d %d",&ss[i].h,&ss[i].v);
    }
    int ans=0;
    for(int i=1;i<=n;++i){
        save[i]=1;
        for(int j=1;j<i;++j){
            if(ss[i].h<=ss[j].h&&ss[j].v<=ss[j].v){
                save[i]=max(save[i],save[j]+1);
            }
        }
        ans=max(ans,save[i]);
    }
    printf("%d\n",ans);
    for(int i=1;i<=n;++i){
        printf("1 ");
    }
}