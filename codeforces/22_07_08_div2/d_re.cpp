/**
 *    author:  Rift
 *    created: 2022.07.09  09:52
**/
#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
#define maxn 500005
using namespace std;
using ll = long long;
int t,n;
int ans[maxn];
typedef struct{
	int l,r,ind;
} st;
bool cmp_l(st a,st b){
	return a.l<b.l;
}
st a[maxn];
struct cmp_r_b{
	bool operator()(st a,st b){
		return a.r>b.r;
	}
};
priority_queue<st,vector<st>,cmp_r_b> pq,cl;

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>t;
	while(t--){
		cin>>n;
		pq=cl;
		rep(i,1,n){
			int in;
			cin>>in;
			int l,r;
			if(in==0){
				l=i+1;
				r=n;
			}
			else{
                l=(i/(in+1))+1;
				r=i/in;
			}
			a[i]=(st){l,r,i};
		}
		sort(a+1,a+n+1,cmp_l);
		int p=1;
		rep(i,1,n){
			for(;a[p].l<=i&&p<=n;++p){
				pq.push(a[p]);
			}
			ans[pq.top().ind]=i;
			pq.pop();
		}
		rep(i,1,n)
			cout<<ans[i]<<" ";
		cout<<endl;
	}

	return 0;
}
