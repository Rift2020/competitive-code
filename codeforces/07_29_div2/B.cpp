#include <iostream>
#define maxn 100005
#define ll long long
#define int long long
using namespace std;
int t,n,k;
int a[maxn];
signed main() {
	ios::sync_with_stdio(false);
	cin>>t;
	for(int o=0;o<t;++o){
		cin>>n>>k;
		for(int i=1;i<=n;++i)cin>>a[i];
		ll ma=-(ll)maxn*maxn*105;
		for(int i=n;i>0;--i){
			for(int j=i-1;j>0&&i*j>ma;--j){
				ma=max(ma,(ll)i*j-k*(a[i]|a[j]));
			}
		}
		cout<<ma<<endl;
	}
	return 0;
}