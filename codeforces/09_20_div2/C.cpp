#include<bits/stdc++.h>#define rep(i, a, b) for (int i = (a); i <= (b); ++i)	#define per(i, a, b) for (int i = (a); i >= (b); --i)	#define maxn 200005
		using namespace std;using ll = long long int;ll n,m,x,y,s;
ll a[maxn];int main(){	ios::sync_with_stdio(false);	cin>>n;
	for(int i=0;i<n;++i)cin>>a[i];
	sort(a,a+n);
	for(int i=0;i<n;++i)s+=a[i];
	cin>>m;
	while (m--) {
		cin>>x>>y;
		if(lower_bound(a,a+n,x)==a+n){
			ll now=a[n-1];
			cout<<x-now+max(0LL,y-s+now)<<endl;
		}
		else if(lower_bound(a,a+n,x)==a){
			ll now=a[0];
			cout<<max(0LL,y-s+now)<<endl;
		}
		else{
			ll now=*lower_bound(a,a+n,x);
			ll la=*(lower_bound(a,a+n,x)-1);
			cout<<min(x-la+max(0LL,y-s+la),max(0LL,y-s+now))<<endl;
		}
	}				return 0;}