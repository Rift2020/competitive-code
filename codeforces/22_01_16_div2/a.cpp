/**
 *    author:  Rift
 *    created: 2022.01.16  22:31
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
int i;
string s;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>i;
	while(i--){
		cin>>s;
		sort(s.begin(),s.end());
		cout<<s<<endl;
	}


	#ifdef LOCAL
	fflush(stdio);getchar();
	#endif
	return 0;
}
