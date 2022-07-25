#include <iostream>

using namespace std;
int main() {
	ios::sync_with_stdio(false);
	int t,a,b,c;
	cin>>t;
	while (t--) {
		cin>>a>>b>>c;
		if(a>b)swap(a,b);
		int n=(b-a)*2;
		if(a>n||b>n||c>n)cout<<-1<<endl;
		else{
			int d=c+b-a;
			if(d>n)d-=n;
			cout<<d<<endl;
		}
	}
	
	
	return 0;
}