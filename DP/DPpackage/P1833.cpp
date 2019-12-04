#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;

//樱花 多重背包和完全背包结合，将两者分开计算中间值性质相同

int main(){
    int a,b,c,d;
    int n;
    scanf("%d:%d %d:%d %d",&a,&b,&c,&d,&n);
    int t,w,nn;
    vector<int> t1,c1;
    vector<int> t2,c2;
    t1.push_back(0);
    t2.push_back(0);
    c1.push_back(0);
    c2.push_back(0);
    for(int i=1;i<=n;++i){
        scanf("%d %d %d",&t,&w,&nn);
        if(!nn){
            t1.push_back(t);
            c1.push_back(w);
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
    int tt=(c-a)*60+d-b;
    int save[tt+1]={0};
    for(int i=1;i<t2.size();++i){
        for(int j=tt;j>=t2[i];--j){
            save[j]=max(save[j],save[j-t2[i]]+c2[i]);
        }
    }
    for(int i=1;i<=tt;++i){
        for(int j=1;j<t1.size();++j){
            if(i>=t1[j]){
                save[i]=max(save[i],save[i-t1[j]]+c1[j]);
            }
        }
    }
    cout<<save[tt]<<endl;
    return 0;

}