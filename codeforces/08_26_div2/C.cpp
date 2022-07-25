#include <iostream>
using namespace std;
int t,n;
string s;
int main() {
	ios::sync_with_stdio(false);
	cin>>t;
	while (t--) {
		cin>>n;
		cin>>s;
		int si=-1;
		for(int i=0;i<s.size();++i){
			if(s[i]=='0'){
				si=i+1;
				break;
			}
		}
		if(si!=-1){
			if(si<=n/2){
				cout<<si+1<<" "<<n<<" "<<si<<" "<<n<<endl;
			}
			else{
				cout<<1<<" "<<si<<" "<<1<<" "<<si-1<<endl;
			}
		}
		else{
			cout<<1<<" "<<n/2<<" "<<2<<" "<<n/2+1<<endl;
		}
	}
	return 0;
}