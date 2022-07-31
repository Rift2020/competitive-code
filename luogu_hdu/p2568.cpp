/**
 *    author:  Rift
 *    created: 2022.08.01  00:05
**/
#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
#define x first
#define y second
#define maxn 10000005
using namespace std;
using ll = long long;
vector<int> prime;
bool notprime[maxn];
int euler[maxn];
void EulerSieve_euler(int n){
	notprime[1]=true;
	euler[1]=1;
	for(int i=2;i<=n;++i){
		if(notprime[i]==false){
			prime.push_back(i);
			euler[i]=i-1;
		}
		for(int p:prime){
			if(i*p>n)break;
			notprime[i*p]=true;
			if(i%p==0){
				euler[i*p]=euler[i]*p;
				break;
			}
			else
				euler[i*p]=euler[i]*(p-1);
		}
	}
}
signed main(){
	ios::sync_with_stdio(false),cin.tie(nullptr);
	int n;
	cin>>n;
	EulerSieve_euler(n);
	ll ans=0;
	for(int i=2;i<=n/2;++i){
		ans+=(ll)(upper_bound(prime.begin(),prime.end(),n/i)-prime.begin())*euler[i]*2;
	}
	ans+=prime.size();
	cout<<ans<<endl;

}
