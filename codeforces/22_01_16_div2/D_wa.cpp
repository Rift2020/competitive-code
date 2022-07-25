#include<bits/stdc++.h>#define rep(i, a, b) for (int i = (a); i <= (b); ++i)	#define per(i, a, b) for (int i = (a); i >= (b); --i)
		#define maxn 200005		using namespace std;using ll = long long;int a[maxn];
int s[maxn];
vector<int> le,ri;
int t,n;
bool ispow2(int x){
	for(int i=1;i<=x;(i=i<<1))if(i==x)return true;
	return false;
}
int need(int x){
	int i;
	for(i=1;i<x;(i=i<<1));
	return i-x;
}signed main(){	ios::sync_with_stdio(false);
	cin.tie(nullptr);	cin>>t;
	while(t--){
		cin>>n;
		le.clear();
		ri.clear();
		for(int i=0;i<=n;++i)a[i]=s[i]=0;
		int in;
		rep(i,1,n){
			cin>>in;
			a[in]++;
		}
		rep(i,1,n){
			s[i]=s[i-1]+a[i];
		}
		rep(i,1,n){
			if(need(s[i])<=1)le.push_back(i);
			if(need(s[n]-s[i-1])<=1)ri.push_back(i);
		}
		reverse(ri.begin(),ri.end());
		int ans=1e9;
		for(int i:le){
			int l=s[i];
			for(int j:ri){
				if(j<=i)break;
				int r=s[n]-s[j-1];
				int m=s[n]-l-r;
				ans=min(ans,need(l)+need(m)+need(r));
				if(ans==0)break;
			}
			if(ans==0)break;
		}
		ans=min(ans,need(s[n])+2);
		cout<<ans<<endl;
	}				return 0;}