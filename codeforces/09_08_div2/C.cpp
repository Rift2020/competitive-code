#include <bits/stdc++.h>
#define maxn 200005
#define mod 998244353
#define int long long
using namespace std;
int t,n,ma;
int fac[maxn];
unordered_map<int,int> um;
void exgcd(int a,int b,int &x,int &y){	if(b==0){		x=1;		y=0;		return;	}	exgcd(b,a%b,y,x);	y-=x*(a/b);}int mod_inverse(int a,int m){	int x,y;	exgcd(a,m,x,y);	return (m+x%m)%m;}int fact(int x){	return fac[x];}int inline fpow(int x,int n){	int re=1;	while(n){	if(n&1)	re=(x*re)%mod;	x=(x*x)%mod;	n>>=1;	}	return re;	}int C(int m,int n){	int fm=fact(m)*fact(n-m);	fm%=mod;	fm=fpow(fm,mod-2);	int fz=fact(n);	return (fz*fm)%mod;}
signed main() {
	ios::sync_with_stdio(false);
	fac[0]=fac[1]=1;
	for(int i=2;i<maxn;++i){
		fac[i]=fac[i-1]*i%mod;
	}
	cin>>t;
	while (t--) {
		um.clear();
		cin>>n;
		ma=0;
		for(int i=0;i<n;++i){
			int in;
			cin>>in;
			ma=max(ma,in);
			um[in]++;
		}
		if(um[ma]>=2){
			cout<<fac[n]<<endl;
		}else if(um[ma]==1&&um[ma-1]==0){
			cout<<0<<endl;
		}
		else{
			int ans=fac[n];
			int p=n-1-um[ma-1];
			for(int i=0;i<=p;++i){
				ans-=C(i,p)%mod*fac[i]%mod*fac[n-i-1]%mod;
				ans%=mod;
			}
			cout<<(ans%mod+mod)%mod<<endl;
		}
	}
	
	return 0;
}