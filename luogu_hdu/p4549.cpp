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
signed main(){
	ios::sync_with_stdio(false),cin.tie(nullptr);
	cin>>n;
	rep(i,1,n){
		cin>>a[i];
		a[i]=abs(a[i]);
	}
	int g=__gcd(a[1],a[2]);
	for(int i=3;i<=n;++i)
		g=__gcd(g,a[i]);
	cout<<g<<endl;
	
	
	return 0;
}
