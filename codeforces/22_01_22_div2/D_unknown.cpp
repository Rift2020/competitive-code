#include<bits/stdc++.h>#define rep(i, a, b) for (int i = (a); i <= (b); ++i)	#define per(i, a, b) for (int i = (a); i >= (b); --i)		using namespace std;using ll = long long;int t,n;
vector<string> in;
unordered_set<string> us;
bool fl;
bool isReverse(string s){
	if(s[0]==s[s.size()-1])return true;
	return false;
}signed main(){	ios::sync_with_stdio(false);
	cin.tie(nullptr);	cin>>t;
	while(t--){
		cin>>n;
		in.clear();
		us.clear();
		fl=false;
		in.resize(n);
		for(int i=0;i<n;++i){
			cin>>in[i];
			if(isReverse(in[i]))fl=true;
		}
		if(fl){
			cout<<"YES"<<endl;
			continue;
		}
		for(int i=0;i<n;++i){
			string now=in[i];
			string rnow;
			int sz=now.size();
			for(int i=now.size()-1;i>=0;--i)rnow+=now[i];
			if(sz==3){
				if(us.find(rnow.substr(0,2))!=us.end()){
					fl=true;
					break;
				}
				if(us.find(rnow)!=us.end()){
					fl=true;
					break;
				}
				us.insert(now);
				us.insert(now.substr(0,2)+"*");
			}
			else{
				if(us.find(rnow)!=us.end()){
					fl=true;
					break;
				}
				if(us.find(rnow+"*")!=us.end()){
					fl=true;
					break;
				}
				us.insert(now);
			}
		}
		if(fl)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}				return 0;}