#include <iostream>
using namespace std;
int t,a,b,am,bm;
string in;
bool check(int x){
	x=10-x;
	int al=x/2;
	int bl=(x+1)/2;
	if(am+al<b||bm+bl<a)return true;
	return false;
}
int main() {
	ios::sync_with_stdio(false);
	cin>>t;
	for(int i=0;i<t;++i){
		cin>>in;
		a=0,b=0,am=0,bm=0;
		for(int i=0;i<10;++i){
			if(i%2==0){
				if(in[i]=='?'){
					a++;
				}
				else if(in[i]=='1'){
					a++;
					am++;
				}
			}
			else{
				if(in[i]=='?'){
					b++;
				}
				else if(in[i]=='1'){
					b++;
					bm++;
				}
			}
			if(check(i+1)){
				cout<<i+1<<endl;
				break;
			}
			if(i==9)
				cout<<10<<endl;
		}
	}
	return 0;
}