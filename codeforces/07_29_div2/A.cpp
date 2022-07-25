#include <iostream>
#define maxn 100005
#define ll long long
using namespace std;
int t,n;
int a[maxn];
int main() {
	ios::sync_with_stdio(false);
	cin>>t;
	for(int o=0;o<t;++o){
		cin>>n;
		for(int i=0;i<n;++i)cin>>a[i];
		ll ans=0;
		for(int i=0;i<n-1;++i){
			ans=max(ans,(ll)a[i]*a[i+1]);
		}
		cout<<ans<<endl;
	}
	return 0;
}