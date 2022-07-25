#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
#define maxn 100005
using namespace std;
using ll = long long;
int n;
int a[maxn];
int l[maxn],r[maxn];
signed main(){
	ios::sync_with_stdio(false);
	while(1){
		cin>>n;
		if(n==0)break;
		rep(i,1,n)cin>>a[i];
		rep(i,1,n)l[i]=r[i]=i;
		for (int i = 1; i <= n; i++)
			for(int le=i-1;l[i]>1&&a[i]<=a[le];le=min(l[i],--le))l[i]=l[le];
		for (int i = n; i >= 1; i--)
			for(int ri=i+1;r[i]<n&&a[i]<=a[ri];ri=max(r[i],++ri))r[i]=r[ri];

		ll ans=0;
		rep(i,1,n){
			ans=max(ans,((ll)a[i])*(r[i]-l[i]+1));
		}
		cout<<ans<<endl;
	}
	
	return 0;
}