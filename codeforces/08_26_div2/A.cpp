#include <iostream>

using namespace std;
int main() {
	ios::sync_with_stdio(false);
	int l,r,t;
	cin>>t;
	while (t--) {
		cin>>l>>r;
		int b=r;
		int a=max(b/2+1,l);
		cout<<b-a<<endl;
	}
	
	return 0;
}