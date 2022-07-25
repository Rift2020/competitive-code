#include <iostream>
#include <cmath>
using namespace std;
int n,x,y,fx,fy,a,b;
int main() {
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=0;i<n;++i){
		cin>>x>>y>>fx>>fy>>a>>b;
		int ans=0;
		if(x==fx&&x==a&&(b>y&&b<fy||b>fy&&b<y))ans+=2;
		if(y==fy&&y==b&&(a>x&&a<fx||a>fx&&a<x))ans+=2;
		ans+=abs(x-fx)+abs(y-fy);
		cout<<ans<<endl;
	}
	return 0;
}