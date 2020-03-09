#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<cstdio> 
 
using namespace std;
 
const int N=105;
 
struct Rule{
	vector<string>p;//URL匹配的规则
	string r;//URL 匹配的名字
	bool flag;//标记规则最后是否有"/" 
}a[N];
 
 
//字符串分割函数，将字符串s用"/"分割，并存放于向量v中 
void split(vector<string> &v,char *s)
{
	char *sp=strtok(s,"/");
	while(sp)
	{
		v.push_back(sp);
		sp=strtok(NULL,"/");
	}
}
 
//判断字符串s是否都是数字 
bool isNum(string s)
{
	for(int i=0;i<s.length();i++)
	  if(!isdigit(s[i]))
	    return false;
	return true;
}
 
int n,m;//规则和查询的条数 
 
//处理URL地址，flag标记此URL地址最后是否有"/" 
void solve(vector<string>URL,bool flag)
{
	int i;
	vector<string>ans;//存放参数 
	for(i=0;i<n;i++)//顺序遍历n条规则 
	{
		ans.clear();//先清空 
		int j=0,k=0; 
		vector<string>t(a[i].p);
		while(j<t.size()&&k<URL.size())//查看URL是否和此规则匹配 
		{ 
			if(t[j]=="<int>")//情况一：<int> 
			{
				if(isNum(URL[k]))//如果都是数字 
				{
					int w;
					for(w=0;w<URL[k].size()-1&&URL[k][w]=='0';w++);//去前导零 
					ans.push_back(URL[k].substr(w));
					j++,k++;//匹配下一部分 
				    continue;
				} 	
			}
			else if(t[j]=="<str>")//情况二：<str> 
			{
				ans.push_back(URL[k]);//直接记录即可 
				j++,k++;//匹配下一部分
				continue;
			}
			else if(t[j]=="<path>")//情况三: <path>
			{
				string s;
				while(k<URL.size()) s=s+"/"+URL[k++];
				ans.push_back(s.substr(1));//要去除第一个"/"符号 
				j++;
				continue;
			}
			else if(t[j]==URL[k])
			{
				j++,k++;//匹配下一部分
				continue;
			}
			break;
		}
		if(j==t.size()&&k==URL.size()&&flag==a[i].flag) break;//如果匹配就跳出 
	}
	if(i==n)
	  cout<<"404"<<endl;//如果n条规则都匹配失败，则输出"404" 
	else
	{
		cout<<a[i].r;//输出匹配的规则的名字 
		for(int w=0;w<ans.size();w++)//输出各个参数 
		  cout<<" "<<ans[w];
		cout<<endl;
	}
}
 
int main()
{
	cin>>n>>m;
	string rule;
	for(int i=0;i<n;i++)
	{
		char temp[120];
		scanf("%s",temp); 
		cin>>a[i].r;
		a[i].flag=(temp[strlen(temp)-1]=='/')?true:false;//记录规则的最后是否有"/" 
		split(a[i].p,temp);//分割 
	}
	for(int i=0;i<m;i++)
	{
		vector<string>URL;
		char temp[120];
		scanf("%s",temp);
		bool flag=(temp[strlen(temp)-1]=='/')?true:false;//记录规则的最后是否有"/" 
		split(URL,temp);//分割 
		solve(URL,flag);//判断处理 
	}
	return 0;
}
