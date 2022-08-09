/**
 *    author:  Rift
 *    created: 2022.08.09  18:17
**/
#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
#define x first
#define y second
#define maxn 25
using namespace std;
using pr = pair<int,int>;
using ll = long long;
int n;
int a[maxn];
int multi_gcd(int a[],int l,int r){
	if(l==r)return a[l];
	int m=(l+r)/2;
	return __gcd(multi_gcd(a,l,m),multi_gcd(a,m+1,r));
}
signed main(){
	ios::sync_with_stdio(false),cin.tie(nullptr);
	cin>>n;
	rep(i,1,n){
		cin>>a[i];
		a[i]=abs(a[i]);
	}
	cout<<multi_gcd(a,1,n)<<endl;
	
	
	return 0;
}
