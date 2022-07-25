#include <iostream>
int t;
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	int in;
	cin>>t;
	for(int i=0;i<t;++i){
		cin>>in;
		int a,b;
		a=b=in/3;
		if(in%3==1){
			a+=1;
		}else if(in%3==2){
			b+=1;
		}
		cout<<a<<" "<<b<<endl;
	}
	return 0;
}