#include<bits/stdc++.h>#define rep(i, a, b) for (int i = (a); i <= (b); ++i)	#define per(i, a, b) for (int i = (a); i >= (b); --i)
		#define int ll		using namespace std;using ll = long long;int t,n,z;
int ans;signed main(){	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>t;	while(t--){
		cin>>n>>z;
		ans=0;
		while(n--){
			int in;
			cin>>in;
			ans=max(ans,in|z);
		}
		cout<<ans<<endl;
	}				return 0;}