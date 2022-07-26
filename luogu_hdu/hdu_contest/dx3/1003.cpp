/**
 *    author:  Rift
 *    created: 2022.07.26  12:05
**/
#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
#define x first
#define y second
using namespace std;
using ll = long long;
int t;
string s;
signed main(){
	ios::sync_with_stdio(false),cin.tie(nullptr);
	cin>>t;
    cin.ignore();
	while(t--){
		getline(cin,s);
		string ans;
		bool ok=true;
		for(char c:s){
			if(ok){
				ans+=c+'A'-'a';
				ok=false;
			}
			else if(c==' ')
				ok=true;
		}
		cout<<ans<<endl;
	}



}
