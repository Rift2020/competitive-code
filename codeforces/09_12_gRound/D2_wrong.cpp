#include<bits/stdc++.h>
#define maxm 305#define rep(i, a, b) for (int i = (a); i <= (b); ++i)	#define per(i, a, b) for (int i = (a); i >= (b); --i)		using namespace std;using ll = long long int;int t,n,m;
int a[305];
int sa[305];
unordered_map<int,int> um;
bool sit[maxm];int main(){	ios::sync_with_stdio(false);	cin>>t;
	while (t--) {
		um.clear();
		memset(sit,false,sizeof(sit));
		cin>>n>>m;
		rep(i,1,n*m){
			cin>>a[i];
			sa[i]=a[i];
		}
		sort(sa+1,sa+n*m+1);
		rep(i,1,n*m){
			um[sa[i]]=i;
		}
		int ans=0;
		//cout<<':';
		//for(auto i:um)cout<<i.first<<" "<<i.second<<endl;
		//cout<<'/'<<endl;
		rep(i,1,n*m){
			int w=um[a[i]];
			um[a[i]]--;
			int l=w/m;
			if(w%m==0)--l;
			l=l*m+1;
			rep(i,l,w)if(sit[i])++ans;
			sit[w]=true;
		}
		cout<<ans<<endl;
	}				return 0;}