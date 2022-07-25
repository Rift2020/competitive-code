#include<bits/stdc++.h>#define rep(i, a, b) for (int i = (a); i <= (b); ++i)	#define per(i, a, b) for (int i = (a); i >= (b); --i)
		#define maxn 200005		using namespace std;using ll = long long int;int t,n;
typedef pair<int,int> pr;
pr a[maxn];
priority_queue<pr> dg,dcl;
priority_queue<pr,vector<pr>,greater<pr> > xg,xcl;
bool used[maxn];
int cnt;int main(){	ios::sync_with_stdio(false);	cin>>t;
	while(t--){
		cin>>n;
		dg=dcl;
		xg=xcl;
		memset(used,false,sizeof(used));
		cnt=0;
		rep(i,1,n){
			cin>>a[i].first;
			a[i].second=i;
			dg.push(a[i]);
			xg.push(a[i]);
		}
		while(cnt!=n-1){
			int x=xg.top().first;
			int xnd=xg.top().second;
			xg.pop();
			used[xnd]=true;
			int dnd=dg.top().second;
			while(!dg.empty()&&used[dg.top().second]){
				dg.pop();
				dnd=dg.top().second;
			}
			int d=dg.top().first;
			dg.pop();
			d-=x;
			rep(i,1,x){
				cout<<xnd<<" "<<dnd<<endl;
			}
			if(d>0){
				cnt++;
				dg.push(pr{d,dnd});
			}
			else{
				cnt+=2;
			}
		}
	}
					return 0;}