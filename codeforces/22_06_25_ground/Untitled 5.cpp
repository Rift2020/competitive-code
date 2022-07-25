#include<bits/stdc++.h>#define rep(i, a, b) for (int i = (a); i <= (b); ++i)	#define per(i, a, b) for (int i = (a); i >= (b); --i)
		#define maxn 250005		using namespace std;using ll = long long;int t,n;
int a[maxn];
int ru[maxn];
int rd[maxn];signed main(){	ios::sync_with_stdio(false);
	cin.tie(nullptr);	cin>>t;
	while(t--){
		cin>>n;
		rep(i,1,n){
			cin>>a[i];
		}
		int ans=0,now=1;		while(now!=n){
			int mi=a[now];
			int ma=a[now];
			for(int i=now+1;;++i){
				if(a[i]>=mi&&a[i]<=ma){
					now=i-1;
					break;
				}
				mi=min(mi,a[i]);
				ma=max(ma,a[i]);
				if(mi!=a[now]&&ma!=a[now]){
					now=i-1;
					break;
				}
				if(i==n){
					now=n;
					break;
				}
			}
			++ans;
		}		cout<<ans<<endl;
	}		return 0;}