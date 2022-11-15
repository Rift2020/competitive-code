/**
 *    author:  Rift
 *    created: 2022.11.10  01:05
**/
#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
#define x first
#define y second
#define maxn 10005
using namespace std;
using ll = long long;
using pr = pair<int,int>;
int t,n;
signed main(){
	ios::sync_with_stdio(false),cin.tie(nullptr);
	cin>>t;
	while(t--){
		cin>>n;
		int sg=0;
		int in;
		rep(i,1,n){
			cin>>in;
			sg^=in;
		}
		if(sg){
			cout<<"Yes"<<endl;
		}
		else
			cout<<"No"<<endl;
	}
	
	
	return 0;
}
