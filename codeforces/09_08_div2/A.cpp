#include <bits/stdc++.h>
#define maxn 55
using namespace std;
int t,n;
char in[maxn];
int a[maxn],b[maxn];
int main() {
	ios::sync_with_stdio(false);
	cin>>t;
	while (t--) {
		cin>>n;
		for(int i=1;i<=n;++i)cin>>in[i];
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		for(int i=1;i<=n;++i){
			a[i]=a[i-1];
			b[i]=b[i-1];
			if(in[i]=='a')a[i]++;
			else if(in[i]=='b')b[i]++;
		}
		
		//for(int i=0;i<=n;++i)cout<<a[i]<<" ";
		//cout<<endl;
		//for(int i=0;i<=n;++i)cout<<b[i]<<" ";
		//cout<<endl;
		bool fl=false;
		for(int i=1;i<=n;++i){
			for(int j=i+1;j<=n;++j){
				int aa=a[j]-a[i-1],bb=b[j]-b[i-1];
				if(aa==bb){
					cout<<i<<" "<<j<<endl;
					fl=true;
					break;
				}
			}
			if(fl)break;
		}
		if(fl==false)cout<<-1<<" "<<-1<<endl;
	}
	
	
	return 0;
}