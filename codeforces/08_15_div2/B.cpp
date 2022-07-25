#include <iostream>
using namespace std;
int t,n;
int main() {
	ios::sync_with_stdio(false);
	cin>>t;
	while (t--) {
		cin>>n;
		string in;
		cin>>in;
		int fir=0;
		int fc;
		for(int i=0;i<n;++i){
			if(in[i]!='?'){
				fir=i;
				if(in[i]=='B')fc=0;
				else fc=1;
				break;
			}
			if(i==n-1){
				fir=1;
				fc=1;
			}
		}
		if(fir>0){
			char c[2]={'B','R'};
			in[0]=c[fc^(fir%2)];
		}
		for(int i=1;i<n;++i){
			if(in[i]!='?')continue;
			if(in[i-1]=='B'){
				in[i]='R';
			}
			else if(in[i-1]=='R'){
				in[i]='B';
			}
		}
		cout<<in<<endl;
	}
	
	
	return 0;
}