/**
 *    author:  Rift
 *    created: 2022.07.26  13:49
**/
#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
#define x first
#define y second
#define int ll
#define maxn 300005
using namespace std;
using ll = long long;
int t,n;
int p[maxn];
int q[maxn];
int s[maxn*2];
typedef pair<int,int> pr;
map<pr,int> um;
priority_queue<pr> pq,cl;
signed main(){
	ios::sync_with_stdio(false),cin.tie(nullptr);
	cin>>t;
	while(t--){
		pq=cl;
		cin>>n;
		rep(i,1,n){
			cin>>p[i];
		}
		rep(i,1,n){
			cin>>q[i];
		}
		rep(i,1,2*n){
			cin>>s[i];
		}
		pq.push({0,0});
		pr pp={0,0};
		um[pp]=1;
		bool fl=false;
		while(!pq.empty()){
			pr now=pq.top();
			int v=um[now];
			pq.pop();
			if(now.x==n&&now.y==n){
				cout<<v<<endl;
				fl=true;
				break;
			}
			if(p[now.x+1]==s[now.x+now.y+1]){
				pr nex={now.x+1,now.y};
				pq.push(nex);
				um[nex]+=v;
			}
			if(q[now.y+1]==s[now.x+now.y+1]){
				pr nex={now.x,now.y+1};
				pq.push(nex);
				um[nex]+=v;
			}
		}
		if(fl==false){
			cout<<-1<<endl;
		}
	}



}
