#include<bits/stdc++.h>#define rep(i, a, b) for (int i = (a); i <= (b); ++i)#define per(i, a, b) for (int i = (a); i >= (b); --i)using namespace std;using ll = long long int;int t,n,s;int main(){	ios::sync_with_stdio(false);	cin>>t;
	while (t--) {
		cin>>n>>s;
		int nn=n/2+1;
		cout<<s/nn<<endl;
	}				return 0;}