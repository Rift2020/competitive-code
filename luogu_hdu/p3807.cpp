/**
 *    author:  Rift
 *    created: 2022.08.14  12:00
**/
#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
#define x first
#define y second
#define maxn 100005
using namespace std;
using ll = long long;
using pr = pair<int,int>;
ll fact[maxn],mod;
void init_fact(ll n){
    fact[0]=1;
    for(int i=1;i<=n;++i)
        fact[i]=fact[i-1]*i%mod;
}
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
ll C(ll n,ll m){
    if(m>n)return 0;
    ll fz=fact[n];
    ll fm=fact[m]*fact[n-m]%mod;
    ll fm_inv,y;
    exgcd(fm,mod,fm_inv,y);
    fm_inv=(fm_inv+mod)%mod;
    return fz*fm_inv%mod;
}
int t;
int n,m;
ll lucas(ll n,ll m){
	if(m==0)return 1;
	if(n<m)return 0;
	return lucas(n/mod,m/mod)*C(n%mod,m%mod)%mod;
}
signed main(){
    ios::sync_with_stdio(false),cin.tie(nullptr);
    cin>>t;
	while(t--){
		cin>>n>>m>>mod;
		init_fact(mod);
		cout<<lucas(n+m,n)<<endl;
	}


    return 0;
}
