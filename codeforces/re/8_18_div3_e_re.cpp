#include <iostream>
#include <vector>
#include <map>
#include<string.h>
using namespace std;
int t;
vector<char> ans2;
map<char,int> mp;
int n;
bool del[30];
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
        string t=ans;
		memset(del,0,sizeof(del));
		for(int i=n-1;i>=0;--i){
			del[ans2[i]-'a']=true;
			string add;
			for(const char &c:ans){
				if(del[c-'a'])continue;
				add+=c;
			}
			t+=add;
		}
		if(t!=s){
			cout<<-1<<endl;
			continue;
		}
		cout<<ans<<" ";
		for(int i=n-1;i>=0;--i){
			cout<<ans2[i];
		}
		cout<<endl;
	}
	
	return 0;
}