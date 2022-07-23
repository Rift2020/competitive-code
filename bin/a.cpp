/**
 *    author:  Rift
 *    created: 2021.12.24  22:32
**/
#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
#ifdef LOCAL
#define cout cout<<"\033[32m"
#define endl "\033[0m"<<endl
#endif
using namespace std;
using ll = long long;
int t,n,s;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>t;
	while(t--){
		cin>>n;
		int in;
		s=0;
		while(n--){
			cin>>in;
			s+=in;
		}
		cout<<s<<endl;
		if(s%n==0)cout<<0<<endl;
		else cout<<1<<endl;
	}

	
	#ifdef LOCAL
	fflush(stdin);getchar();
	#endif
	return 0;
}
