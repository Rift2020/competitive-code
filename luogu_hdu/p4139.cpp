/**
 *    author:  Rift
 *    created: 2022.08.08  15:38
**/
#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
#define x first
#define y second
#define maxn 10000005
#define int ll
using namespace std;
using ll = long long;
using pr = pair<int,int>;
vector<int> prime;
bool notprime[maxn];
int euler[maxn];
int t,n,mod;
void EulerSieve_euler(int n){
	notprime[1]=true;
	for(int i=2;i<=n;++i){
		if(notprime[i]==false){
			prime.push_back(i);
			euler[i]=i-1;
		}
		for(const int &p:prime){
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
int inline fpow(int x,int n,int mod){
    int re=1;
    while(n){
        if(n&1)
			re=(x*re)%mod;
        x=(x*x)%mod;
        n>>=1;
    }
    return re;
}
int recurrence(int p){
	if(p==1)return 0;
	return fpow(2,recurrence(euler[p])+euler[p],p)%p;
}
signed main(){
	ios::sync_with_stdio(false),cin.tie(nullptr);
	EulerSieve_euler(maxn-1);
	cin>>t;
	while(t--){
		cin>>n;
		cout<<recurrence(n)<<endl;
	}
	
	return 0;
}
