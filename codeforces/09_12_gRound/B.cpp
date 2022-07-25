#include<bits/stdc++.h>#define rep(i, a, b) for (int i = (a); i <= (b); ++i)	#define per(i, a, b) for (int i = (a); i >= (b); --i)		using namespace std;using ll = long long int;int t;
string s;int main(){	ios::sync_with_stdio(false);	cin>>t;
	while(t--){
		cin>>s;
		int ans=0;
		for(int i=0;i<s.size();++i){
			if(s[i]=='0'&&(i==0||s[i-1]!='0')){
				++ans;
			}
		}
		cout<<min(ans,2)<<endl;
	}				return 0;}