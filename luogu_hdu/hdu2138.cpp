#include<bits/stdc++.h>
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
const int S=8;

mt19937 g(rand());//设定g来产生伪随机数，范围unsigned int

bool Witness(ll a,ll n) {
	ll u=n-1,t=0;
	while(u%2==0)t++,u>>=1;
	ll x=fpow(a,u,n);
	if(x==1)return false;
	for(int i=1; i<=t; i++,x=x*x%n)
		if(x!=n-1&&x!=1&&x*x%n==1)return true;
	return x!=1;
}

bool Miller_Rabin(ll n) {
	if(n==2)return true;
	if(n<2||!(n&1))return false;
	srand(time(NULL));
	for(int i=1; i<=S; i++)
		if(Witness(g()%(n-1)+1,n))return false;
	return true;
}
ll x,n,ans;
	while(cin>>n){
		ans=0;
		while(n--){
			cin>>x;
			if(Miller_Rabin(x)){
				++ans;
			}
		}
	}
			