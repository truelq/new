#include <iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int ss[n+1];
    for (int i = 0; i < n; ++i){
        cin >> ss[i];
    }
    vector<int> save;
    save.reserve(n+1);
    
    int l[n+1];
    int state[n+1];
    //memset(save,0x7f,sizeof(save));
    memset(l,0,sizeof(l));
    memset(state,0,sizeof(state));
    save[0]=0;
    int ans=0;
    for(int i=0;i<n;++i){
        if(ss[i]>save[ans]){
            save[++ans]=ss[i];
            l[i]=ans;
            state[i]+=1;
        }else{
            int temp=(int)(upper_bound(save.begin(),save.begin()+ans,ss[i])-save.begin());
            //cout<<temp<<endl;
            save[temp]=ss[i];
        }
    }

    cout<<ans<<endl;
    return 0;

}