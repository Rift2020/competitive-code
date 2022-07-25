#include <iostream>

using namespace std;
int q;
string s,t;
bool inline check(int x){
	string a;
	a=s[x];
	if(a==t)return true;
	int i;
	for(i=1;i<s.size()&&i<t.size();++i){
		if(s[x+i]==t[i]){
			a+=s[x+i];
		}
		else{
			break;
		}
	}
	int j=i;
		i-=2;
	for(;x+i>=0&&j<t.size()&&a.size()<t.size();--i,++j){
		if(s[x+i]==t[j]){
			a+=s[x+i];
		}
		else{
			break;
		}
	}
	//cout<<a<<" ";
	if(a==t)return true;
	return false;
}
int main() {
	ios::sync_with_stdio(false);
	cin>>q;
	for(int i=0;i<q;++i){
		bool f=false;
		cin>>s;
		cin>>t;
		for(int i=0;i<s.size();++i){
			if(s[i]==t[0]){
				if(check(i)){
					cout<<"YES"<<endl;
					f=true;
					break;
				}
			}
		}
		if(f==false)cout<<"NO"<<endl;
	}
	return 0;
}