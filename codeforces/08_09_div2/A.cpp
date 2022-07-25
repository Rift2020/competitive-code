#include <iostream>
#include <algorithm>
#define ll long long
#define maxn 100005
using namespace std;
int t;
int n;
int a[maxn];
int main() {
	ios::sync_with_stdio(false);
	cin>>t;
	while (t--) {
		cin>>n;
		for(int i=0;i<n;++i)cin>>a[i];
		sort(a,a+n);
		double a1=0;
		for(int i=0;i<n-1;++i)a1+=a[i];
		a1=a1/(n-1);
		printf("%.7f\n",a1+a[n-1]);
	}
	
	
	
	
	
	return 0;
}