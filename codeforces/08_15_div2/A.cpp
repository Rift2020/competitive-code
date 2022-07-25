#include <iostream>
#define  maxn 105
using namespace std;
int a[maxn];
int t,n;
int main() {
	ios::sync_with_stdio(false);
	cin>>t;
	while (t--) {
		cin>>n;
		for(int i=0;i<n;++i)cin>>a[i];
		int ans=a[0];
		for(int i=1;i<n;++i){
			ans=ans&a[i];
		}
		cout<<ans<<endl;
	}
	return 0;
}