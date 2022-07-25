#include<bits/stdc++.h>#define rep(i, a, b) for (int i = (a); i <= (b); ++i)	#define per(i, a, b) for (int i = (a); i >= (b); --i)	#define int long long
		using namespace std;int sumOdd(int x){
	int re=x/3*2;
	re+=x%3;
	return re;
}
int queryOdd(int l,int r){
	return sumOdd(r)-sumOdd(l-1);
}
int n;signed main(){	ios::sync_with_stdio(false);	cin>>n;
	unsigned long long s=0;
	unsigned long long nj=sumOdd(n);
	s=n*(n-1)/2-(nj-1)*nj/2;	cout<<s<<endl;	return 0;}