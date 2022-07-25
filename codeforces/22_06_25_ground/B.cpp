#include<bits/stdc++.h>#define rep(i, a, b) for (int i = (a); i <= (b); ++i)	#define per(i, a, b) for (int i = (a); i >= (b); --i)
	#define maxn 100005
		using namespace std;using ll = long long;int t,n;
int a[maxn];signed main(){	ios::sync_with_stdio(false);
	cin.tie(nullptr);	cin>>t;
	while(t--){
		cin>>n;
		rep(i,1,n){
			cin>>a[i];
		}
		int a0=-1;
		bool a1=false;
		bool d=false;
		bool s=false;
		rep(i,1,n){
			if(a[i]==0)a1=true;
			if(a[i]!=0&&a0==-1){
				a0=i;
			}
			else if(a[i]==0&&a0!=-1){
				d=true;
			}
			else if(a[i]!=0&&d){
				s=true;
			}
		}
		if(s)cout<<"2"<<endl;
		else if(a0==-1)cout<<"0"<<endl;
		else cout<<"1"<<endl;
	}				return 0;}