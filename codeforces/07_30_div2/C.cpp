#include <iostream>
#define maxn 100005
#define ll long long
using namespace std;
int t,m;
int a[3][maxn];
int cf[3][maxn];
int main() {
	ios::sync_with_stdio(false);
	cin>>t;
	for(int o=0;o<t;++o){
		cin>>m;
		for(int i=1;i<=m;++i)cin>>a[1][i];
		for(int i=1;i<=m;++i)cin>>a[2][i];
		if(m==1){
			cout<<0<<endl;
			continue;
		}
		cf[1][1]=a[1][1],cf[2][1]=a[2][1];
		for(int i=2;i<=m;++i){
			cf[1][i]=cf[1][i-1]+a[1][i];
			cf[2][i]=cf[2][i-1]+a[2][i];
		}
		cf[2][0]=0;
		int ans=999999999;
		//for(int i=1;i<=m;++i)cout<<cf[1][i]<<" ";
		//cout<<endl;
		//for(int i=1;i<=m;++i)cout<<cf[2][i]<<" ";
		for(int i=1;i<=m;++i){
			int s=cf[1][m]-cf[1][i];
			int x=cf[2][i-1];
			ans=min(ans,max(s,x));
		}
		cout<<ans<<endl;
	}
}