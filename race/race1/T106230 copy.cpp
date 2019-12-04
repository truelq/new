#include<bits/stdc++.h>
#include<queue>
#include<pri
using namespace std;

const int N=100010,M=1000010;
int head[N],ver[M],edge[M],Next[M],d[N];
bool v[N];
int n,m,pot;
priority_queuq<pair<int,int>>q;
