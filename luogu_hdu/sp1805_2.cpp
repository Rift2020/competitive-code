#include<bits/stdc++.h>#define rep(i, a, b) for (int i = (a); i <= (b); ++i)#define per(i, a, b) for (int i = (a); i >= (b); --i)
#define maxn 100005
using namespace std;using ll = long long;
ll n,ans;int a[maxn];
ll l[maxn];
ll r[maxn];
typedef pair<int,int> pr;//index,value
stack<pr> st;
void pp(int i){
	int tp=st.top().first;
	r[tp]=i-1;
	st.pop();
}
void pp2(int i){
	int tp=st.top().first;
	l[tp]=i+1;
	st.pop();
}signed main(){	ios::sync_with_stdio(false);	while(1){
		cin>>n;
		if(n==0)break;
		rep(i,1,n)cin>>a[i];
		//计算r数组部分{
		rep(i,1,n){
			while(!st.empty()&&st.top().second>a[i])pp(i);
			st.push({i,a[i]});
		}
		while(!st.empty())pp(n+1);
		//}
		per(i,n,1){
			while(!st.empty()&&st.top().second>a[i])pp2(i);
			st.push({i,a[i]});
		}
		while(!st.empty())pp2(0);
		ans=0;
		rep(i,1,n)ans=max(ans,(r[i]-l[i]+1)*a[i]);
		cout<<ans<<endl;
	}				return 0;}