#include<bits/stdc++.h>
#define maxn 500005
deque<pr> dq;
int mi[maxn];
int ma[maxn];
int n,k;
int pre[maxn];
int a[maxn];
	++k;
	rep(i,1,n)cin>>a[i];
	rep(i,1,n)pre[i]=pre[i-1]+a[i];
	dq.clear();
	rep(i,0,n){
		while(!dq.empty()&&dq.back().second>=pre[i])dq.pop_back();
		dq.push_back({i,pre[i]});
		if(i-dq.front().first+1>k)dq.pop_front();
		mi[i]=dq.front().second;
	}
	rep(i,1,n)
		ans=max(ans,pre[i]-mi[i]);