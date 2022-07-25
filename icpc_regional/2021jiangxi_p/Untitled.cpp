#include<bits/stdc++.h>#define rep(i, a, b) for (int i = (a); i <= (b); ++i)	#define per(i, a, b) for (int i = (a); i >= (b); --i)		using namespace std;using ll = long long int;ll t,n,m;int main(){	ios::sync_with_stdio(false);	cin>>t;
	while(t--){
		cin>>n>>m;
		ll s=0;
		rep(i,1,n){
			s+=i*i;
		}
		s*=m;
		cout<<s<<endl;
	}				return 0;}