#include <iostream>
int t;
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	int in,ans;
	cin>>t;
	for(int i=0;i<t;++i){
		cin>>in;
		ans=0;
		if(in%10==9)++ans;
		ans+=in/10;
		cout<<ans<<endl;
	}
	return 0;
}