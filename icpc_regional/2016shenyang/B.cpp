#include<bits/stdc++.h>#define rep(i, a, b) for (int i = (a); i <= (b); ++i)	#define per(i, a, b) for (int i = (a); i >= (b); --i)		using namespace std;using ll = long long;int t;
string in;
int ans;
map<char,int> mp={{'H',1},{'O',16},{'C',12}};signed main(){	ios::sync_with_stdio(false);	cin>>t;
	while(t--){
		cin>>in;
		ans=0;
		for(char c:in)ans+=mp[c];
		cout<<ans<<endl;
	}				return 0;}