#include<bits/stdc++.h>#define rep(i, a, b) for (int i = (a); i <= (b); ++i)	#define per(i, a, b) for (int i = (a); i >= (b); --i)
		#define maxn 100005		using namespace std;using ll = long long int;int t,n;
char a[maxn];
char b[maxn];
int r[maxn];int main(){	ios::sync_with_stdio(false);	cin>>t;
	while (t--) {
		cin>>n;
		rep(i,1,n)cin>>a[i];
		rep(i,1,n)cin>>b[i];
		rep(i,1,n){
			if(a[i]=='0'&&b[i]=='0')r[i]=1;
			else if(a[i]=='1'&&b[i]=='1')r[i]=0;
			else r[i]=2;
		}
		int ans=0;
		rep(i,1,n){
			if(i<n&&((r[i]==1&&r[i+1]==0)||(r[i]==0&&r[i+1]==1))){
				++i;
				ans+=2;
			}
			else ans+=r[i];
		}
		cout<<ans<<endl;
	}				return 0;}