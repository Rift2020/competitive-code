#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
	#define per(i, a, b) for (int i = (a); i >= (b); --i)
	#define maxn 1005
		using namespace std;
using ll = long long int;
int t,n,m,u,cnt;
unordered_map<string,int> um;
bool ig[maxn];
vector<int> v[maxn];
typedef pair<bool,int> pr;
pr dfs(int x){

	if(ig[x])return {true,1};
	bool fl=true;
	int re=0;
	for(int i:v[x]){
	    pr p=dfs(i);
	    if(p.first!=true)fl=false;
		re+=p.second;
	}
	if(fl== true&&x!=0&&v[x].size()!=0)return {true,1};
	return {false,re};
}
int main(){
	ios::sync_with_stdio(false);
	cin>>t;
	while(t--){
		cin>>n>>m;
		rep(i,1,maxn-1)v[i].clear();
		um.clear();
		memset(ig,false,sizeof(ig));
		for(int o=0;o<n;++o){
			string in;
			cin>>in;
			in+='/';
			u=0;
			for(int i=0;i<in.size();++i){
				if(in[i]=='/'){
					if(um.find(in.substr(0,i+1))==um.end()){
						um[in.substr(0,i+1)]=++cnt;
						v[u].push_back(cnt);
					}
					u=um[in.substr(0,i+1)];
				}
			}
			ig[um[in]]=true;
		}
		for(int o=0;o<m;++o){
			string in;
			cin>>in;
			in+='/';
			u=0;
			for(int i=0;i<in.size();++i){
				if(in[i]=='/'){
					if(um.find(in.substr(0,i+1))==um.end()){
						um[in.substr(0,i+1)]=++cnt;
						v[u].push_back(cnt);
					}
					u=um[in.substr(0,i+1)];
				}
			}
		}
		cout<<dfs(0).second<<endl;
	}



	return 0;
}