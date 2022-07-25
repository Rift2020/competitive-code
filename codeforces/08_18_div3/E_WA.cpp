#include <iostream>
#include <vector>
#include <map>
using namespace std;
int t;
vector<char> ans2;
map<char,int> mp;
int n;
int main() {
	cin>>t;
	while (t--) {
		string s;
		cin>>s;
		ans2.clear();
		mp.clear();
		bool fl=true;
		for(int i=s.size()-1;i>=0;--i){
			if(mp.find(s[i])==mp.end()){
				mp[s[i]]=1;
				ans2.push_back(s[i]);
			}
			else{
				mp[s[i]]++;
			}
		}
		n=ans2.size();
		int len=0;
		for(int i=0;i<n;++i){
			if(mp[ans2[i]]%(n-i)!=0){
				fl=false;
				break;
			}
			len+=mp[ans2[i]]/(n-i);
		}
		if(fl==false){
			cout<<-1<<endl;
			continue;
		}
		string ans=s.substr(0,len);
		cout<<ans<<" ";
		for(int i=n-1;i>=0;--i){
			cout<<ans2[i];
		}
		cout<<endl;
	}
	
	return 0;
}