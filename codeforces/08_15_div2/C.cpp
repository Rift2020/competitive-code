#include <iostream>
#define maxn 10005
using namespace std;
int a[maxn];
int t,n;
int main() {
	ios::sync_with_stdio(false);
	cin>>t;
	while (t--) {
		cin>>n;
		for(int i=1;i<=n;++i){
			int in;
			cin>>in;
			if(in==0)a[i]=0;
			else a[i]=1;
		}
		int ind=-1;
		if(a[1]==1){
			ind=1;
		}
		else if(a[n]==0){
			ind=n+1;
		}
		else{
			for(int i=2;i<=n;++i){
				if(a[i]==1&&a[i-1]==0){
					ind=i;
					break;
				}
			}
		}
		//cout<<":"<<ind<<endl;
		if(ind==-1){
			cout<<-1<<endl;
		}
		else{
			for(int i=1;i<=n;++i){
				if(ind==i)cout<<n+1<<" ";
				cout<<i<<" ";
			}
			if(ind==n+1)cout<<n+1;
			cout<<endl;
		}
	}
	return 0;
}