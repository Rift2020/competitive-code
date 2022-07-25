#include<bits/stdc++.h>#define rep(i, a, b) for (int i = (a); i <= (b); ++i)	#define per(i, a, b) for (int i = (a); i >= (b); --i)		using namespace std;using ll = long long;int t,l,r,k;signed main(){	ios::sync_with_stdio(false);
	cin.tie(nullptr);	cin>>t;
	while(t--){
		cin>>l>>r>>k;
		int n=r-l+1;
		if(n==1){
			if(l!=1)
				cout<<"YES"<<endl;
			else
				cout<<"NO"<<endl;
			continue;
		}
		if(n%2==1&&l%2==1)n+=2;
		n/=2;
		if(n<=k)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}				return 0;}