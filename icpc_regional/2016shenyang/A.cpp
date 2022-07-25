#include<bits/stdc++.h>#define rep(i, a, b) for (int i = (a); i <= (b); ++i)	#define per(i, a, b) for (int i = (a); i >= (b); --i)		using namespace std;using ll = long long;int t,a,b;signed main(){	ios::sync_with_stdio(false);	cin>>t;
	while(t--){
		cin>>a>>b;
		cout<<2*max(a,b)+min(a,b)<<endl;
	}				return 0;}