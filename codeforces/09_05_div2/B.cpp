#include <iostream>
#define maxn 300005
using namespace std;
int mem[maxn];
int t,a,b;
int main() {
	ios::sync_with_stdio(false);
	for(int i=1;i<maxn;++i){
		mem[i]=mem[i-1]^i;
	}
	cin>>t;
	while (t--) {
		cin>>a>>b;
		int ans=a;
		if(mem[a-1]==b);
		else if((mem[a-1]^a)==b){
			ans+=2;
		}
		else ans+=1;
		cout<<ans<<endl;
	}
	
	return 0;
}