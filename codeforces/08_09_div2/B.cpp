#include <iostream>
#include <algorithm>
#include <unordered_map>
#define maxn 100005
using namespace std;
int t,n,k;
int a[maxn];
int sa[maxn];
unordered_map<int,int> um;
int main() {
	ios::sync_with_stdio(false);
	cin>>t;
	while (t--) {
		cin>>n>>k;
		for(int i=0;i<n;++i){
			cin>>a[i];
			sa[i]=a[i];
		}
		um.clear();
		sort(sa,sa+n);
		for(int i=0;i<n;++i){
			um[sa[i]]=i;
		}
		int need=1;
		for(int i=1;i<n;++i){
			int la=a[i-1],now=a[i];
			if(sa[um[la]+1]==now&&um[la]!=n-1)continue;
			++need;
		}
		//cout<<need<<endl;
		if(need<=k)cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	
	
	
	
	return 0;
}