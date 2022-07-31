/**
 *    author:  Rift
 *    created: 2022.07.26  12:17
**/
#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
#define x first
#define y second
#define maxn 1000005
using namespace std;
using ll = long long;
int t;
int n,k,ans;
typedef pair<int,int> pr;
pr a[maxn];
priority_queue<int,vector<int>,greater<int> >pq,cl;
void take(){
	if(k>pq.size()){
		++ans;
		pq=cl;
	}
	else{
		ans++;
		rep(i,1,k)pq.pop();
	}
}
signed main(){
	ios::sync_with_stdio(false),cin.tie(nullptr);
	cin>>t;
	while(t--){
		pq=cl;
		ans=0;
		cin>>n>>k;
		rep(i,1,n){
			cin>>a[i].x>>a[i].y;
		}
		sort(a+1,a+n+1);
		pq.push(a[1].y);
		rep(i,2,n){
			int nex=a[i].x;
			while(!pq.empty()&&nex>pq.top())
				take();
			pq.push(a[i].y);
		}
		while(!pq.empty())take();
		cout<<ans<<endl;
	}



}
