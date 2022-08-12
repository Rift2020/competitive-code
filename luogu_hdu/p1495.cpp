/**
 *    author:  Rift
 *    created: 2022.08.12  10:41
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
ll exgcd(ll a,ll b,ll &x,ll &y){
	if(b==0){
		x=1;
		y=0;
		return a;
	}
	ll g=exgcd(b,a%b,x,y);
	ll t=x;
	x=y;
	y=t-a/b*y;
	return g;
}
ll mod_inv(ll a,ll n){
	ll x,y;
	exgcd(a,n,x,y);
	return x;
}
ll CRT(int a[],int n[],int k){
	ll ns=1;
	for(int i=1;i<=k;++i)ns*=n[i];
	ll re=0;
	for(int i=1;i<=k;++i){
		ll m=ns/n[i];
		ll minv=mod_inv(m,n[i]);
		re+=((ll)a[i]*m*minv)%ns;
	}
	return (re%ns+ns)%ns;
}
int k,a[maxn],n[maxn]; 
signed main(){
	ios::sync_with_stdio(false),cin.tie(nullptr);
	cin>>k;
	rep(i,1,k){
		cin>>n[i]>>a[i];
	}
	cout<<CRT(a,n,k)<<endl;
	
	return 0;
}
