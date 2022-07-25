#include <iostream>
#define maxn 100005
using namespace std;

int t,n;
int a[maxn];
int main() {
	ios::sync_with_stdio(false);
	cin>>t;
	while (t--) {
		cin>>n;
		int cnt=0,l=0,l2=0,ans;
		for(int i=1;i<=n;++i){
			cin>>a[i];
			if(a[i]%2==1){
				++cnt;
				l+=abs(i-(2*cnt-1));
				l2+=abs(i-(2*cnt));
			}
		}
		if(n%2==0){
			if(cnt==n/2){
				ans=min(l,l2);
			}
			else ans=-1;
		}
		else{
			if(cnt==n/2){
				ans=l2;
			}
			else if(cnt==n/2+1){
				ans=l;
			}
			else{
				ans=-1;
			}
		}
		cout<<ans<<endl;
	}
	
	return 0;
}