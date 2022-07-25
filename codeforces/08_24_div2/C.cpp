#include <iostream>
#include <queue>
#include <algorithm>
#define maxn 100005
using namespace std;
struct cav{
	int ent;
	int n;
};
bool operator<(const cav &a,const cav &b){
	return a.ent<b.ent;
}
int t,n,ans,k;
int a[maxn];
cav ar[maxn];
int s[maxn];
int main() {
	ios::sync_with_stdio(false);
	cin>>t;
	while (t--) {
		ans=0;
		cin>>n;
		for(int i=0;i<n;++i){
			cin>>k;
			//cout<<"k"<<k<<endl;
			for(int j=0;j<k;++j)cin>>a[j];
			//sort(a,a+k);
			//for(int j=0;j<k;++j)cout<<a[j]<<" ";
			//cout<<endl;
			int le=a[0]+1;
			for(int j=1;j<k;++j){
				if(le+j>a[j])continue;
				else{
					le=a[j]+1-j;
				}
			}
			ar[i]=(cav){le,k};
		}
		sort(ar,ar+n);
		for(int i=1;i<n;++i)s[i]=s[i-1]+ar[i-1].n;
		//for(int i=0;i<n;++i)cout<<ar[i].ent<<" ";
		//cout<<endl;
		ans=ar[0].ent;
		for(int i=1;i<n;++i){
			if(ans+s[i]>=ar[i].ent)continue;
			ans=ar[i].ent-s[i];
		}
		cout<<ans<<endl;
	}
	
	return 0;
}