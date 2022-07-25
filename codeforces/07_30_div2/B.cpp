#include <iostream>
#define maxw 999999999
using namespace std;
int t;
int w,h,x1,x2,y1,y2,w2,h2;
int main() {
	ios::sync_with_stdio(false);
	cin>>t;
	for(int o=0;o<t;++o){
		cin>>w>>h>>x1>>y1>>x2>>y2>>w2>>h2;
		if(x2-x1+w2>w&&y2-y1+h2>h){
			cout<<-1<<endl;
			continue;
		}
		int lx,ly;
		if(x2-x1+w2<=w)
			lx=max(x1,w-x2);
		else lx=-maxw;
		if(y2-y1+h2<=h)
			ly=max(y1,h-y2);
		else ly=-maxw;
		int ans=min(w2-lx,h2-ly);
		//cout<<o+1<<':'<<endl;
		//cout<<":"<<lx<<" "<<ly<<endl;
		if(ans<0){
			cout<<0<<endl;
		}
		else{
			cout<<ans<<endl;
		}
	}
	return 0;
}