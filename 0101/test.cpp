#include<iostream>
#include<string>
#include<stdio.h>

using namespace std;
string defa="\\x1B\\x5B\\x30\\x6D";
string start="\\x1B\\x5B\\x34\\x38\\x3B\\x32\\x3B";
string mid="\\x%x";
string endd="\\x6D";
string ccc="\\x3B";
string space="\\x20";
string ent="\\x0A";

int change(string a ){
	int ans=0;
	for(int i=0;i<a.size();++i){
		if(a[i]<='9'&&a[i]>='0'){
			ans=ans*16+a[i]-'0';
		}else if(a[i]>='a'&&a[i]<='f'){
			ans=ans*16+a[i]-'a'+10;
		}else if(a[i]>='A'&&a[i]<='F'){
			ans=ans*16+a[i]-'A'+10;
		}
	}
	return ans;
}
void printrgb(int temps){
	if(temps/100){
		printf(mid.data(),temps/100+'0');
		printf(mid.data(),temps%100/10+'0');
		printf(mid.data(),temps%10+'0');
	}
	else if(temps/10){
		printf(mid.data(),temps/10+'0');
		printf(mid.data(),temps%10+'0');
	}
	else {
		printf(mid.data(),temps+'0');
	}
}
int main(){
	int m,n;
	int p,q;
	cin>>m>>n>>p>>q;
	int mm,nn;
	mm=m/p;
	nn=n/q;
	
	int r[n][m];
	int g[n][m];
	int b[n][m];
	int rr[nn][mm];
	int gg[nn][mm];
	int bb[nn][mm];
	int sum=p*q;
	string temp="";
	string s="";
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			cin>>temp;
			s="";
			if(temp.size()==2){
				s=s+temp[1]+temp[1];
				r[i][j]=change(s);
				g[i][j]=change(s);
				b[i][j]=change(s);
			}else if(temp.size()==4){
				s=s+temp[1]+temp[1];
				r[i][j]=change(s);
				s="";
				s=s+temp[2]+temp[2];
				g[i][j]=change(s);
				s="";
				s=s+temp[3]+temp[3];
				b[i][j]=change(s);
			}else{
				s=s+temp[1]+temp[2];
				//printf("%s",s.data());
				r[i][j]=change(s);
				s="";
				s=s+temp[3]+temp[4];
				g[i][j]=change(s);
				s="";
				s=s+temp[5]+temp[6];
				b[i][j]=change(s);
			}
		}
	}
	for(int i=0;i<nn;++i){
		for(int j=0;j<mm;++j){
			int tempa=0;
			int tempb=0;
			int tempc=0;
			for(int k=i*q;k<i*q+q;++k){
				for(int l=j*p;l<j*p+p;++l){
					tempa+=r[k][l];
					tempb+=g[k][l];
					tempc+=b[k][l];
				}
			}
			rr[i][j]=tempa/sum;
			gg[i][j]=tempb/sum;
			bb[i][j]=tempc/sum;
		}
	}
	
	int rrr,ggg,bbb;
	rrr=ggg=bbb=0;
	int defstate=1;
	int temps;
	for(int i=0;i<nn;++i){
		for(int j=0;j<mm;++j){
			if(rr[i][j]==rrr&&gg[i][j]==ggg&&bb[i][j]==bbb){
				printf(space.data());
			}else if(rr[i][j]==0&&gg[i][j]==0&&bb[i][j]==0){
				if(!defstate){
					printf(defa.data());
					//printf(end.data());
					defstate=1;
				}
				printf(space.data());
			}else{
				defstate=0;
				printf(start.data());
				temps=rr[i][j];
				printrgb(rr[i][j]);
				printf(ccc.data());
				printrgb(gg[i][j]);
				printf(ccc.data());
				printrgb(bb[i][j]);
				printf(endd.data());
				
				printf(space.data());
			}
			rrr=rr[i][j];
			ggg=gg[i][j];
			bbb=bb[i][j];
		}
		if(!defstate){
			printf(defa.data());
			defstate=1;
		}
		printf(ent.data());
	}


	return 0;
}
