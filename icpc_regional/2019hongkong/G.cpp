#include<bits/stdc++.h>#define rep(i, a, b) for (int i = (a); i <= (b); ++i)	#define per(i, a, b) for (int i = (a); i >= (b); --i)		using namespace std;using ll = long long int;int k,p,q,m,n;int main(){	ios::sync_with_stdio(false);	cin>>k;	p=sqrt(k);
	q=k/p;
	m=k%p;
	int cnt=1;
	n=p+q+m;
	cout<<n+1<<endl;	rep(i,1,m){
		cout<<i<<" ";
		++cnt;
	}	rep(i,0,p-1){
		cout<<cnt<<" ";
		++cnt;
	}
	cout<<m+1<<" ";
	++cnt;
	rep(i,1,q-1){
		cout<<cnt<<" ";
		++cnt;
	}
	cout<<endl;
	cout<<3<<" ";
	rep(i,1,m)cout<<2<<" ";
	rep(i,1,p+q)cout<<1<<" ";
	cout<<endl;	return 0;}