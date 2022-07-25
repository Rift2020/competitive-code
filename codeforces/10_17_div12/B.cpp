#include<bits/stdc++.h>#define rep(i, a, b) for (int i = (a); i <= (b); ++i)	#define per(i, a, b) for (int i = (a); i >= (b); --i)
		#define maxn 100005		using namespace std;using ll = long long int;
int t;
int n;
int m;bool use[maxn];int main(){	ios::sync_with_stdio(false);	cin>>t;
	while(t--){
		cin>>n;
		memset(use,false,sizeof(use));
		int a,b,c;
		cin>>m;
		rep(o,1,m){
			cin>>a>>b>>c;
			use[b]=true;
		}
		int s;
		rep(i,1,n){
			if(use[i]==false){
				s=i;
			}
		}
		rep(i,1,n){
			if(i==s)continue;
			cout<<i<<" "<<s<<endl;
		}
	}				return 0;}