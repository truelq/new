#include<bits/stdc++.h>

using namespace std;
string a;
string b;

int ss[250001];
int main(){
	cin>>a>>b;
	
	int ans=0;
	for(int i=0;i<a.size();++i){
		for(int j=0;j<b.size();++j){
			int temp=0;
			for(int k=0;i+k<a.size()&&j+k<b.size();++k){
				if(a[i+k]==b[j+k]){
					temp++;
				}else break;
			}
			ans=max(ans,temp);
		}
		
	}
	cout<<ans<<endl;
	return 0;
	
}
