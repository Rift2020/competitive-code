/**
 *    author:  Rift
 *    created: 2022.07.28  22:46
**/
#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
#define x first
#define y second
#define maxn 50005
using namespace std;
using ll = long long;
int n;
typedef pair<int,int> pr;
pr a[maxn];
signed main(){
	ios::sync_with_stdio(false),cin.tie(nullptr);
	cin>>n;
	rep(i,1,n){
		int x,y;
		cin>>x>>y;
		a[i].x=x+y;
		a[i].y=x-y;
	}
	int xma=-1e7,yma=-1e7,xmi=1e7,ymi=1e7;
	rep(i,1,n){
		xma=max(xma,a[i].x);
		xmi=min(xmi,a[i].x);
		ymi=min(ymi,a[i].y);
		yma=max(yma,a[i].y);
	}
	cout<<max(xma-xmi,yma-ymi)<<endl;

}
