#include <iostream>

using namespace std;
int main() {
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while (t--) {
		int p;
		cin>>p;
		cout<<(p-1)/2<<" "<<(p-1)<<endl;
	}
	
	
	return 0;
}