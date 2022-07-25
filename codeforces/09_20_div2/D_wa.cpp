#include<bits/stdc++.h>#define rep(i, a, b) for (int i = (a); i <= (b); ++i)	#define per(i, a, b) for (int i = (a); i >= (b); --i)
		#define maxn 12
		#define maxm 200005		using namespace std;using ll = long long int;
typedef  pair<int,int> pr;//a,iint n,m,p[maxn],a[maxn];
vector<int> slot[maxn];
unordered_set<string> ban;int main(){	ios::sync_with_stdio(false);	cin>>n;
	rep(i,1,n){
		int c;
		cin>>c;		
		rep(j,1,c){
			int in;
			cin>>in;
			slot[i].push_back(in);
		}
	}	cin>>m;
	rep(i,0,m-1){
		string in;
		rep(j,1,n){
			int inn;
			cin>>inn;
			in+=char('0'+inn);
		}
		ban.insert(in);
	}
	rep(i,1,n)p[i]=slot[i].size()-1;	while (1) {
		string now;
		rep(i,1,n){
			now+=char('0'+p[i]+1);
		}
		if(ban.find(now)==ban.end()){
			rep(i,1,n){
				cout<<p[i]+1<<" ";
			}
			cout<<endl;
			return 0;
		}
		memset(a,0x3f,sizeof(a));
		int po=0,mi=INT_MAX;
		rep(i,1,n){
			if(p[i]>0){
				int ind=p[i];
				a[i]=slot[i][ind]-slot[i][ind-1];
			}
			if(a[i]<mi){
				po=i;
				mi=a[i];
			}
		}
		p[po]--;
	}
	
	
		return 0;}