/**
 *    author:  Rift
 *    created: 2022.07.08  22:34
**/
#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
using namespace std;
using ll = long long;
int t;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>t;
	while(t--){
		int cnt=0,in;
		rep(i,1,4){
			cin>>in;
			cnt+=in;
		}
		if(cnt==0)
			cout<<0<<endl;
		else if(cnt==4)
			cout<<2<<endl;
		else
			cout<<1<<endl;
	}


}
