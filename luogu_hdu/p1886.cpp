#include<bits/stdc++.h>
#define maxn 1000005
deque<pr> dq;
int mi[maxn];
int ma[maxn];
int n,k;
int a[maxn];
	rep(i,1,n)cin>>a[i];
	rep(i,1,n){
		while(!dq.empty()&&dq.back().second<=a[i])dq.pop_back();
		dq.push_back({i,a[i]});
		if(i-dq.front().first+1>k)dq.pop_front();
		if(i>=k)ma[i]=dq.front().second;
	}
	dq.clear();
	rep(i,1,n){
		while(!dq.empty()&&dq.back().second>=a[i])dq.pop_back();
		dq.push_back({i,a[i]});
		if(i-dq.front().first+1>k)dq.pop_front();
		if(i>=k)mi[i]=dq.front().second;
	}
		cout<<mi[i]<<" ";
	cout<<endl;
		cout<<ma[i]<<" ";
	cout<<endl;