#include<bits/stdc++.h>#define rep(i, a, b) for (int i = (a); i <= (b); ++i)#define per(i, a, b) for (int i = (a); i >= (b); --i)
#define maxn 100005
#define mod 1000000007using namespace std;using ll = long long;int n;
int a[maxn];
ll dp[maxn];//长度为i的种数
vector<int> factor[1000005];
void factorSieve(int n){
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n/i;++j){
			factor[i*j].push_back(i);
		}
	}
}
void add(int x){
	if(x==1){
		dp[1]++;
		return;
	}
	dp[x]+=dp[x-1];
	dp[x]%=mod;
}signed main(){	ios::sync_with_stdio(false);	cin>>n;
	int man=0;
	rep(i,1,n){
		cin>>a[i];
		man=max(man,a[i]);
	}
	factorSieve(man);
	rep(i,1,n){
		for(auto j=factor[a[i]].rbegin();j!=factor[a[i]].rend();++j){
			if(*j<maxn)
				add(*j);
		}
	}
	ll ans=0;	rep(i,1,maxn-1){
		ans+=dp[i];
		ans%=mod;
	}	cout<<ans<<endl;		return 0;}