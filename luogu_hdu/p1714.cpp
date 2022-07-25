#include<bits/stdc++.h>#define rep(i, a, b) for (int i = (a); i <= (b); ++i)#define per(i, a, b) for (int i = (a); i >= (b); --i)
#define maxn 500005using namespace std;using ll = long long;typedef pair<int,int> pr;//index,value
deque<pr> dq;
int mi[maxn];
int ma[maxn];
int n,k;
int pre[maxn];
int a[maxn];signed main(){	ios::sync_with_stdio(false);	cin>>n>>k;
	++k;
	rep(i,1,n)cin>>a[i];
	rep(i,1,n)pre[i]=pre[i-1]+a[i];
	dq.clear();
	rep(i,0,n){
		while(!dq.empty()&&dq.back().second>=pre[i])dq.pop_back();
		dq.push_back({i,pre[i]});
		if(i-dq.front().first+1>k)dq.pop_front();
		mi[i]=dq.front().second;
	}	int ans=0;
	rep(i,1,n)
		ans=max(ans,pre[i]-mi[i]);	cout<<ans<<endl;	return 0;}