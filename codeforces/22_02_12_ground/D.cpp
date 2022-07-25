#include<bits/stdc++.h>#define rep(i, a, b) for (int i = (a); i <= (b); ++i)	#define per(i, a, b) for (int i = (a); i >= (b); --i)
		#define int ll		using namespace std;using ll = long long;int t,n,m;
typedef struct{
	int i,c;
}pr;
bool operator<(const pr &a,const pr &b){
	if((a.i<b.i&&a.c<=b.c)||(a.i<=b.i&&a.c<b.c))return true;
	return false;
}
vector<pr> v;
unordered_map<int,int> mp;
typedef pair<int,int> ban;
set<ban> st,cl;signed main(){	ios::sync_with_stdio(false);
	cin.tie(nullptr);	cin>>t;
	while(t--){
		cin>>n>>m;
		mp.clear();
		st=cl;
		v.clear();
		rep(i,1,n){
			int in;
			cin>>in;
			mp[in]++;
		}
		for(auto i:mp){
			v.push_back({i.first,i.second});
		}
		sort(v.begin(),v.end());
		rep(i,1,m){
			ban in;
			cin>>in.first>>in.second;
			st.insert(in);
			st.insert({in.second,in.first});
		}
		int ans=0,br=-1;
		for(int i=v.size()-1;i>=0;--i){
			bool one=false;
			for(int j=i-1;j>=0;--j){
				if(st.find({v[i].i,v[j].i})==st.end()){
					one=true;
					if((v[i].i+v[j].i)*(v[i].c+v[j].c)>ans){
						ans=(v[i].i+v[j].i)*(v[i].c+v[j].c);
						br=j;
					}
					
				}
				if(j!=0&&v[j-1]<v[j]&&one)break;
			}
			if(i!=0&&br!=-1&&v[i-1]<v[br])break;
		}
		cout<<ans<<endl;
	}				return 0;}