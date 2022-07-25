#include<bits/stdc++.h>#define rep(i, a, b) for (int i = (a); i <= (b); ++i)	#define per(i, a, b) for (int i = (a); i >= (b); --i)
		#define maxn 200005		using namespace std;using ll = long long;
typedef pair<int,int> pr;//h,i
int t,n,m;
int a[maxn];
int h[maxn];
bool vis[maxn];
int ans;signed main(){	ios::sync_with_stdio(false);
	cin.tie(nullptr);	cin>>t;
	while(t--){
		cin>>n>>m;
		rep(i,1,n){
			h[i]=0;
			vis[i]=false;
		}
		priority_queue<pr> d;
		priority_queue<pr,vector<pr>,greater<pr> > x;
		rep(i,1,m){
			cin>>a[i];
			h[a[i]]++;
		}
		ans=0;
		rep(i,1,n){
			ans=max(ans,h[i]);
			d.push({h[i],i});
			x.push({h[i],i});
		}
		while(1){
			pr da=d.top();
			d.pop();
			pr xi=x.top();
			x.pop();
			vis[xi.second]=true;
			if(da.first<=xi.first+1)break;
			if(vis[da.second])break;
			da.first--;
			xi.first+=2;
			d.push(da);
			x.push(xi);
			ans=min(ans,max(d.top().first,xi.first));
		}
		cout<<ans<<endl;
	}				return 0;}