#include<bits/stdc++.h>#define rep(i, a, b) for (int i = (a); i <= (b); ++i)#define per(i, a, b) for (int i = (a); i >= (b); --i)
#define maxn 1000005using namespace std;using ll = long long;typedef pair<int,int> pr;//index,value
deque<pr> dq;
int mi[maxn];
int ma[maxn];
int n,k;
int a[maxn];signed main(){	ios::sync_with_stdio(false);	cin>>n>>k;
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
	}	rep(i,k,n)
		cout<<mi[i]<<" ";
	cout<<endl;	rep(i,k,n)
		cout<<ma[i]<<" ";
	cout<<endl;		return 0;}