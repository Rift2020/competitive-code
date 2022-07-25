#include<bits/stdc++.h>#define rep(i, a, b) for (int i = (a); i <= (b); ++i)	#define per(i, a, b) for (int i = (a); i >= (b); --i)
		#define maxn 105		using namespace std;using ll = long long;int t;
int n;
int k[maxn];
int h[maxn];
typedef pair<int,int> pr;//le,ri
vector<pr> v;signed main(){	ios::sync_with_stdio(false);
	cin.tie(nullptr);	cin>>t;
	while(t--){
		cin>>n;
		v.clear();
		rep(i,1,n)cin>>k[i];
		rep(i,1,n)cin>>h[i];
		rep(i,1,n){
			v.push_back({k[i]-h[i]+1,k[i]});
		}
		sort(v.begin(),v.end());

		ll ans=0;
		for(int i=0;i<v.size();){
			int le=v[i].first,ri=v[i].second;
			for(i=i+1;i<v.size();++i){
				int jle=v[i].first,jri=v[i].second;
				if(jle<=ri){
					ri=max(ri,jri);
				}
				else{
					break;
				}
			}
			ans+=((ll)(1+ri-le+1))*(ri-le+1)/2;
		}
		cout<<ans<<endl;
	}				return 0;}