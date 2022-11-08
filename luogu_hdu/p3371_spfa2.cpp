/**
 *    author:  Rift
 *    created: 2022.11.08  16:15
**/
#include<bits/stdc++.h>
#include <climits>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
#define x first
#define y second
#define maxn 200005
using namespace std;
using ll = long long;
using pr = pair<int,int>;
int n,m,s;
vector<pr> g[maxn];
int dis[maxn],cnt[maxn];
bool inq[maxn];
queue<int> q;
bool spfa(){
    dis[s]=0;
    q.push(s);
    while(!q.empty()){
        int u=q.front();
        q.pop();
        inq[u]=false;
        for(auto i:g[u]){
            int v=i.x,w=i.y;
            if(dis[u]+w<dis[v]){
                cnt[v]=cnt[u]+1;
                dis[v]=dis[u]+w;
                if(cnt[v]>=n)return false;
                if(inq[v]==false){
                    q.push(v);
                    inq[v]=true;
                }
            }
        }
    }
    return true;
}

signed main(){
	ios::sync_with_stdio(false),cin.tie(nullptr);
	cin>>n>>m>>s;
	for(int i=0;i<=n;++i)dis[i]=INT_MAX;
	rep(i,1,m){
		int u,v,w;
		cin>>u>>v>>w;
		g[u].push_back({v,w});
	}
	spfa();
	rep(i,1,n)
		cout<<dis[i]<<" ";
	cout<<endl;
	return 0;
}
