#include <iostream>
#include <vector>
#include <string.h>
#define maxn 200005
using namespace std;
int a[maxn];
vector<int> v;
int n;
int main() {
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while (t--) {
		cin>>n;
		v.clear();
		memset(a,0,sizeof(a));
		string ein,win;
		cin>>ein>>win;
		for(int i=0;i<n;++i){
			a[i+1]=ein[i]-'0';
			if(win[i]=='1')
				v.push_back(i+1);
		}
		int ans=0;
		for(int i:v){
			//cout<<i<<" ";
			if(a[i-1]==1){
				a[i-1]=2;
				++ans;
			}
			else if(a[i]==0){
				a[i]=2;
				++ans;
			}
			else if(a[i+1]==1){
				a[i+1]=2;
				++ans;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}