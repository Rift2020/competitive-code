#include<bits/stdc++.h>#define rep(i, a, b) for (int i = (a); i <= (b); ++i)#define per(i, a, b) for (int i = (a); i >= (b); --i)
#define mod 998244353
#define maxn 1000005using namespace std;using ll = long long int;ll po[maxn];
ll mem[maxn];
ll lmem[maxn];
ll qzh[maxn];
ll n,d;
ll ans;int main(){	ios::sync_with_stdio(false);	po[0]=1,po[1]=1;
	rep(i,2,maxn-1){
		po[i]=po[i-1]*2%mod;
	}	cin>>n>>d;
	for(int i=0;i<=d;++i){
		lmem[i]=po[i]*po[d-i];
		if(i!=d-i)lmem[i]*=2;
		lmem[i]%=mod;
	}
	qzh[0]=0;
	for(int i=d+1/2;i<=d;++i){
		qzh[i]=qzh[i-1]+lmem[i];
		qzh[i]%=mod;
	}
		for(ll num=1,de=1;de<=n;++de,num=num*2%mod){
		int ma=min(n-de,d);
		if(ma==0)continue;
		//cout<<num<<" "<<ma<<" "<<qzh[ma]<<endl;
		ans+=qzh[ma]*num;
		ans%=mod;
	}
	cout<<ans*2%mod<<endl;		return 0;}