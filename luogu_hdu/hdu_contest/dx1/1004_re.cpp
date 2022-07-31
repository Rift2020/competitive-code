/**
 *    author:  Rift
 *    created: 2022.07.25  14:20
**/
#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
#define x first
#define y second
#define maxm 200005
#define maxn 2005
using namespace std;
using ll = long long;
vector<int> prime;
bool notPrime[maxm];
int t,n,m;
typedef pair<int,int> pr;
typedef tuple<int,int,int> tp;
pr a[maxn];
void EulerSieve(int n){
	notPrime[1]=true;
	for(int i=2;i<=n;++i){
		if(!notPrime[i])
			prime.push_back(i);
		for(const int &p:prime){
			if(p*i>n)break;
			notPrime[p*i]=true;
			if(i%p==0)break;
		}
	}
}
tp dist[maxn*maxn];//dist,i,j
int cnt;
bitset<2005> bs[maxn];//0=bigger,1=smaller
signed main(){
	//freopen("1004.in","r",stdin);
	ios::sync_with_stdio(false),cin.tie(nullptr);
	EulerSieve(maxm-1);
	cin>>t;
	while(t--){
		cin>>n>>m;
		cnt=0;
		rep(i,1,n)bs[i].reset();
		rep(i,1,n)cin>>a[i].x>>a[i].y;
		rep(i,1,n){
			rep(j,i+1,n){
				dist[++cnt]=make_tuple(abs(a[i].x-a[j].x)+abs(a[i].y-a[j].y),i,j);
			}
		}
		sort(dist+1,dist+cnt+1);
		int ans=0;
		rep(i,1,cnt){
			int x=get<1>(dist[i]);
			int y=get<2>(dist[i]);
			if(notPrime[get<0>(dist[i])]==false)
				ans+=(bs[x]^bs[y]).count();
			bs[x][y]=1;
			bs[y][x]=1;
		}
		cout<<ans<<endl;
	}


}
