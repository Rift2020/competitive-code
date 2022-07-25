#include<bits/stdc++.h>#define rep(i, a, b) for (int i = (a); i <= (b); ++i)	#define per(i, a, b) for (int i = (a); i >= (b); --i)		using namespace std;using ll = long long int;string s[4];
string t,ans;int main(){	ios::sync_with_stdio(false);	cin>>s[1]>>s[2]>>s[3];
	cin>>t;	for(char i:t){
		ans+=s[i-'0'];
	}	cout<<ans<<endl;		return 0;}