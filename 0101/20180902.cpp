#include<iostream>
#include<vector>

using namespace std;
int max(int x,int y){
	if(x>y)
		return x;
	else return y;
};
int min(int x,int y){
	if(x>y)
		return y;
	else return x;
};
int main(){
	int counts;
	int temp;
	int tem;
	int timelength=0;
	vector<int> a,b,c,d;
	cin>>counts;
	for(int i=0;i<counts;++i){
		cin>>temp>>tem;
		a.push_back(temp);
		b.push_back(tem);
	}
	for(int i=0;i<counts;++i){
		cin>>temp>>tem;
		c.push_back(temp);
		d.push_back(tem);
	}
	int j=0;
	for(int i=0;i<counts;++i){
		for(;j<counts;++j){
			int t=max(a[i],c[j]);
			int y=min(b[i],d[j]);
			if(t<y){
				timelength+=y-t;
				if(b[i]<d[j])
				break;
				else 
				continue;
			}
			else {
				if(b[i]<d[j]){
					break;
				}else{
					continue;
				}
			}
		}
	}
	cout<<timelength;
}
