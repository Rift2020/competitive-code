#include <iostream>
using namespace std;
int t,a,b;

int main() {
	ios::sync_with_stdio(false);
	cin>>t;
	while (t--) {
		cin>>a>>b;
		if(a>b)swap(a,b);
		int d=b-a;
		if(d%2==0)cout<<a+1<<endl;
		else cout<<2*(a+1)<<endl;
		for(int i=0;i<=2*a;i+=2){
			if(d%2==0)cout<<i+d/2<<" ";
			else cout<<i+d/2<<" "<<i+d/2+1<<" ";
		}
		cout<<endl;
	}
	
	
	return 0;
}