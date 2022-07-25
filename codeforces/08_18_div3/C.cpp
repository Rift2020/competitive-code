#include <iostream>
#include <cmath>
#define  int long long
using namespace std;
signed main() {
	ios::sync_with_stdio(false);
	int t,k;
	cin>>t;
	while (t--) {
		cin>>k;
		int n=(int)(sqrt(k-1)+1);
		int le=(n-1)*(n-1)+1;
		int ri=n*n;
		int r,c;
		int mid=(le+ri)/2;
		if(k<mid){
			c=n;
			r=1+k-le;
		}
		else{
			r=n;
			c=n-k+mid;
		}
		cout<<r<<" "<<c<<endl;
	}
	
	
	return  0;
}