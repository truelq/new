#include<iostream>
#include<vector>
using namespace std;

int main(){
	vector<int >prices;
	int counts;
	int temp;
	cin>>counts;
	for(int i=0;i<counts;i++){
		cin>>temp;
		prices.push_back(temp);
	}
	for(int i=0;i<counts;i++){
		if(i>0){
			if(i+1<counts){
				cout<<(prices[i-1]+prices[i]+prices[i+1])/3;
				cout<<' ';
			}
			else {
				cout<<(prices[i-1]+prices[i])/2;
				cout<<' ';
			}
		}
		else {
		cout<<(prices[0]+prices[1])/2;
		cout<<' ';
		}
	}
	return 0;
}
