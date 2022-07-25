#include<bits/stdc++.h>#define rep(i, a, b) for (int i = (a); i <= (b); ++i)	#define per(i, a, b) for (int i = (a); i >= (b); --i)		using namespace std;using ll = long long int;int t;
string in;int main(){	ios::sync_with_stdio(false);	cin>>t;
	while(t--){
		cin>>in;
		int a=0,b=0;
		for(char c:in){
			if(c=='A'||c=='C')a++;
			else if(c=='B')++b;
		}
		if(a==b)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}				return 0;}