#include<bits/stdc++.h>
#define mod 998244353
#define maxn 1000005
ll mem[maxn];
ll lmem[maxn];
ll qzh[maxn];
ll n,d;
ll ans;
	rep(i,2,maxn-1){
		po[i]=po[i-1]*2%mod;
	}
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
	
		int ma=min(n-de,d);
		if(ma==0)continue;
		//cout<<num<<" "<<ma<<" "<<qzh[ma]<<endl;
		ans+=qzh[ma]*num;
		ans%=mod;
	}
	cout<<ans*2%mod<<endl;