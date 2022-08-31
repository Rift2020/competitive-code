/**
 *    author:  Rift
 *    created: 2022.08.23  12:11
**/
#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
#define x first
#define y second
using namespace std;
using ll = long long;
using pr = pair<int,int>;
ll p[30],k[30],cnt=0;
void factor(ll n){
	for(ll i=2;i*i<=n;++i){
		if(n%i==0){
			p[++cnt]=i;
			k[cnt]=1;
			n/=i;
			while(n%i==0){
				n/=i;
				k[cnt]++;
			}
		}
	}
	if(n>1){
		p[++cnt]=n;
		k[cnt]=1;
	}
}
signed main(){
	ios::sync_with_stdio(false),cin.tie(nullptr);
	int n;
	cin>>n;
	factor(n);
	rep(i,1,cnt){
		cout<<p[i]<<" "<<k[i]<<endl;
	}
	
	
	return 0;
}
