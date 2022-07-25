#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
using namespace std;
int t,n;
string in;
vector<int> ans;
int pow(int x,int n){
	int re=1;
	for(int i=0;i<n;++i)re*=x;
	return re;
}
void dfs(int x){
	if(n==1){
		ans.push_back(atoi(in.substr(x).c_str()));
		return;
	}
	int now=atoi(in.substr(x).c_str());
	int ok;
	for(int i=0;i<=in[x];++i){
		if(now-i*pow(10,in.size()-1-x)>=n)ok=i;
		else break;
	}
	if(ok==in[x]){
		ans.push_back(ok*pow(10,in.size()-1-x));
		--n;
		dfs(x+1);
	}
	else{
		ans.push_back(ok*pow(10,in.size()-1-x));
		--n;
		now-=ok*pow(10,in.size()-1-x);
		while (n!=1) {
			ans.push_back(1);
			--n;
			now--;
		}
		ans.push_back(now);
		return;
	}
	
}
int main() {
	ios::sync_with_stdio(false);
	cin>>t;
	while(t--){
		ans.clear();
		cin>>in>>n;
		dfs(0);
		for(auto i:ans)cout<<i<<" ";
		cout<<endl;
	}
	
	
	
	return 0;
}