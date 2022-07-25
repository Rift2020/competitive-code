#include <iostream>
#define ll long long
using namespace std;
int t;
ll in,ans;
int a[]={0,15,20,25};
int main() {
	ios::sync_with_stdio(false);
	cin>>t;
	for(int o=0;o<t;++o){
		cin>>in;
		ans=0;
		ll mod=in%60;
		in-=mod;
		while (in>=10&&mod<=50) {
			mod+=10;
			in-=10;
		}
		ans+=(in/10)*a[3];
		//cout<<"in"<<in<<" "<<mod<<endl;
		ll add=9999999;
		for(int i=0;i<=10;++i){
			for(int j=0;j<=7;++j){
				for(int k=0;k<=6;++k){
					if(i*6+j*8+k*10>=mod){
						add=min(add,(ll)i*a[1]+j*a[2]+k*a[3]);
					}
				}
			}
		}
		cout<<ans+add<<endl;;
	}
	
	
	return 0;
}