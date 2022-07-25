#include<bits/stdc++.h>#define rep(i, a, b) for (int i = (a); i <= (b); ++i)#define per(i, a, b) for (int i = (a); i >= (b); --i)using namespace std;using ll = long long int;ll m,k;int main(){	ios::sync_with_stdio(false);	while(cin>>m>>k){
		cout<<k+(m-k)*k<<endl;
	}				return 0;}