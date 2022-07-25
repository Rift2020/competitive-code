#include<bits/stdc++.h>#define rep(i, a, b) for (int i = (a); i <= (b); ++i)	#define per(i, a, b) for (int i = (a); i >= (b); --i)
		#define maxn 3000005		using namespace std;using ll = long long;int n;
int a[maxn];
int ans[maxn];
typedef pair<int,int> pr;//value,index
stack<pr> st;signed main(){	ios::sync_with_stdio(false);	cin>>n;
	rep(i,1,n)cin>>a[i];	per(i,n,1){
		while(!st.empty()&&st.top().first<=a[i])st.pop();
		if(!st.empty())ans[i]=st.top().second;
		st.push({a[i],i});
	}	rep(i,1,n)cout<<ans[i]<<" ";
	cout<<endl;		return 0;}