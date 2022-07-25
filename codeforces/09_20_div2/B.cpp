#include<bits/stdc++.h>#define rep(i, a, b) for (int i = (a); i <= (b); ++i)	#define per(i, a, b) for (int i = (a); i >= (b); --i)		using namespace std;using ll = long long int;int t,a[3],m;int main(){	ios::sync_with_stdio(false);	cin>>t;
	while(t--){
		cin>>a[0]>>a[1]>>a[2]>>m;
		sort(a,a+3,greater<int>());
		int l=max(0,a[0]-a[1]-a[2]-1);
		int r=max(0,a[0]-1)+max(0,a[1]-1)+max(0,a[2]-1);
		if(m>=l&&m<=r)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}				return 0;}