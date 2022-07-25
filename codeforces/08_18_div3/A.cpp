#include <iostream>
#include <vector>
using namespace std;
bool has3(int x){
	string s=to_string(x);
	if(s[s.size()-1]=='3')return true;
	return false;
}
vector<int> v;
int main() {
	ios::sync_with_stdio(false);
	int t,k;
	v.push_back(0);
	for(int i=1;v.size()<1005;++i){
		if(i%3==0||has3(i))continue;
		v.push_back(i);
		//cout<<i<<endl;
	}
	cin>>t;
	while (t--) {
		cin>>k;
		cout<<v[k]<<endl;
	}
	
	
	return 0;
}