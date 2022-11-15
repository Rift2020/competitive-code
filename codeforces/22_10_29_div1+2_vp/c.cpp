/**
 *    author:  Rift
 *    created: 2022.10.30  15:18
**/
#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
#define x first
#define y second
#define maxn 200005
#define int ll
using namespace std;
using ll = long long;
using pr = pair<int,int>;
int t,n;
int a[maxn];
signed main(){
	ios::sync_with_stdio(false),cin.tie(nullptr);
	cin>>t;
	while(t--){
		cin>>n;
		rep(i,1,n)cin>>a[i];
		sort(a+1,a+1+n);
		int ans=0;
		rep(i,2,n-1){
			ans=max(ans,abs(a[i]-a[1])+min(abs(a[i]-a[i+1]),abs(a[i]-a[i-1])));

			ans=max(ans,abs(a[i]-a[n])+min(abs(a[i]-a[i+1]),abs(a[i]-a[i-1])));
		}
		ans=max(ans,abs(a[1]-a[2])+abs(a[1]-a[n]));
		
		ans=max(ans,abs(a[n]-a[n-1])+abs(a[1]-a[n]));
		cout<<ans<<endl;
	}
	
	
	return 0;
}
