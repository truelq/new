#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

//樱花 多重背包和完全背包结合，将两者分开计算中间值性质相同
struct P1833
{
    int t;
    int c;
};
bool compare(P1833 a,P1833 b){
    return a.t<b.t;
}
bool operator<(const P1833&a ,const P1833& b){
    return a.t<b.t;
}
int main(){
    int a,b,c,d;
    int n;
    scanf("%d:%d %d:%d %d",&a,&b,&c,&d,&n);
    int t,w,nn;
    vector<int> t1,c1;
    vector<P1833> tempt;
    vector<int> t2,c2;
    P1833 temp;
    temp.c=0;
    temp.t=0;
    tempt.push_back(temp);
    //t1.push_back(0);
    t2.push_back(0);
    //c1.push_back(0);
    c2.push_back(0);
    for(int i=1;i<=n;++i){
        scanf("%d %d %d",&t,&w,&nn);
        if(!nn){
            temp.t=t;
            temp.c=w;
            tempt.push_back(temp);
            //t1.push_back(t);
            //c1.push_back(w);
        }else{
            for(int j=1;j<=nn;j<<=1){
                t2.push_back(t*j);
                c2.push_back(w*j);
                nn-=j;
            }
            if(nn){
                t2.push_back(nn*t);
                c2.push_back(nn*w);
            }
        }
    }
    sort(tempt.begin(),tempt.end());
    int tt=(c-a)*60+d-b;
    int save[tt+1]={0};
    for(int i=1;i<t2.size();++i){
        for(int j=tt;j>=t2[i];--j){
            save[j]=max(save[j],save[j-t2[i]]+c2[i]);
        }
    }
    for(int i=1;i<=tt;++i){
        for(int j=1;j<tempt.size()&&tempt[j].t<=i;++j){
                save[i]=max(save[i],save[i-tempt[j].t]+tempt[j].c);
        }
    }
    cout<<save[tt]<<endl;
    return 0;

}