#include <bits/stdc++.h>
#define maxn 200005
#define mod 998244353
#define int long long
using namespace std;
int t,n,ma;
int fac[maxn];
unordered_map<int,int> um;
void exgcd(int a,int b,int &x,int &y){
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