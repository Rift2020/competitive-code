#include<bits/stdc++.h>#define rep(i, a, b) for (int i = (a); i <= (b); ++i)	#define per(i, a, b) for (int i = (a); i >= (b); --i)
		#define maxn 100005		using namespace std;using ll = long long;int t,n;
int a[maxn];signed main(){	ios::sync_with_stdio(false);
	cin.tie(nullptr);	cin>>t;
	while(t--){
		cin>>n;
		rep(i,1,n){
			cin>>a[i];
		}
		bool fl=false,notone=false;
		ll ans=0;
		rep(i,2,n-1){
			if(a[i]>1)notone=true;
			if(a[i]%2==0){
				fl=true;
				ans+=a[i]/2;
			}
			else{
				ans+=a[i]/2+1;
			}
		}
		if(fl||(notone&&n>3))cout<<ans<<endl;
		else cout<<-1<<endl;
	}				return 0;}