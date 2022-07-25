#include<bits/stdc++.h>#define rep(i, a, b) for (int i = (a); i <= (b); ++i)	#define per(i, a, b) for (int i = (a); i >= (b); --i)
		#define maxn 10005		using namespace std;
		using ll = long long;int t,n;
int a[maxn];
int b[maxn];
int st[maxn];signed main(){	ios::sync_with_stdio(false);
	cin.tie(nullptr);	cin>>t;
	while(t--){
		cin>>n;
		rep(i,1,n){
			cin>>a[i];
			st[i]=a[i];
		}
		sort(st+1,st+n+1);
		bool fl=false;
		rep(i,1,n){
			if(a[i]!=st[i]){
				fl=true;
				break;
			}
		}
		if(fl)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}				return 0;}