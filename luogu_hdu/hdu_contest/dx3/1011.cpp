/**
 *    author:  Rift
 *    created: 2022.07.29  10:28
**/
#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
#define x first
#define y second
#define maxn 100005
#define maxl 21
using namespace std;
using pr = pair<int,int>;
using ll = long long;
typedef struct{
	int x,y,w;
}st;
bool operator<(st a,st b){
	return a.w<b.w;
}
int t,n,q;
st a[maxn];
int xma[maxn][maxl],xmi[maxn][maxl],yma[maxn][maxl],ymi[maxn][maxl];
int logn[maxn];
signed main(){
	ios::sync_with_stdio(false),cin.tie(nullptr);
	cin>>t;
	while(t--){
		cin>>n>>q;
		rep(i,1,n){
			int x,y;
			cin>>x>>y>>a[i].w;
			a[i].x=x+y;
			a[i].y=x-y;
		}
		sort(a+1,a+n+1);
		
	}
	
	
	return 0;
}
