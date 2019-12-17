#include<bits/stdc++.h>

using namespace std;
int n,m;
int sa[501];
int sb[501];
int ss[501][501];
int tot[501];
int lics[501][501];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d",sa+i);
	}
	scanf("%d",&m);
	for(int i=1;i<=m;++i){
		scanf("%d",sb+i);
	}
	sa[0]=sb[0]=-1;
	
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			if(sa[i]==sb[j]){
				//ss[i][j]=tot[j]=1;
				for(int k=0;k<j;++k){
					if(sb[k]<sb[j]){
						if(ss[i][j]<ss[i-1][k]+1){
							ss[i][j]=ss[i-1][k]+1;
							tot[j]=tot[k]+1;
							for(int p=1;p<=tot[k];++p){
								lics[j][p]=lics[k][p];
							}
						}
					}
				}
				lics[j][tot[j]]=sb[j];
			}else{
				ss[i][j]=ss[i-1][j];
			}
		}
	}
	int ans=0;
	int pos=0;
	for(int i=1;i<=m;++i){
		if (ss[n][i]>ans)
		{
			ans=ss[n][i];
			pos=i;
		}
	}
	cout<<ans<<endl;
	for(int i=1;i<=tot[pos];++i)
	cout<<lics[pos][i]<<" ";
	return 0;
	
}
