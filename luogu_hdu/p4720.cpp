/**
 *    author:  Rift
 *    created: 2022.08.22  14:54
**/
#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
#define x first
#define y second
#define maxmod 1000005
using namespace std;
using ll = long long;
using pr = pair<int,int>;
ll fac[maxmod];
ll inline fpow(ll x,ll n){
    ll re=1;
    while(n){
        if(n&1)
            re*=x;//re=(x*re)%mod;
        x*=x;//x=(x*x)%mod;
        n>>=1;
    }
    return re;
}
ll inline fpow(ll x,ll n,ll mod){
    ll re=1;
    while(n){
        if(n&1)
            re=(x*re)%mod;
        x=(x*x)%mod;
        n>>=1;
    }
    return re;
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
    y=t-(a/b)*y;
    return g;
}
ll mod_inverse(ll a,ll n){
	ll x,y;
	exgcd(a,n,x,y);
	return x;
}
ll CRT(ll a[],ll n[],ll k){
    ll ns=1;
    ll re=0;
    for(ll i=1;i<=k;++i)ns*=n[i];
    for(ll i=1;i<=k;++i){
        ll minv,y;
        ll m=ns/n[i];
        exgcd(m,n[i],minv,y);
        re=(re+(a[i]*m*minv)%ns)%ns;
    }
    return (re+ns)%ns;
}
ll inline vn(ll n,ll p){
    ll re=0;
	for(ll pp=p;pp<=n;pp*=p)
		re+=n/pp;
	return re;
}
void pre_cal(ll p,ll pk){
	fac[0]=fac[1]=1;
	for(int i=2;i<=pk;++i){
		if(i%p==0)fac[i]=fac[i-1];
		else fac[i]=fac[i-1]*i%pk;
	}
}
ll cal(ll n,ll p,ll pk){
	if(n==0)return 1;
	ll a;
	if(n>=pk)
		a=fac[pk];
	else
		a=1;
	a=fpow(a,n/pk,pk);
	a=a*fac[n%pk]%pk;
	return cal(n/p,p,pk)*a%pk;
}
ll exlucas(ll n,ll m,ll mod){
	ll p[30],k[30],cnt=0;
	for(ll i=2;i*i<=mod;++i){
		if(mod%i==0){
			p[++cnt]=i;
			k[cnt]=1;
            mod/=i;
			while(mod%i==0){
				mod/=i;
				k[cnt]++;
			}
		}
	}
	if(mod>1){
		p[++cnt]=mod;
		k[cnt]=1;
	}
    ll crt_a[cnt+1],crt_n[cnt+1];
	for(int i=1;i<=cnt;++i){
		ll pk=fpow(p[i],k[i]);
		pre_cal(p[i],pk);
		ll fz=cal(n,p[i],pk);
		ll fm=cal(m,p[i],pk)*cal(n-m,p[i],pk)%pk;
		ll fm_inv=mod_inverse(fm,pk);
		crt_a[i]=fz*fm_inv%pk*fpow(p[i],vn(n,p[i])-vn(m,p[i])-vn(n-m,p[i]),pk)%pk;
		crt_n[i]=pk;
	}
    ll re=CRT(crt_a,crt_n,cnt);
	return re;
}
signed main(){
	ios::sync_with_stdio(false),cin.tie(nullptr);
	ll n,m,p;
	cin>>n>>m>>p;
	cout<<exlucas(n,m,p)<<endl;


	return 0;
}
