#include <iostream>
#include <vector>
#define ll long long
using namespace std;
vector<string> v;
int t,n,m;
int main() {
	ios::sync_with_stdio(false);
	for(ll i=1;i<1e18+5;i*=2){
		v.push_back(to_string(i));
	}
	cin>>t;
	while (t--) {
		cin>>n;
		string a=to_string(n);
		m=1e9;
		for(string b:v){
			int i=0,s=0;
			for(char c:b){
				for(;i<a.size();++i){
					if(a[i]==c){
						++i;
						++s;
						break;
					}
				}
			}
			//cout<<a<<" "<<b<<endl;
			//cout<<s<<endl;
			//if(a.size()+b.size()-2*s<m)
				//cout<<a<<" "<<b<<" "<<s<<endl;
			m=min(m,(int)(a.size()+b.size()-2*s));
		}
		cout<<m<<endl;
	}
	
	return 0;
}