#include <iostream>

using namespace std;
int t,a,b;
int main() {
	ios::sync_with_stdio(false);
	cin>>t;
	while (t--) {
		cin>>a>>b;
		if(a<b)swap(a,b);
		if(a-b==0){
			if(a==0)cout<<0<<endl;
			else cout<<1<<endl;
		}
		else if((a-b)%2==1){
			cout<<-1<<endl;
		}
		else {
			cout<<2<<endl;
		}
	}
	
	
	return 0;
}