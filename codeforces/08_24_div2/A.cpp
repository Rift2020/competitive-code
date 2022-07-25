#include <iostream>
#define maxn 1005
using namespace std;

int a[maxn],n,ans,la=-1,t;
bool swp(int x){
	int s=0;
	//for(int i=1;i<=n;++i)cout<<a[i]<<" ";
	//cout<<endl;
	if(x%2==1){
		for(int i=1;i<=n-2;i+=2){
			if(a[i]>a[i+1]){
				swap(a[i],a[i+1]);
				++s;
			}
		}
	}
	else{
		for(int i=2;i<=n-1;i+=2){
			if(a[i]>a[i+1]){
				swap(a[i],a[i+1]);
				++s;
			}
		}
	}
	if(s!=0)ans=x;
	else{
		if(la==0&&s==0){
			cout<<ans<<endl;
			return true;
		}
	}
	la=s;
	return false;
}
int main() {
	ios::sync_with_stdio(false);
	cin>>t;
	while (t--) {
		cin>>n;
		ans=0;
		la=-1;
		for(int i=1;i<=n;++i){
			cin>>a[i];
		}
		for(int i=1;;++i){
			if(swp(i))break;
			
		}
	}
	
	
	
	
	return 0;
}