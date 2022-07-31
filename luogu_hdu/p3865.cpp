/**
 *    author:  Rift
 *    created: 2022.07.29  11:11
**/
#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
#define x first
#define y second
#define endl '\n'
#define maxn 100005
#define maxl 22
using namespace std;
using pr = pair<int,int>;
using ll = long long;
int n,m;
int logn[maxn];
int f[maxl][maxn];
void init(){
	logn[1]=0;
	rep(i,2,n)
		logn[i]=logn[i/2]+1;
	for(int j=1;j<=logn[n]+1;++j){
		for(int i=1;i+(1<<j)-1<=n;++i){
			f[j][i]=max(f[j-1][i],f[j-1][i+(1<<(j-1))]);
		}
	}
}
int query(int l,int r){
	int s=logn[r-l+1];
	return max(f[s][l],f[s][r-(1<<s)+1]);
}
signed main(){
	ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
	cin>>n>>m;
	rep(i,1,n)cin>>f[0][i];
	init();
	rep(i,1,m){
		int l,r;
		cin>>l>>r;
		cout<<query(l,r)<<endl;
	}
	
	return 0;
}
