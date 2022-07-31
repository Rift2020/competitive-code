/**
 *    author:  Rift
 *    created: 2022.07.24  22:57
**/
#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
#define x first
#define y second
#define maxv 1100
#define maxn 1100
using namespace std;
using ll = long long;
int t,n,m;
int v[maxn];
int w[maxn];
bitset<maxn> bs[2][maxv];//val,vol
signed main(){
	ios::sync_with_stdio(false),cin.tie(nullptr);
	cin>>t;
	while(t--){
		cin>>n>>m;
		rep(i,0,maxv-1)bs[0][i].reset(),bs[1][i].reset();
		rep(i,1,n){
			cin>>v[i]>>w[i];
		}
		bs[0][0][0]=1;
		rep(i,1,n){
			rep(j,0,1023)
				bs[i&1][j^w[i]]=(bs[!(i&1)][j]<<v[i])|bs[!(i&1)][j^w[i]];
		}
		int ans=-1;
		rep(i,0,maxn-1){
			if(bs[n&1][i][m])ans=i;
		}
		cout<<ans<<endl;
	}

	return 0;
}
