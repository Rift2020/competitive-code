/**
  *    author:  Rift
  *    created: 2022.10.30  14:26
  **/
#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
#define x first
#define y second
#define maxn 200005
using namespace std;
using ll = long long;
using pr = pair<int,int>;
int t,n;
pr a[maxn],s[maxn];
signed main(){
	ios::sync_with_stdio(false),cin.tie(nullptr);
	cin>>t;
	while(t--){
		cin>>n;
		ll ma=0,ans=0;
		rep(i,1,n){
			cin>>s[i].x>>s[i].y;
			if(s[i].x>s[i].y)
				swap(s[i].x,s[i].y);
			ma=max(ma,(ll)s[i].y);
			ans+=s[i].x;
		}
		ans=ans*2+ma*2;
		
		cout<<ans<<endl;
	}



	return 0;
}
