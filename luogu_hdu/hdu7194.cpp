/**
 *    author:  Rift
 *    created: 2022.10.26  23:59
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
unordered_set<int> a,b;
signed main(){
	ios::sync_with_stdio(false),cin.tie(nullptr);
	cin>>t;
	while(t--){
		a.clear();
		b.clear();
		cin>>n;
		int in;
		rep(i,1,n){
			cin>>in;
			a.insert(in);
		}
		rep(i,1,n){
			cin>>in;
			b.insert(in);
		}
		if(a.size()==n&&b.size()==n)
			cout<<"Just a game of chance."<<endl;
		else
			cout<<"Win!"<<endl;
	}
	
	
	return 0;
}
