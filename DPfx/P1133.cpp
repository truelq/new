#include<iostream>
#include<stdio.h>
#include<vector>
#include<string.h>
using namespace std;
//教主的花园
int ss[100001][3];
int save[100001][3];
int main(){
    int n;
    vector<int> ans;
    cin>>n;
    for(int i=0;i<n;++i){
        scanf("%d %d %d",ss[i]+0,ss[i]+1,ss[i]+2);
    }
    //0向下开始
    int begin=0;
    save[0][0]=ss[0][0];
    //save[0][1]=ss[0][1];
    for(int i=1;i<n;++i){
        save[i][0]=max(save[i-1][1],save[i-1][2])+ss[i][0];
        save[i][1]=max(save[i-1][0],save[i-1][2])+ss[i][1];
        save[i][2]=max(save[i-1][0],save[i-1][1])+ss[i][2];
        save[i][begin]=0;
        begin^=2;
    }
    ans.push_back(save[n-1][0]);
    ans.push_back(save[n-1][1]);
    ans.push_back(save[n-1][2]);
    
    //1向下开始
    memset(save,0,sizeof(save));
    begin=0;
    save[0][1]=ss[0][1];
    for(int i=1;i<n;++i){
        save[i][0]=max(save[i-1][1],save[i-1][2])+ss[i][0];
        save[i][1]=max(save[i-1][0],save[i-1][2])+ss[i][1];
        save[i][2]=max(save[i-1][0],save[i-1][1])+ss[i][2];
        save[i][begin]=0;
        begin^=2;
    }
    ans.push_back(save[n-1][2]);
    //1向上开始
    memset(save,0,sizeof(save));
    begin=2;
    save[0][1]=ss[0][1];
    for(int i=1;i<n;++i){
        save[i][0]=max(save[i-1][1],save[i-1][2])+ss[i][0];
        save[i][1]=max(save[i-1][0],save[i-1][2])+ss[i][1];
        save[i][2]=max(save[i-1][0],save[i-1][1])+ss[i][2];
        save[i][begin]=0;
        begin^=2;
    }
    ans.push_back(save[n-1][0]);
    //2向上开始
    memset(save,0,sizeof(save));
    begin=2;
    save[0][2]=ss[0][2];
    //save[0][1]=ss[0][1];
    for(int i=1;i<n;++i){
        save[i][0]=max(save[i-1][1],save[i-1][2])+ss[i][0];
        save[i][1]=max(save[i-1][0],save[i-1][2])+ss[i][1];
        save[i][2]=max(save[i-1][0],save[i-1][1])+ss[i][2];
        save[i][begin]=0;
        begin^=2;
    }
    ans.push_back(save[n-1][0]);
    ans.push_back(save[n-1][1]);
    ans.push_back(save[n-1][2]);

    int mm=0;
    for(int i=0;i<ans.size();++i){
        mm=max(mm,ans[i]);
    }
    cout<<mm<<endl;
    return 0;
}