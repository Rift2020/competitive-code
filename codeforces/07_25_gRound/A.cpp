#include <iostream>
#include <algorithm>
using namespace std;
int t;
int n;
string s,ss;
int main() {
	ios::sync_with_stdio(false);
	cin>>t;
	for(int i=0;i<t;++i){
		cin>>n;
		cin>>s;
		ss=s;
		sort(s.begin(),s.end());
		int ans=0;
		for(int i=0;i<n;++i){
			if(s[i]!=ss[i])++ans;
		}
		cout<<ans<<endl;
	}
	return 0;
}