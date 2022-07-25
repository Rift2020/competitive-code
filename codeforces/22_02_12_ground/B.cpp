#include<bits/stdc++.h>#define rep(i, a, b) for (int i = (a); i <= (b); ++i)	#define per(i, a, b) for (int i = (a); i >= (b); --i)	#define maxn 105
		using namespace std;using ll = long long;int t,n;
int a[maxn];signed main(){	ios::sync_with_stdio(false);
	cin.tie(nullptr);	cin>>t;
	while(t--){
		cin>>n;
		rep(i,1,n){
			cin>>a[i];
			if(a[i]==0)a[i]=2;
			else a[i]=1;
		}
		ll ans=0;
		rep(i,1,n){
			ll l=i,r=n-i+1;
			ans+=l*r*a[i];
		}
		cout<<ans<<endl;
	}				return 0;}