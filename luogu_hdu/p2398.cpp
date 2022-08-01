/**
 *    author:  Rift
 *    created: 2022.08.01  15:17
**/
#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
#define x first
#define y second
#define maxn 100005
using namespace std;
using pr = pair<int,int>;
using ll = long long;
vector<int> prime;
int notprime[maxn];
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
			if(p*i>n)break;
			notprime[p*i]=true;
			if(i%p==0){
				euler[i*p]=p*euler[i];
				break;
			}
			else{
				euler[i*p]=(p-1)*euler[i];
			}
		}
	}
}
int n;
signed main(){
	ios::sync_with_stdio(false),cin.tie(nullptr);
	cin>>n;
	EulerSieve_euler(n);
	ll ans=0;
	rep(i,2,n){
		int k=n/i;
		ans+=(1+k)*k/2*euler[i];
	}
	ans*=2;
	ans+=(ll)(1+n)*n/2;
	cout<<ans<<endl;
	
	
	return 0;
}
