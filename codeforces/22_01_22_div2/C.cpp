#include<bits/stdc++.h>#define rep(i, a, b) for (int i = (a); i <= (b); ++i)	#define per(i, a, b) for (int i = (a); i >= (b); --i)
		#define maxn 200005		using namespace std;using ll = long long;int t,n;
vector<int> v[maxn];//v[i][j]，数字i的第j+1次出现的位置
int ind[maxn];//v[i]的当前“指针”
int ans[maxn],cnt=-1;signed main(){	ios::sync_with_stdio(false);
	cin.tie(nullptr);	cin>>t;
	while(t--){
		cin>>n;
		cnt=-1;
		for(int i=0;i<=n;++i){
			v[i].clear();
			ind[i]=0;
		}
		rep(i,1,n){
			int in;
			cin>>in;
			v[in].push_back(i);
		}
		for(int now=0;now<=n;){
			int k=now;
			int add=0;
			for(int i=0;i<=n;++i){
				while(ind[i]<v[i].size()&&v[i][ind[i]]<=now)ind[i]++;
				if(ind[i]>=v[i].size())break;
				k=max(k,v[i][ind[i]]);
				add=i+1;
			}
			if(k==now)now++;
			else now=k;
			ans[++cnt]=add;
		}
		cout<<cnt<<endl;
		for(int i=0;i<cnt;++i){
			cout<<ans[i]<<" ";
		}
		cout<<endl;
	}				return 0;}