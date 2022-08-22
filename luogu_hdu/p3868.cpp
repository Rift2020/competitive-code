/**
 *    author:  Rift
 *    created: 2022.08.13  12:06
**/
#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
#define x first
#define y second
#define maxn 15
using namespace std;
using ll = long long;
using pr = pair<int,int>;
int k,a[maxn],n[maxn];
ll exgcd(ll a,ll b,ll &x,ll &y){
	if(b==0){
		x=1;
		y=0;
		return a;
	}
	ll g=exgcd(b,a%b,x,y);
	int t=x;
	x=y;
	y=t-a/b*y;
	return g;
}
ll mul(ll a,ll b,ll mod){
	if(b<0){
		a=-a;
		b=-b;
	}
	a%=mod;
	b%=mod;
	ll ans=0;
	while(b){
		if(b&1)
			ans=(ans+a)%mod;
		a=(a<<1)%mod;
		b>>=1;
	}
	return ans;
}
ll CRT(int a[],int n[],int k){
	ll ns=1;
	ll re=0;
	for(int i=1;i<=k;++i)ns*=n[i];
	for(int i=1;i<=k;++i){
		ll minv,y;
		ll m=ns/n[i];
		exgcd(m,n[i],minv,y);
		re=(re+mul(mul(a[i],m,ns),minv,ns))%ns;
	}
	return (re+ns)%ns;
}
signed main(){
	ios::sync_with_stdio(false),cin.tie(nullptr);
	cin>>k;
	rep(i,1,k){
		cin>>a[i];
	}
	rep(i,1,k){
		cin>>n[i];
	}
	cout<<CRT(a,n,k)<<endl;
	
	return 0;
}
