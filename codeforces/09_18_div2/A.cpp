#include<bits/stdc++.h>#define rep(i, a, b) for (int i = (a); i <= (b); ++i)	#define per(i, a, b) for (int i = (a); i >= (b); --i)		using namespace std;using ll = long long int;int t;
int n;
string s;int main(){	ios::sync_with_stdio(false);	cin>>t;
	while(t--){
		cin>>n;
		cin>>s;
		int ans=0;
		for(int i=0;i<n;++i){
			//cout<<':'<<s[i]-'0'<<endl;
			if(i!=n-1&&s[i]!='0')
				ans+=s[i]-'0'+1;
			else
				ans+=s[i]-'0';
		}
		cout<<ans<<endl;
	}				return 0;}